/*
This file is part of ATmegaTimer2.

ATmegaTimer2 is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

ATmegaTimer2 is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with ATmegaTimer2.  If not, see <http://www.gnu.org/licenses/>.
*/
////////////////////////////////////////////////////////////////////////////////
#include "ATmegaTimer2.h"
////////////////////////////////////////////////////////////////////////////////
const int pinLED = 13;

const long DEFAULT_RS232_RATE = 19200L;

const char *APP_PROMPT = "ATmegaTimer2 demo";

const int TIMER_TOP = 124;
const int TIMER_CNT = 5;

volatile int timer2_ovfCnt = 0;
volatile int stLed = 0;
////////////////////////////////////////////////////////////////////////////////
void printTimer2Regs() {
  Serial.println("==========");
  Serial.print("TCCR2A: ");
  Serial.println(TCCR2A, HEX);
  Serial.print("TCCR2B: ");
  Serial.println(TCCR2B, HEX);
  Serial.print("OCR2A:  ");
  Serial.println(OCR2A, HEX);
  Serial.print("OCR2B:  ");
  Serial.println(OCR2B, HEX);
  Serial.print("TIMSK2: ");
  Serial.println(TIMSK2, HEX);
}
////////////////////////////////////////////////////////////////////////////////
void printTimer2Value() {
  Serial.print("TCNT2:  ");
  Serial.println(TCNT2, HEX);
}
////////////////////////////////////////////////////////////////////////////////
void setup() {
  pinMode(pinLED, OUTPUT);

  Serial.begin(19200);
  Serial.println(APP_PROMPT);

  ATmegaTimer2.setControlRegs(0x00, 0x00, 0x02, 0x00); //CTC mode
  ATmegaTimer2.setOutCompare(TIMER_TOP, 0x00);
  ATmegaTimer2.setIntMask(1, 0, 0); //OCIE2A enabled
  ATmegaTimer2.setValue(0);
  ATmegaTimer2.setClkSelect(0x07);

  printTimer2Regs();
  printTimer2Value();
}
////////////////////////////////////////////////////////////////////////////////
void loop() {
  if(stLed % 2) {
    digitalWrite(pinLED, LOW);
  }
  else {
    digitalWrite(pinLED, HIGH);
  }
}
////////////////////////////////////////////////////////////////////////////////
ISR(TIMER2_COMPA_vect) {
  timer2_ovfCnt ++;
  if(timer2_ovfCnt == TIMER_CNT) {
    stLed ++;
    timer2_ovfCnt = 0;
  }
}
////////////////////////////////////////////////////////////////////////////////