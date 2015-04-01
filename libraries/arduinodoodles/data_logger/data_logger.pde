/*
This file is part of data_logger.

data_logger is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

data_logger is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with data_logger.  If not, see <http://www.gnu.org/licenses/>.
*/
////////////////////////////////////////////////////////////////////////////////
#include <ATmegaTimer2.h>
////////////////////////////////////////////////////////////////////////////////
const int pinLED = 13;

const int CMD_LENGTH = 128;
const long DEFAULT_RS232_RATE = 19200L;
int CFG_ECHO = 1; /** echo of the received character */

const char *APP_VER = "1.1";
const char *APP_PROMPT = "dlog> ";

const char *CMD_HELP   = "help";
const char *CMD_STATUS = "status";
const char *CMD_SHLD   = "shield";
const char *CMD_SEC    = "sec";
const char *CMD_START  = "start";
const char *CMD_STOP   = "stop";
////////////////////////////////////////////////////////////////////////////////
const int STATE_IDLE = 0;
const int STATE_CAPTURE = 1;

const int TIMER_TOP = 124;
const int TIMER_CNT = 125;

const int SHIELD_NONE = 0;
//const int SHIELD_1 = 1;

const float VREF_3v3 = 3.3;
const float VREF_5v0 = 5.0;

const int MIN_CAPTURE_INTERVAL = 1;
const int MAX_CAPTURE_INTERVAL = 8*60; //more than this and DL.period must be long
////////////////////////////////////////////////////////////////////////////////
volatile int timer2_ovfCnt = 0;
volatile byte flgMeasure = 0;

struct DataLogger_s {
  int state;
  int serCmdDisable;
  char serCmd[CMD_LENGTH];
  int shield;
  float vref;
  int period;
} DL;
////////////////////////////////////////////////////////////////////////////////
void dl_base_resetState();
void dl_base_gotoState(int newState);
void dl_base_shldNone_setup();
void dl_base_shldNone_capture();
void dl_base_shldNone_print();
////////////////////////////////////////////////////////////////////////////////
void dl_ser_printVersion();
void dl_ser_printState();
void dl_ser_printShield();
void dl_ser_printInterval();
void dl_ser_printStatus();
int dl_ser_getCmd();
void dl_ser_executeCmd();
////////////////////////////////////////////////////////////////////////////////
void setup() {
  pinMode(pinLED, OUTPUT);

  dl_base_resetState();
  dl_base_shldNone_setup();

  ATmegaTimer2.setControlRegs(0x00, 0x00, 0x00, 0x00, 0x02, 0x00); //CTC mode
  ATmegaTimer2.setOutCompare(TIMER_TOP, 0x00);
  ATmegaTimer2.setIntMask(0x01, 0x00, 0x00); //OCIE2A enabled
  //ATmegaTimer2.setValue(0x00);
  //ATmegaTimer2.setClkSelect(0x07);

  Serial.begin(DEFAULT_RS232_RATE);
  Serial.println();
  Serial.print(APP_PROMPT);
}
////////////////////////////////////////////////////////////////////////////////
void loop() {
  if(dl_ser_getCmd() == 1) {
    dl_ser_executeCmd();
  }

  if(DL.state == STATE_CAPTURE) {
    if(flgMeasure == 1) {
      digitalWrite(pinLED, HIGH);
      switch(DL.shield) {
        case SHIELD_NONE:
          //dl_base_shldNone_capture();
          dl_base_shldNone_print();
      }
      digitalWrite(pinLED, LOW);
      flgMeasure = 0;
    }
  }
}
////////////////////////////////////////////////////////////////////////////////
ISR(TIMER2_COMPA_vect) {
  timer2_ovfCnt++;
  if(timer2_ovfCnt == DL.period*TIMER_CNT) {
    //digitalWrite(pinLED, HIGH);
    //Serial.println("IRQ");
    //digitalWrite(pinLED, LOW);
    flgMeasure = 1;
    timer2_ovfCnt = 0;
  }
}
////////////////////////////////////////////////////////////////////////////////