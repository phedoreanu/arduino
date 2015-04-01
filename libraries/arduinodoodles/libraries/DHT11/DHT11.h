/*
This file is part of DHT11.

DHT11 is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

DHT11 is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with DHT11.  If not, see <http://www.gnu.org/licenses/>.
*/
////////////////////////////////////////////////////////////////////////////////
#ifndef DHT11_h
#define DHT11_h

#include "WProgram.h"

const int DHT11_SAMPLES = 1024;
const int DHT11_NBITS = 40;
const int DHT11_STATE_IDLE = 0;
const int DHT11_START_ZERO = 1;
const int DHT11_START_ONE = 2;
const int DHT11_START_BIT = 3;
const int DHT11_END_BIT = 4;
const int DHT11_ERR1 = 101;
const int DHT11_ERR2 = 102;
const int DHT11_ERR3 = 103;

class DHT11Class
{
  public:
    int rh;
    int temp;

    void setPin(int pin);
    int read();

  private:
    int pin;
    int owState;
};

extern DHT11Class DHT11;

#endif
////////////////////////////////////////////////////////////////////////////////