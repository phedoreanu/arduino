/*
This file is part of MCHP_93LC56B.

MCHP_93LC56B is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

MCHP_93LC56B is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with MCHP_93LC56B.  If not, see <http://www.gnu.org/licenses/>.
*/
////////////////////////////////////////////////////////////////////////////////
#ifndef MCHP_93LC56B_h
#define MCHP_93LC56B_h

#include "WProgram.h"
#include <SPI.h>

class MCHP_93LC56B
{
  public:
    MCHP_93LC56B(int16_t pCS);
    uint16_t read(uint8_t addr);
    void write(uint8_t addr, uint16_t data);
    void erase(uint8_t addr);
    void eral();
    void wral(uint16_t data);
    void ewds();
    void ewen();

  private:
    int16_t pinCS;
};

#endif
////////////////////////////////////////////////////////////////////////////////