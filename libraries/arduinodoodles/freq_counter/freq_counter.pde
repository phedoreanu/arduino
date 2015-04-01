/*
This file is part of freq_counter.

freq_counter is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

freq_counter is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with freq_counter.  If not, see <http://www.gnu.org/licenses/>.
*/
////////////////////////////////////////////////////////////////////////////////
#include "ATmegaTimer2.h"
////////////////////////////////////////////////////////////////////////////////
const int pinLED = 13;
const int pinINT0 = 2;
const int pinINT1 = 3;

const long DEFAULT_RS232_RATE = 19200L;

const char *APP_PROMPT = "2 ch. frequency counter";

const int TIMER_TOP = 124;
const int TIMER_CNT = 125;

int ledState = LOW;
volatile int timer2_ovfCnt = 0;
volatile boolean showResult = false;
volatile long int int0_cnt = 0L;
volatile long int int1_cnt = 0L;
volatile long int int0_totalCnt = 0L;
volatile long int int1_totalCnt = 0L;
////////////////////////////////////////////////////////////////////////////////
void ISR_INT0() {
  int0_cnt ++;
}
////////////////////////////////////////////////////////////////////////////////
void ISR_INT1() {
  int1_cnt ++;
}
////////////////////////////////////////////////////////////////////////////////
inline void enableExternalINT() {
  EIMSK |= (_BV(INT1) | _BV(INT0));
}
////////////////////////////////////////////////////////////////////////////////
inline void disableExternalINT() {
  EIMSK &= ~(_BV(INT1) | _BV(INT0));
}
////////////////////////////////////////////////////////////////////////////////
void startMeasure() {
  digitalWrite(pinLED, HIGH);

  showResult = false;
  ATmegaTimer2.setValue(0x00);
  int0_cnt = 0L;
  int1_cnt = 0L;
  ATmegaTimer2.setClkSelect(0x07);
  enableExternalINT();
}
////////////////////////////////////////////////////////////////////////////////
void setup() {
  pinMode(pinLED, OUTPUT);

  Serial.begin(19200);
  Serial.println(APP_PROMPT);

  ATmegaTimer2.setControlRegs(0x00, 0x00, 0x02, 0x00); //CTC mode
  ATmegaTimer2.setOutCompare(TIMER_TOP, 0x00);
  ATmegaTimer2.setIntMask(0x01, 0x00, 0x00); //OCIE2A enabled
  //printTimer2Regs();

  attachInterrupt(0, ISR_INT0, RISING);
  attachInterrupt(1, ISR_INT1, RISING);
  //printIntInfo();

  disableExternalINT();
  startMeasure();
}
////////////////////////////////////////////////////////////////////////////////
void printTimer2Regs() {
  Serial.print("TCCR2A:");
  Serial.println(TCCR2A, HEX);
  Serial.print("TCCR2B:");
  Serial.println(TCCR2B, HEX);
  Serial.print("OCR2A:");
  Serial.println(OCR2A, HEX);
  Serial.print("OCR2B:");
  Serial.println(OCR2B, HEX);
  Serial.print("TIMSK2:");
  Serial.println(TIMSK2, HEX);
  Serial.println("====");
}
////////////////////////////////////////////////////////////////////////////////
void printTimer2Value() {
  Serial.print("TCNT2:");
  Serial.println(TCNT2, HEX);
}
////////////////////////////////////////////////////////////////////////////////
void printIntInfo() {
  Serial.print("EICRA:");
  Serial.println(EICRA, HEX);
  Serial.print("EIMSK:");
  Serial.println(EIMSK, HEX);
}
////////////////////////////////////////////////////////////////////////////////
void loop() {
  if(showResult) {
    digitalWrite(pinLED, LOW);

    Serial.print("freq (Hz),");
    Serial.print(int0_totalCnt, DEC);
    Serial.print(",");
    Serial.print(int1_totalCnt, DEC);
    Serial.println();

    startMeasure();
  }
}
////////////////////////////////////////////////////////////////////////////////
ISR(TIMER2_COMPA_vect) {
  timer2_ovfCnt ++;
  if(timer2_ovfCnt == TIMER_CNT) {
    ATmegaTimer2.stopTimer();
    disableExternalINT();
    int0_totalCnt = int0_cnt;
    int1_totalCnt = int1_cnt;
    timer2_ovfCnt = 0;
    showResult = true;
  }
}
////////////////////////////////////////////////////////////////////////////////