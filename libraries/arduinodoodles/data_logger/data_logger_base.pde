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
void dl_base_resetState() {
  DL.state = STATE_IDLE;
  DL.serCmdDisable = 1;
  strcpy(DL.serCmd, "");
  DL.shield = SHIELD_NONE;
  DL.vref = VREF_5v0;
  DL.period = MIN_CAPTURE_INTERVAL;
}
////////////////////////////////////////////////////////////////////////////////
void dl_base_gotoState(int newState) {
  switch(DL.state) {
    case STATE_IDLE:
      if(newState == STATE_CAPTURE) {
        DL.serCmdDisable = 0;
        timer2_ovfCnt = 0;
        ATmegaTimer2.setValue(0x00);
        ATmegaTimer2.setClkSelect(0x07);
        DL.state = newState;
      }
      break;
    case STATE_CAPTURE:
      if(newState == STATE_IDLE) {
        ATmegaTimer2.stopTimer();
        DL.serCmdDisable = 1;
        DL.state = newState;
      }
      break;
    default:
      dl_base_resetState();
      break;
  }
}
////////////////////////////////////////////////////////////////////////////////
void dl_base_shldNone_setup() {
  DL.shield = SHIELD_NONE;
  analogReference(DEFAULT);
  DL.vref = VREF_5v0;
}
////////////////////////////////////////////////////////////////////////////////
void dl_base_shldNone_capture() {

}
////////////////////////////////////////////////////////////////////////////////
void dl_base_shldNone_print() {
  Serial.println();
  for(int pin = 0; pin < 6; pin++) {
    int tmp = analogRead(pin);
    float v = ((float)tmp/1023.0)*DL.vref;

    //Serial.print(tmp, DEC);
    Serial.print(v, 3);
    Serial.print(",");
  }
  Serial.print(millis());
}
////////////////////////////////////////////////////////////////////////////////