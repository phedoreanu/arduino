/*
This file is part of i2cScan.

i2cScan is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

i2cScan is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with i2cScan.  If not, see <http://www.gnu.org/licenses/>.
*/
////////////////////////////////////////////////////////////////////////////////
#include "AltTWI.h"
////////////////////////////////////////////////////////////////////////////////
const int pinLED = 13;

const long DEFAULT_RS232_RATE = 19200L;

const char *APP_NAME = "i2cScan";
const char *APP_VER = "1.0";

char twiACK = 0;
////////////////////////////////////////////////////////////////////////////////
void twiTXcback(uint8_t twiStatus) {
  //Serial.print("twiStatus: ");
  //Serial.println(twiStatus, HEX);
  twiACK = 0;
  if(twiStatus == 0x18) {
    twiACK = 1;
  }
}
////////////////////////////////////////////////////////////////////////////////
void scan() {
  int replies = 0;

  Serial.println();
  Serial.println(APP_NAME);
  Serial.println("scan all I2C addresses");

  digitalWrite(pinLED, HIGH);
  for(char slaveAddr = 0x10; slaveAddr < 0xF0; slaveAddr+=2) {
  //for(char slaveAddr = 0x90; slaveAddr < 0xA0; slaveAddr+=2) {
    //Serial.print("try address ");
    //Serial.println(slaveAddr, HEX);

    AltTWI.sendToSlave(slaveAddr, NULL, 0, 0);

    if(twiACK == 1) {
      Serial.print("ACK from address ");
      Serial.println(slaveAddr, HEX);
      replies ++;
    }
  }
  digitalWrite(pinLED, LOW);

  if(replies == 0) {
    Serial.println("nothing on I2C bus");
  }
}
////////////////////////////////////////////////////////////////////////////////
void setup() {
  pinMode(pinLED, OUTPUT);
  Serial.begin(DEFAULT_RS232_RATE);

  AltTWI.init(100);
  AltTWI.setTXCallback(twiTXcback);
}
////////////////////////////////////////////////////////////////////////////////
void loop() {
  scan();
  delay(4000);
}
////////////////////////////////////////////////////////////////////////////////