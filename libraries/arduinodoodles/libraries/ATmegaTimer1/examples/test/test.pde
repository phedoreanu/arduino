/*
This file is part of ATmegaTimer1.

ATmegaTimer1 is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

ATmegaTimer1 is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with ATmegaTimer1.  If not, see <http://www.gnu.org/licenses/>.
*/
////////////////////////////////////////////////////////////////////////////////
#include "ATmegaTimer1.h"
////////////////////////////////////////////////////////////////////////////////
const int pinLED = 13;

const long DEFAULT_RS232_RATE = 19200L;

const char *APP_PROMPT = "ATmegaTimer1 demo";

const int TIMER_TOP = 124;
const int TIMER_CNT = 5;

volatile int timer2_ovfCnt = 0;
volatile int stLed = 0;
////////////////////////////////////////////////////////////////////////////////
void printTimer2Regs() {
  Serial.println("==========");
  Serial.print("TCCR1A: ");
  Serial.println(TCCR1A, HEX);
  Serial.print("TCCR1B: ");
  Serial.println(TCCR1B, HEX);
  Serial.print("OCR1A:  ");
  Serial.println(OCR1A, HEX);
  Serial.print("OCR1B:  ");
  Serial.println(OCR1B, HEX);
  Serial.print("TIMSK1: ");
  Serial.println(TIMSK1, HEX);
}
////////////////////////////////////////////////////////////////////////////////
void printTimer2Value() {
  Serial.print("TCNT1:  ");
  Serial.println(TCNT1, HEX);
}
////////////////////////////////////////////////////////////////////////////////
void setup() {
  pinMode(pinLED, OUTPUT);

  Serial.begin(19200);
  Serial.println(APP_PROMPT);

  ATmegaTimer1.setControlRegs(0x00, 0x00, 0x04, 0x00, 0x00, 0x00); //CTC mode
  ATmegaTimer1.setOutCompare(TIMER_TOP, 0x00);
  ATmegaTimer1.setIntMask(0, 1, 0, 0); //OCIE1A enabled
  ATmegaTimer1.setValue(0);
  ATmegaTimer1.setClkSelect(0x05);

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
ISR(TIMER1_COMPA_vect) {
  timer2_ovfCnt ++;
  if(timer2_ovfCnt == TIMER_CNT) {
    stLed ++;
    timer2_ovfCnt = 0;
  }
}
////////////////////////////////////////////////////////////////////////////////