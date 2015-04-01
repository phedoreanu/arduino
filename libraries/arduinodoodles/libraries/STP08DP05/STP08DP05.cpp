/*
This file is part of STP08DP05.

STP08DP05 is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

STP08DP05 is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with STP08DP05.  If not, see <http://www.gnu.org/licenses/>.
*/
////////////////////////////////////////////////////////////////////////////////
#include "STP08DP05.h"

STP08DP05::STP08DP05(int16_t pOE, int16_t pLE, int16_t pCLK, int16_t pSDI, int16_t pSDO) {
  pinOE = pOE;
  pinLE = pLE;
  pinCLK = pCLK;
  pinSDI = pSDI;
  pinSDO = pSDO;

  pinMode(pinOE, OUTPUT);
  pinMode(pinLE, OUTPUT);
  pinMode(pinCLK, OUTPUT);
  pinMode(pinSDI, OUTPUT);
  pinMode(pinSDO, INPUT);

  digitalWrite(pinOE, HIGH); //outputs disabled
  digitalWrite(pinLE, LOW);
  digitalWrite(pinCLK, LOW);
  digitalWrite(pinSDI, LOW);
}
////////////////////////////////////////////////////////////////////////////////
void STP08DP05::enableOut() {
  digitalWrite(pinOE, LOW);
}
////////////////////////////////////////////////////////////////////////////////
void STP08DP05::disableOut() {
  digitalWrite(pinOE, HIGH);
}
////////////////////////////////////////////////////////////////////////////////
/**
  send MSb(it) on pinSDI and reads the bit on pinSDO

  @param sdi
  @see pinSDI
*/
char STP08DP05::transferBit(char sdi) {
  char sdo = 0x00;

  //assumes pinCLK is low
  if(digitalRead(pinSDO) == HIGH) {
    sdo = 0x01;
  }
  else {
    sdo = 0x00;
  }
  if(sdi & 0x80) {
    digitalWrite(pinSDI, HIGH);
  }
  else {
    digitalWrite(pinSDI, LOW);
  }
  digitalWrite(pinCLK, HIGH);
  digitalWrite(pinCLK, LOW);
  return sdo;
}
////////////////////////////////////////////////////////////////////////////////
char STP08DP05::setOut(uint8_t data) {
  char res = 0x00;

  //Serial.print("sending ... ");
  //Serial.println(data, HEX);
  disableOut();
  digitalWrite(pinLE, HIGH); //start data shift-in
  for(int i = 0; i < 8; i++) {
    res =  res << 1;
    res = res | transferBit(data);
    data = data << 1;
  }
  //Serial.print("received ... ");
  //Serial.println(res, HEX);
  digitalWrite(pinLE, LOW);
  enableOut();
  return res;
}
////////////////////////////////////////////////////////////////////////////////
void STP08DP05::startDetectMode() {
  //Serial.println("start detect mode");
  //assumes pinCLK is low
  digitalWrite(pinOE, HIGH);
  digitalWrite(pinLE, LOW);
  digitalWrite(pinCLK, HIGH);
  digitalWrite(pinCLK, LOW);

  digitalWrite(pinOE, LOW);
  digitalWrite(pinLE, LOW);
  digitalWrite(pinCLK, HIGH);
  digitalWrite(pinCLK, LOW);

  digitalWrite(pinOE, HIGH);
  digitalWrite(pinLE, LOW);
  digitalWrite(pinCLK, HIGH);
  digitalWrite(pinCLK, LOW);

  digitalWrite(pinOE, HIGH);
  digitalWrite(pinLE, HIGH);
  digitalWrite(pinCLK, HIGH);
  digitalWrite(pinCLK, LOW);

  digitalWrite(pinOE, HIGH);
  digitalWrite(pinLE, LOW);
  digitalWrite(pinCLK, HIGH);
  digitalWrite(pinCLK, LOW);
}
////////////////////////////////////////////////////////////////////////////////
void STP08DP05::endDetectMode() {
  //Serial.println("end detect mode");
  //assumes pinCLK is low
  digitalWrite(pinOE, HIGH);
  digitalWrite(pinLE, LOW);
  digitalWrite(pinCLK, HIGH);
  digitalWrite(pinCLK, LOW);

  digitalWrite(pinOE, LOW);
  digitalWrite(pinLE, LOW);
  digitalWrite(pinCLK, HIGH);
  digitalWrite(pinCLK, LOW);

  digitalWrite(pinOE, HIGH);
  digitalWrite(pinLE, LOW);
  digitalWrite(pinCLK, HIGH);
  digitalWrite(pinCLK, LOW);

  digitalWrite(pinOE, HIGH);
  digitalWrite(pinLE, LOW);
  digitalWrite(pinCLK, HIGH);
  digitalWrite(pinCLK, LOW);

  digitalWrite(pinOE, HIGH);
  digitalWrite(pinLE, LOW);
  digitalWrite(pinCLK, HIGH);
  digitalWrite(pinCLK, LOW);
}
////////////////////////////////////////////////////////////////////////////////
// doesn't seem to work properly when tested - no error even when an LED is shorted
char STP08DP05::chkOut() {
  char data = 0x00;

  startDetectMode();
  setOut(0x7F);

  enableOut();
  delayMicroseconds(100);
  disableOut();

  data = setOut(0x00);

  endDetectMode();

  enableOut();
  Serial.println(data, HEX);
  return data;
}
////////////////////////////////////////////////////////////////////////////////