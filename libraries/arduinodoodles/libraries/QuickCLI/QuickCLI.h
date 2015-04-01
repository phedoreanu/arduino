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
#ifndef QuickCLI_h
#define QuickCLI_h

#include "WProgram.h"

const int QCLI_CMD_LENGTH = 128;

typedef struct {
  char *cmdName;
  char *descArg;
  void (*fctn)(char *arg);
} QuickCLIMethod;

class QuickCLIClass {
  public:
    uint8_t cmdDone;
    void init(char *strPrompt);
    void setMethods(QuickCLIMethod *arr, uint8_t n);
    void setEchoOn();
    void setEchoOff();
    void process(uint16_t ch);
    void execute();

  private:
    uint8_t echoOn;
    char *prompt;
    QuickCLIMethod *methods;
    uint8_t nMethods;
    char cmd[QCLI_CMD_LENGTH];

    void printIntro();
    void printHelp();
};

extern QuickCLIClass QuickCLI;

#endif
////////////////////////////////////////////////////////////////////////////////