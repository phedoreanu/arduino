/*
This file is part of QuickCLI.

QuickCLI is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

QuickCLI is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with QuickCLI.  If not, see <http://www.gnu.org/licenses/>.
*/
////////////////////////////////////////////////////////////////////////////////
#include "QuickCLI.h"
////////////////////////////////////////////////////////////////////////////////
void QuickCLIClass::init(char *strPrompt) {
  cmdDone = 0;

  echoOn = 1;

  prompt = (char *)malloc(strlen(strPrompt) + 1);
  strcpy(prompt, strPrompt);

  methods = NULL;
  nMethods = 0;

  strcpy(cmd, "");

  printIntro();
  Serial.print(prompt);
  Serial.print("> ");
}
////////////////////////////////////////////////////////////////////////////////
void QuickCLIClass::setMethods(QuickCLIMethod *arr, uint8_t n) {
  methods = arr;
  nMethods = n;
}
////////////////////////////////////////////////////////////////////////////////
void QuickCLIClass::printIntro() {
  Serial.println();
  Serial.println("QuickCLI (part of Arduino Doodles)");
  Serial.println("http://sourceforge.net/projects/arduinodoodles");
  Serial.println();
}
////////////////////////////////////////////////////////////////////////////////
void QuickCLIClass::printHelp() {
  if(echoOn) {
    Serial.println("available commands:");
    Serial.println("help");
    for(int i=0; i<nMethods; i++) {
      Serial.print(methods[i].cmdName);
      Serial.print(" - ");
      Serial.println(methods[i].descArg);
    }
  }
}
////////////////////////////////////////////////////////////////////////////////
void QuickCLIClass::setEchoOn() {
  echoOn = 1;
}
////////////////////////////////////////////////////////////////////////////////
void QuickCLIClass::setEchoOff() {
  echoOn = 0;
}
////////////////////////////////////////////////////////////////////////////////
void QuickCLIClass::process(uint16_t ch) {
  // ignore input if a command is in progress
  if(cmdDone > 0) {
    return;
  }

  char chBuf[1];

  strcpy(chBuf, "");
  chBuf[0] = (char)ch;

  if((chBuf[0] == '\n') || (chBuf[0] == '\r')) {
    if(echoOn) {
      Serial.println();
    }
    cmdDone = 1;
    return;
  }
  if(chBuf[0] == '\b') {
    if(strlen(cmd) > 0) {
      if(echoOn) {
        Serial.print(chBuf[0]);
        Serial.print(" ");
        Serial.print(chBuf[0]);
        cmd[strlen(cmd) - 1] = '\0';
      }
    }
    return;
  }

  if((chBuf[0] > 31) && (chBuf[0] < 128)) {
    if(echoOn) {
      Serial.print(chBuf[0]);
    }
    if(strlen(cmd) < QCLI_CMD_LENGTH) {
      strncat(cmd, chBuf, 1);
    }
  }
}
////////////////////////////////////////////////////////////////////////////////
void QuickCLIClass::execute() {
  String tmpCmd = cmd;

  if(tmpCmd.length() == 0) {
  }
  else if(tmpCmd.startsWith("help"))
    printHelp();
  else {
    uint8_t bFound = 0;

    for(int i = 0; i < nMethods; i++) {
      if(tmpCmd.startsWith(methods[i].cmdName)) {
        methods[i].fctn(cmd);
        bFound = 1;
        break;
      }
    }

    if(!bFound) {
      if(echoOn)
        Serial.println("unrecognized command");
    }
  }

  strcpy(cmd, "");

  if(echoOn) {
    Serial.print(prompt);
    Serial.print("> ");
  }

  cmdDone = 0;
}
////////////////////////////////////////////////////////////////////////////////
QuickCLIClass QuickCLI;