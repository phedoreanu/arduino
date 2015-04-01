/*
This file is part of ATmegaTimer2.

ATmegaTimer2 is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

ATmegaTimer2 is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with ATmegaTimer2.  If not, see <http://www.gnu.org/licenses/>.
*/
////////////////////////////////////////////////////////////////////////////////
#ifndef TIMER2_h
#define TIMER2_h

#include "WProgram.h"

const uint8_t COM2A_TOGGLE = _BV(COM2A0);
const uint8_t COM2A_CLEAR  = _BV(COM2A1);
const uint8_t COM2A_SET    = _BV(COM2A1) | _BV(COM2A0);
const uint8_t COM2B_TOGGLE = _BV(COM2B0);
const uint8_t COM2B_CLEAR  = _BV(COM2B1);
const uint8_t COM2B_SET    = _BV(COM2B1) | _BV(COM2B0);

const uint8_t WGM2_PWM_PH   = _BV(WGM20);
const uint8_t WGM2_CTC      = _BV(WGM21);
const uint8_t WGM2_PWM_FAST = _BV(WGM21) | _BV(WGM20);

const uint8_t CS2_DIV1    = _BV(CS20);
const uint8_t CS2_DIV8    = _BV(CS21);
const uint8_t CS2_DIV32   = _BV(CS21) | _BV(CS20);
const uint8_t CS2_DIV64   = _BV(CS22);
const uint8_t CS2_DIV128  = _BV(CS22) | _BV(CS20);
const uint8_t CS2_DIV256  = _BV(CS22) | _BV(CS21);
const uint8_t CS2_DIV1024 = _BV(CS22) | _BV(CS21) | _BV(CS20);

class ATmegaTimer2Class
{
  public:
    void setControlRegs(uint8_t coma, uint8_t comb, uint8_t wgm, uint8_t cs);
    void setIntMask(uint8_t ociea, uint8_t ocieb, uint8_t toie);
    void setClkSelect(uint8_t cs);
    void setOutCompare(uint8_t ocra, uint8_t ocrb);
    inline void setValue(uint8_t val) { TCNT2 = val; };
    inline void forceOutCmpA() { TCCR2B |= _BV(FOC2A); };
    inline void forceOutCmpB() { TCCR2B |= _BV(FOC2B); };
    inline void clrIntMask() { TIMSK2 = 0x00; };
    inline void stopTimer() { TCCR2B &= ~(CS2_DIV1024); };
};

extern ATmegaTimer2Class ATmegaTimer2;

#endif
////////////////////////////////////////////////////////////////////////////////