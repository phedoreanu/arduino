/*
This file is part of ATmegaTimer1.

ATmegaTimer1 is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

ATmegaTimer1 is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with ATmegaTimer1.  If not, see <http://www.gnu.org/licenses/>.
*/
////////////////////////////////////////////////////////////////////////////////
#ifndef TIMER1_h
#define TIMER1_h

#include "WProgram.h"

const uint8_t COM1A_TOGGLE = _BV(COM1A0);
const uint8_t COM1A_CLEAR  = _BV(COM1A1);
const uint8_t COM1A_SET    = _BV(COM1A1) | _BV(COM1A0);
const uint8_t COM1B_TOGGLE = _BV(COM1B0);
const uint8_t COM1B_CLEAR  = _BV(COM1B1);
const uint8_t COM1B_SET    = _BV(COM1B1) | _BV(COM1B0);

const uint8_t WGM1_PWM1 = _BV(WGM10);
const uint8_t WGM1_PWM2 = _BV(WGM11);
const uint8_t WGM1_PWM3 = _BV(WGM11) | _BV(WGM10);

const uint8_t CS1_DIV1        = _BV(CS10);
const uint8_t CS1_DIV8        = _BV(CS11);
const uint8_t CS1_DIV64       = _BV(CS11) | _BV(CS10);
const uint8_t CS1_DIV256      = _BV(CS12);
const uint8_t CS1_DIV1024     = _BV(CS12) | _BV(CS10);
const uint8_t CS1_EXT_T1_FALL = _BV(CS12) | _BV(CS11);
const uint8_t CS1_EXT_T1_RISE = _BV(CS12) | _BV(CS11) | _BV(CS10);

class ATmegaTimer1Class
{
  public:
    void setControlRegs(uint8_t coma, uint8_t comb, uint8_t wgm, uint8_t cs,
      uint8_t icnc, uint8_t ices);
    void setIntMask(uint8_t icie, uint8_t ociea, uint8_t ocieb, uint8_t toie);
    void setClkSelect(uint8_t cs);
    void setOutCompare(uint16_t ocra, uint16_t ocrb);
    inline uint16_t getInCapture() { return ICR1; };
    inline void setValue(uint16_t val) { TCNT1 = val; };
    inline void forceOutCmpA() { TCCR1C |= _BV(FOC1A); };
    inline void forceOutCmpB() { TCCR1C |= _BV(FOC1B); };
    inline void clrIntMask() { TIMSK1 = 0x00; };
    inline void stopTimer() { TCCR1B &= ~(CS1_EXT_T1_RISE); };
};

extern ATmegaTimer1Class ATmegaTimer1;

#endif
////////////////////////////////////////////////////////////////////////////////