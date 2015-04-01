/*
This file is part of AltTWI.

AltTWI is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

AltTWI is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with AltTWI.  If not, see <http://www.gnu.org/licenses/>.
*/
////////////////////////////////////////////////////////////////////////////////
#ifndef ALTTWI_h
#define ALTTWI_h

#include "WProgram.h"

class AltTWIClass {
  public:
    AltTWIClass();
    void init(uint32_t f);
    void init(uint32_t f, uint8_t slAddr);
    void init(uint32_t f, uint8_t slAddr, uint8_t slAddrMsk);

    void setTXCallback(void (*) (uint8_t));
    void setRXCallback(void (*) (uint8_t*, int16_t));

    void sendToMaster(uint8_t *data, int16_t len, uint8_t opt);
    void sendToSlave(uint8_t addr, uint8_t *data, int16_t len, uint8_t opt);
    void getFromSlave(uint8_t addr, int16_t len, uint8_t opt);

    void printAllRegs();
    void printTWIStatus();

  private:
    static void (*userTXCallback) (uint8_t);
    static void (*userRXCallback) (uint8_t*, int16_t);

    static void onTX(uint8_t status);
    static void onRX(uint8_t* data, int16_t len);
};

extern AltTWIClass AltTWI;

#endif
////////////////////////////////////////////////////////////////////////////////