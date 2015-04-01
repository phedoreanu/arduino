/*
This file is part of tty_echo.

tty_echo is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

tty_echo is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with tty_echo.  If not, see <http://www.gnu.org/licenses/>.
*/
////////////////////////////////////////////////////////////////////////////////
const int CMD_LENGTH = 256;
const long DEFAULT_RS232_RATE = 19200L;
const int ECHO_ON = 0; /** echo of the received character */

//#define RX_LINE_END_NL  /** use this if the received lines are finished with \n */
#define RX_LINE_END_CR  /** use this if the received lines are finished with \r */

const char *APP_VER = "1.0";
const char *APP_PROMPT = "echo> ";

char serCmd[CMD_LENGTH];
////////////////////////////////////////////////////////////////////////////////
void setup() {
  Serial.begin(DEFAULT_RS232_RATE);
  Serial.println();
  Serial.print(APP_PROMPT);

  strcpy(serCmd, "");
}
////////////////////////////////////////////////////////////////////////////////
/**
 change as needed to process the received command
*/
void procesCmd() {
  if(strcmp(serCmd, "help") == 0) {
    Serial.print("serial port echo ver ");
    Serial.println(APP_VER);
  }
  else {
    Serial.println(serCmd);
  }
}
////////////////////////////////////////////////////////////////////////////////
/**
 gets each ASCII non-control character into the serCmd buffer until end of line is recieved

 @see RX_LINE_END_NL
 @see RX_LINE_END_CR
*/
void loop() {
  char chBuf[1];

  strcpy(chBuf, "");
  if(Serial.available()) {
    chBuf[0] = Serial.read();

    if((chBuf[0] > 31) && (chBuf[0] < 128)) {
      if(ECHO_ON) {
        Serial.print(chBuf[0]);
      }
      if(strlen(serCmd) < CMD_LENGTH) {
        strncat(serCmd, chBuf, 1);
      }
    }

    #ifdef RX_LINE_END_NL
    if(chBuf[0] == '\n') {
      Serial.println();
      if(strlen(serCmd) > 0) {
        procesCmd();
      }
      Serial.print(APP_PROMPT);
      strcpy(serCmd, "");
    }
    #endif
    #ifdef RX_LINE_END_CR
    if(chBuf[0] == '\r') {
      Serial.println();
      if(strlen(serCmd) > 0) {
        procesCmd();
      }
      Serial.print(APP_PROMPT);
      strcpy(serCmd, "");
    }
    #endif
  }
}
////////////////////////////////////////////////////////////////////////////////