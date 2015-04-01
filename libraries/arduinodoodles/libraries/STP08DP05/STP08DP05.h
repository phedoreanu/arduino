/*
This file is part of STP08DP05.

STP08DP05 is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

STP08DP05 is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with STP08DP05.  If not, see <http://www.gnu.org/licenses/>.
*/
////////////////////////////////////////////////////////////////////////////////
#ifndef STP08DP05_h
#define STP08DP05_h

#include "WProgram.h"

class STP08DP05
{
  public:
    STP08DP05(int16_t pOE, int16_t pLE, int16_t pCLK, int16_t pSDI, int16_t pSDO);
    void enableOut();
    void disableOut();
    char setOut(uint8_t data);
    char chkOut();

  private:
    int16_t pinOE;
    int16_t pinLE;
    int16_t pinCLK;
    int16_t pinSDI;
    int16_t pinSDO;

    char transferBit(char sdi);
    void startDetectMode();
    void endDetectMode();
};

#endif
////////////////////////////////////////////////////////////////////////////////