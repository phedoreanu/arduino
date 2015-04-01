/*
This file is part of DHT11.

DHT11 is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

DHT11 is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with DHT11.  If not, see <http://www.gnu.org/licenses/>.
*/
////////////////////////////////////////////////////////////////////////////////
#include "DHT11.h"
////////////////////////////////////////////////////////////////////////////////
void DHT11Class::setPin(int pOW) {
  pin = pOW;
  owState = DHT11_STATE_IDLE;

  pinMode(pin, INPUT);
}
////////////////////////////////////////////////////////////////////////////////
int DHT11Class::read() {
  //char rawData[DHT11_SAMPLES];
  //for(int i = 0; i < DHT11_SAMPLES; i++)
  //  rawData[i] = 0xA;

  char bitData[DHT11_NBITS];
  int bitCnt = 0;

  for(int i = 0; i < DHT11_NBITS; i++)
    bitData[i] = 0;

  char sensorData[DHT11_NBITS/8];
  for(int i = 0; i < (DHT11_NBITS/8); i++)
    sensorData[i] = 0;

  owState = DHT11_STATE_IDLE;
  int wireVal[2] = {HIGH, HIGH};
  unsigned long negTS = 0;
  unsigned long posTS = 0;
  //unsigned long dbgTS[3] = {0, 0, 0};
  //bool bDbgStop = false;

  /** start read cycle - pull wire low for > 18 us */
  pinMode(pin, OUTPUT);
  //digitalWrite(pin, LOW);
  delay(20);
  //digitalWrite(pin, HIGH);
  pinMode(pin, INPUT);

  /** sensor starts replying */
  //noInterrupts();
  for(int i = 0; i < DHT11_SAMPLES; i++) {
    wireVal[1] = wireVal[0];
    wireVal[0] = digitalRead(pin);
    //rawData[i] = wireVal[0];
    if((wireVal[0] == HIGH) && (wireVal[1] == LOW)) {
      posTS = micros();
      //dbgTS[2] = dbgTS[1];
      //dbgTS[1] = dbgTS[0];
      //dbgTS[0] = posTS;
    }
    else if((wireVal[0] == LOW) && (wireVal[1] == HIGH)) {
      negTS = micros();
      //dbgTS[2] = dbgTS[1];
      //dbgTS[1] = dbgTS[0];
      //dbgTS[0] = negTS;
    }
    else
      continue;

    switch(owState) {
      case DHT11_STATE_IDLE: {
        if(negTS > 0) {
          //bDbgStop = true;
          owState = DHT11_START_ZERO;
        }
        break;
      }
      case DHT11_START_ZERO: {
        if(posTS > 0) {
          if((posTS > negTS) && ((posTS - negTS) > 70)) {
            //bDbgStop = true;
            owState = DHT11_START_ONE;
            negTS = 0;
          }
          else {
            owState = DHT11_ERR1;
          }
        }
        break;
      }
      case DHT11_START_ONE: {
        if(negTS > 0) {
          if((negTS > posTS) && ((negTS - posTS) > 70)) {
            //bDbgStop = true;
            owState = DHT11_START_BIT;
            posTS = 0;
          }
          else {
            owState = DHT11_ERR1;
          }
        }
        break;
      }
      case DHT11_START_BIT: {
        if(posTS > 0) {
          //if(bitCnt == 12) {
          //  bDbgStop = true;
          //  break;
          //}
          if((posTS > negTS) && ((posTS - negTS) > 45)) {
            //bDbgStop = true;
            owState = DHT11_END_BIT;
            negTS = 0;
          }
          else {
            owState = DHT11_ERR2;
          }
        }
        break;
      }
      case DHT11_END_BIT: {
        if(negTS > 0) {
          //if(bitCnt == 11) {
          //  bDbgStop = true;
          //  break;
          //}
          if(negTS > posTS) {
            if((negTS - posTS) > 32) {
              bitData[bitCnt] = 1;
            }
            //bDbgStop = true;
            owState = DHT11_START_BIT;
            posTS = 0;
            bitCnt ++;
          }
          else {
            owState = DHT11_ERR3;
          }
        }
        break;
      }
      default: {
        //bDbgStop = true;
        break;
      }
    }

    //if(bDbgStop)
    //  break;
  }
  //interrupts();

  //Serial.println("raw:");
  //for(int i = 0; i < DLEN; i++) {
  //  Serial.print(rawData[i], HEX);
  //}
  //Serial.println();

  //Serial.println("bits:");
  for(int i = 0; i < 40; i++) {
    //Serial.print(bitData[i], HEX);
    sensorData[i/8] += (bitData[i] << (7 - (i%8)));
  }
  //Serial.println();

  char sensorCRC = 0;
  //Serial.println("byte:");
  for(int i = 0; i < 4; i++) {
    //Serial.print(sensorData[i], HEX);
    //Serial.print("|");
    sensorCRC += sensorData[i];
  }
  //Serial.println();

  //Serial.println("check:");
  //Serial.println(owState, DEC);
  //Serial.println(bitCnt, DEC);
  //Serial.println(posTS, DEC);
  //Serial.println(negTS, DEC);
  //Serial.println(dbgTS[2], DEC);
  //Serial.println(dbgTS[1], DEC);
  //Serial.println(dbgTS[0], DEC);
  //Serial.println(sensorCRC, HEX);
  //Serial.println(sensorData[4], HEX);

  if(owState != DHT11_END_BIT)
    return (1000 + owState);

  if(bitCnt != 40)
    return 2000;

  if(sensorCRC != sensorData[4])
    return 3000;

  rh = sensorData[0];
  temp = sensorData[2];
  return 0;
}
////////////////////////////////////////////////////////////////////////////////
DHT11Class DHT11;