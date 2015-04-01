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
////////////////////////////////////////////////////////////////////////////////
const long DEFAULT_RS232_RATE = 19200L;

const char *APP_PROMPT = "STP08DP05 demo";

const int ledDelay = 500; //ms

const int pinOE = 9;
const int pinSDO = 10;
const int pinLE = 11;
const int pinCLK = 12;
const int pinSDI = 13;
STP08DP05 drv1 = STP08DP05(pinOE, pinLE, pinCLK, pinSDI, pinSDO);
////////////////////////////////////////////////////////////////////////////////
void setup() {
  Serial.begin(DEFAULT_RS232_RATE);
  Serial.println(APP_PROMPT);

  drv1.enableOut();
}
////////////////////////////////////////////////////////////////////////////////
void quicktest() {
  drv1.setOut(0x80);
  delay(ledDelay);
  drv1.setOut(0x40);
  delay(ledDelay);
  drv1.setOut(0x20);
  delay(ledDelay);
  drv1.setOut(0x10);
  delay(ledDelay);
  drv1.setOut(0x08);
  delay(ledDelay);
  drv1.setOut(0x04);
  delay(ledDelay);
  drv1.setOut(0x02);
  delay(ledDelay);
  drv1.setOut(0x01);
  delay(ledDelay);
  drv1.setOut(0x00);
  delay(ledDelay);

  drv1.setOut(0xFF);
  delay(ledDelay);
  drv1.setOut(0x00);
  delay(ledDelay);

  drv1.setOut(0x55);
  delay(ledDelay);
  drv1.setOut(0xAA);
  delay(ledDelay);
  drv1.setOut(0x00);
  delay(ledDelay);
}
////////////////////////////////////////////////////////////////////////////////
void loop() {
  Serial.println("start LEDs");
  quicktest();
  Serial.println("stop LEDs");
  delay(8*ledDelay);

  Serial.println("start error detection");
  drv1.chkOut();
  Serial.println("end error detection");
  delay(8*ledDelay);
}
////////////////////////////////////////////////////////////////////////////////