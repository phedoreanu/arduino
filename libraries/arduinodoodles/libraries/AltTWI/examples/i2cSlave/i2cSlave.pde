/*
This file is part of AltTWI.

AltTWI is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

AltTWI is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with AltTWI.  If not, see <http://www.gnu.org/licenses/>.
*/
////////////////////////////////////////////////////////////////////////////////
#include "AltTWI.h"

const long DEFAULT_RS232_RATE = 19200L;

uint8_t txd[3] = {0xBE, 0xEF, 0x00};
////////////////////////////////////////////////////////////////////////////////
void setup() {
  char i2cAddr = 0xA2;

  Serial.begin(DEFAULT_RS232_RATE);
  Serial.println("AltTWI - slave mode");

  AltTWI.init(100, i2cAddr);
  //AltTWI.printAllRegs();
}
////////////////////////////////////////////////////////////////////////////////
void loop() {
  Serial.print("set message for Master ... ");
  Serial.println(txd[2], DEC);
  AltTWI.sendToMaster(txd, 3, 0);
  //AltTWI.printTWIStatus();
  txd[2] ++;
  delay(2000);
}
////////////////////////////////////////////////////////////////////////////////