/*
This file is part of TSL230R.

TSL230R is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

TSL230R is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with TSL230R.  If not, see <http://www.gnu.org/licenses/>.
*/
////////////////////////////////////////////////////////////////////////////////
#ifndef TSL230R_h
#define TSL230R_h

#include "WProgram.h"

const uint8_t TSL230R_PWR_DOWN = 0;
const uint8_t TSL230R_SENS_1x = 1;
const uint8_t TSL230R_SENS_10x = 10;
const uint8_t TSL230R_SENS_100x = 100;

const uint8_t TSL230R_SCALE_1 = 1;
const uint8_t TSL230R_SCALE_2 = 2;
const uint8_t TSL230R_SCALE_10 = 10;
const uint8_t TSL230R_SCALE_100 = 100;

class TSL230R
{
  public:
    TSL230R(int16_t pOE, int16_t pS0, int16_t pS1, int16_t pS2, int16_t pS3);
    inline void enableOut() { digitalWrite(pinOE, LOW); };
    inline void disableOut() { digitalWrite(pinOE, HIGH); };
    void setSensitivity(uint8_t data);
    inline uint8_t getSensitivity() { return sensitivity;  };
    void setFreqScaling(uint8_t data);
    inline uint8_t getFreqScaling() { return freqScaling; };
    float freq2irradiance(float f);

  private:
    int16_t pinOE;
    int16_t pinS0;
    int16_t pinS1;
    int16_t pinS2;
    int16_t pinS3;
    uint8_t sensitivity;
    uint8_t freqScaling;
};

#endif
////////////////////////////////////////////////////////////////////////////////
