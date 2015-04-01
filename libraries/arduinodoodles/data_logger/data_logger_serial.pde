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
int dl_ser_getCmd() {
  char chBuf[1];

  strcpy(chBuf, "");
  if(Serial.available()) {
    chBuf[0] = Serial.read();

    if((chBuf[0] > 31) && (chBuf[0] < 128)) {
      if(CFG_ECHO && DL.serCmdDisable) {
        Serial.print(chBuf[0]);
      }
      if(strlen(DL.serCmd) < CMD_LENGTH) {
        strncat(DL.serCmd, chBuf, 1);
      }
      return 0;
    }

    if((chBuf[0] == '\n') || (chBuf[0] == '\r')) {
      if(DL.serCmdDisable) {
        Serial.println();
      }
      return 1;
    }
  }
}
////////////////////////////////////////////////////////////////////////////////
void dl_ser_printVersion() {
  Serial.print("version: " );
  Serial.println(APP_VER);
}

void dl_ser_printState() {
  Serial.print("state: ");
  switch(DL.state) {
    case STATE_IDLE:
      Serial.println("IDLE");
      break;
    case STATE_CAPTURE:
      Serial.println("CAPTURE");
      break;
  }
}

void dl_ser_printShield() {
  Serial.print("shield used: ");
  switch(DL.shield) {
    case SHIELD_NONE:
      Serial.println("NONE");
      break;
    //case SHIELD_1:
    //  Serial.println("???");
    //  break;
  }
}

void dl_ser_printInterval() {
  Serial.print("capture every: ");
  Serial.print(DL.period, DEC);
  Serial.println(" sec");
}

void dl_ser_printStatus() {
  dl_ser_printState();
  dl_ser_printShield();
  dl_ser_printInterval();
}
////////////////////////////////////////////////////////////////////////////////
void dl_ser_executeCmd() {
  char *cmd;
  char *arg1;

  cmd = strtok(DL.serCmd, " ");
  arg1 = strtok(NULL, " ");

  if(DL.state == STATE_IDLE) {
    if(strcmp(cmd, CMD_HELP) == 0) {
      Serial.println("data logger");
      dl_ser_printVersion();
      Serial.println("available commands:");
      Serial.print("  ");
      Serial.println(CMD_STATUS);
      Serial.print("  ");
      Serial.println(CMD_SHLD);
      Serial.print("  ");
      Serial.println(CMD_SEC);
      Serial.print("  ");
      Serial.println(CMD_START);
      Serial.print("  ");
      Serial.println(CMD_STOP);
    }
    else if(strcmp(cmd, CMD_STATUS) == 0) {
      dl_ser_printStatus();
    }
    else if(strcmp(cmd, CMD_SHLD) == 0) {
      if(arg1 == NULL) {
        dl_base_shldNone_setup();
      }
      //else if(strcmp(arg1, "1") == 0) {
      //}
      dl_ser_printShield();
    }
    else if(strcmp(cmd,CMD_SEC) == 0) {
      if(arg1 == NULL) {
        DL.period = MIN_CAPTURE_INTERVAL;
      }
      else {
        int sec = atoi(arg1);

        if((sec < MIN_CAPTURE_INTERVAL) || (sec > MAX_CAPTURE_INTERVAL)) {
          DL.period = MIN_CAPTURE_INTERVAL;
        }
        else {
          DL.period = sec;
        }
      }
      dl_ser_printInterval();
    }
    else if(strcmp(cmd, CMD_START) == 0) {
      dl_base_gotoState(STATE_CAPTURE);
    }
  }
  else if(DL.state == STATE_CAPTURE) {
    if(strcmp(cmd, CMD_STOP) == 0) {
      dl_base_gotoState(STATE_IDLE);
      Serial.println();
    }
  }

  strcpy(DL.serCmd, "");
  if(DL.serCmdDisable) {
    Serial.print(APP_PROMPT);
  }
}
////////////////////////////////////////////////////////////////////////////////