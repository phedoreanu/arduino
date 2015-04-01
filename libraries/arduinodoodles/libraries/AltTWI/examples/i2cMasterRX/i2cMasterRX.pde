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

////////////////////////////////////////////////////////////////////////////////
void setup() {
  Serial.begin(DEFAULT_RS232_RATE);
  Serial.println("AltTWI - master mode");

  AltTWI.init(100);
  //AltTWI.printAllRegs();
}
////////////////////////////////////////////////////////////////////////////////
void loop() {
  char slaveAddr = 0x6E;

  //AltTWI.printTWIStatus();
  Serial.println("ask for data ...");
  AltTWI.getFromSlave(slaveAddr, 2 , 0);
  delay(8000);
}
////////////////////////////////////////////////////////////////////////////////