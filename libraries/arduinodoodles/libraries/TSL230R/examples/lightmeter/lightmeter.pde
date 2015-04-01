/*
This file is part of lightmeter.

lightmeter is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

lightmeter is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with lightmeter.  If not, see <http://www.gnu.org/licenses/>.
*/
////////////////////////////////////////////////////////////////////////////////
#include "TSL230R.h"
#include "QuickCLI.h"
#include "ATmegaTimer2.h"
////////////////////////////////////////////////////////////////////////////////
const int pinLED = 13;
const int pinINT0 = 2;
const int pinINT1 = 3;
const int pinS0 = 10;
const int pinS1 = 12;
const int pinS2 = 5;
const int pinS3 = 4;

const long DEFAULT_RS232_RATE = 19200L;

const char *APP_VER = "1.0";
const char *APP_PROMPT = "lightmeter";

const int TIMER_TOP = 124;
const int TIMER_CNT = 125;

TSL230R ic = TSL230R(1, pinS0, pinS1, pinS2, pinS3);

volatile int timer2_ovfCnt = 0;
volatile boolean showResult = false;
volatile long int int1_cnt = 0L;
volatile long int int1_totalCnt = 0L;
////////////////////////////////////////////////////////////////////////////////
void setFreqScaling(char *arg);
void setSensitivity(char *arg);
void measure(char *arg);

const uint8_t nMethods = 3;
QuickCLIMethod cliMethods[nMethods] = {
  {(char *)"freq",   (char *)"[1|2|10|100]", setFreqScaling},
  {(char *)"sensty", (char *)"[0|1|10|100]", setSensitivity},
  {(char *)"m",      (char *)"measure",      measure}
};
////////////////////////////////////////////////////////////////////////////////
void ISR_INT1() {
  int1_cnt ++;
}
////////////////////////////////////////////////////////////////////////////////
inline void enableExternalINT() {
  //EIMSK |= (_BV(INT1) | _BV(INT0));
  EIMSK |= _BV(INT1);
}
////////////////////////////////////////////////////////////////////////////////
inline void disableExternalINT() {
  //EIMSK &= ~(_BV(INT1) | _BV(INT0));
  EIMSK &= ~_BV(INT1);
}
////////////////////////////////////////////////////////////////////////////////
void setup() {
  ic.enableOut();

  ATmegaTimer2.setControlRegs(0x00, 0x00, 0x02, 0x00); //CTC mode
  ATmegaTimer2.setOutCompare(TIMER_TOP, 0x00);
  ATmegaTimer2.setIntMask(0x01, 0x00, 0x00); //OCIE2A enabled

  attachInterrupt(1, ISR_INT1, RISING);
  disableExternalINT();

  Serial.begin(DEFAULT_RS232_RATE);
  QuickCLI.init((char *)APP_PROMPT);
  QuickCLI.setMethods(cliMethods, nMethods);
}
////////////////////////////////////////////////////////////////////////////////
void setFreqScaling(char *arg) {
  String strArg = arg;
  int idx1, idx2;

  strArg = strArg.trim();
  idx1 = strArg.indexOf(" ");
  if(idx1 != -1) {
    idx2 = strArg.indexOf(" ", (idx1+1));
    if(idx2 != -1)
      strArg = strArg.substring((idx1+1), idx2);
    else
      strArg = strArg.substring(idx1+1);
  }

  if(strArg.equals("1")) {
    ic.setFreqScaling(TSL230R_SCALE_1);
    Serial.print("freq scaling: ");
    Serial.println(ic.getFreqScaling(), DEC);
  }
  else if(strArg.equals("2")) {
    ic.setFreqScaling(TSL230R_SCALE_2);
    Serial.print("freq scaling: ");
    Serial.println(ic.getFreqScaling(), DEC);
  }
  else if(strArg.equals("10")) {
    ic.setFreqScaling(TSL230R_SCALE_10);
    Serial.print("freq scaling: ");
    Serial.println(ic.getFreqScaling(), DEC);
  }
  else if(strArg.equals("100")) {
    ic.setFreqScaling(TSL230R_SCALE_100);
    Serial.print("freq scaling: ");
    Serial.println(ic.getFreqScaling(), DEC);
  }
  else {
    Serial.print("current freq scaling: ");
    Serial.println(ic.getFreqScaling(), DEC);
  }
}
////////////////////////////////////////////////////////////////////////////////
void setSensitivity(char *arg) {
  String strArg = arg;
  int idx1, idx2;

  strArg = strArg.trim();
  idx1 = strArg.indexOf(" ");
  if(idx1 != -1) {
    idx2 = strArg.indexOf(" ", (idx1+1));
    if(idx2 != -1)
      strArg = strArg.substring((idx1+1), idx2);
    else
      strArg = strArg.substring(idx1+1);
  }

  if(strArg.equals("0")) {
    ic.setSensitivity(TSL230R_PWR_DOWN);
    Serial.println("powering down");
  }
  else if(strArg.equals("1")) {
    ic.setSensitivity(TSL230R_SENS_1x);
    Serial.print("sensitivity: ");
    Serial.println(ic.getSensitivity(), DEC);
  }
  else if(strArg.equals("10")) {
    ic.setSensitivity(TSL230R_SENS_10x);
    Serial.print("sensitivity: ");
    Serial.println(ic.getSensitivity(), DEC);
  }
  else if(strArg.equals("100")) {
    ic.setSensitivity(TSL230R_SENS_100x);
    Serial.print("sensitivity: ");
    Serial.println(ic.getSensitivity(), DEC);
  }
  else {
    if(ic.getSensitivity() == TSL230R_PWR_DOWN)
      Serial.print("power down");
    else {
      Serial.print("current sensitivity: ");
      Serial.println(ic.getSensitivity(), DEC);
    }
  }
}
////////////////////////////////////////////////////////////////////////////////
float measureOnce() {
  showResult = false;
  ATmegaTimer2.setValue(0x00);
  int1_cnt = 0L;
  ATmegaTimer2.setClkSelect(0x07);
  enableExternalINT();

  while(! showResult) {}
  /*
  Serial.print("freq (Hz),");
  Serial.print(int1_totalCnt, DEC);
  Serial.println();
  */
  return (float)int1_totalCnt;
}
////////////////////////////////////////////////////////////////////////////////
void measure(char *arg) {
  float tmp = 0.0;

  for(int i = 0; i < 4; i++) {
    Serial.print("measurement ");
    Serial.println((i + 1), DEC);
    tmp += measureOnce();
  }

  ic.freq2irradiance(tmp/4.0);
}
////////////////////////////////////////////////////////////////////////////////
void loop() {
  if(Serial.available()) {
    QuickCLI.process(Serial.read());
  }
  if(QuickCLI.cmdDone == 1) {
    QuickCLI.execute();
  }
}
////////////////////////////////////////////////////////////////////////////////
ISR(TIMER2_COMPA_vect) {
  timer2_ovfCnt ++;
  if(timer2_ovfCnt == TIMER_CNT) {
    ATmegaTimer2.stopTimer();
    disableExternalINT();
    int1_totalCnt = int1_cnt;
    timer2_ovfCnt = 0;
    showResult = true;
  }
}
////////////////////////////////////////////////////////////////////////////////