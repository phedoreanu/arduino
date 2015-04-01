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
#include "ATmegaTimer1.h"
////////////////////////////////////////////////////////////////////////////////
void ATmegaTimer1Class::setControlRegs(uint8_t coma, uint8_t comb,
    uint8_t wgm, uint8_t cs, uint8_t icnc, uint8_t ices) {
  uint8_t tmpTCCR1A = 0x00;
  uint8_t tmpTCCR1B = 0x00;

  TCCR1A = tmpTCCR1A;
  TCCR1B = tmpTCCR1B;

  if(coma == 1) {
    tmpTCCR1A |= COM1A_TOGGLE;
  }
  else if(coma == 2) {
    tmpTCCR1A |= COM1A_CLEAR;
  }
  else if(coma == 3) {
    tmpTCCR1A |= COM1A_SET;
  }

  if(comb == 1) {
    tmpTCCR1A |= COM1B_TOGGLE;
  }
  else if(comb == 2) {
    tmpTCCR1A |= COM1B_CLEAR;
  }
  else if(comb == 3) {
    tmpTCCR1A |= COM1B_SET;
  }

  if(wgm == 1) {
    tmpTCCR1A |= WGM1_PWM1;
  }
  else if(wgm == 2) {
    tmpTCCR1A |= WGM1_PWM2;
  }
  else if(wgm == 3) {
    tmpTCCR1A |= WGM1_PWM3;
  }
  else if(wgm == 4) {
    tmpTCCR1B |= _BV(WGM12);
  }
  else if(wgm == 5) {
    tmpTCCR1B |= _BV(WGM12);
    tmpTCCR1A |= WGM1_PWM1;
  }
  else if(wgm == 6) {
    tmpTCCR1B |= _BV(WGM12);
    tmpTCCR1A |= WGM1_PWM2;
  }
  else if(wgm == 7) {
    tmpTCCR1B |= _BV(WGM12);
    tmpTCCR1A |= WGM1_PWM3;
  }
  else if(wgm == 8) {
    tmpTCCR1B |= _BV(WGM13);
  }
  else if(wgm == 9) {
    tmpTCCR1B |= _BV(WGM13);
    tmpTCCR1A |= WGM1_PWM1;
  }
  else if(wgm == 10) {
    tmpTCCR1B |= _BV(WGM13);
    tmpTCCR1A |= WGM1_PWM2;
  }
  else if(wgm == 11) {
    tmpTCCR1B |= _BV(WGM13);
    tmpTCCR1A |= WGM1_PWM3;
  }
  else if(wgm == 12) {
    tmpTCCR1B |= _BV(WGM13) | _BV(WGM12);
  }
  else if(wgm == 13) {
    return;
  }
  else if(wgm == 14) {
    tmpTCCR1B |= _BV(WGM13) | _BV(WGM12);
    tmpTCCR1A |= WGM1_PWM2;
  }
  else if(wgm == 15) {
    tmpTCCR1B |= _BV(WGM13) | _BV(WGM12);
    tmpTCCR1A |= WGM1_PWM3;
  }

  if(cs == 1) {
    tmpTCCR1B |= CS1_DIV1;
  }
  else if(cs == 2) {
    tmpTCCR1B |= CS1_DIV8;
  }
  else if(cs == 3) {
    tmpTCCR1B |= CS1_DIV64;
  }
  else if(cs == 4) {
    tmpTCCR1B |= CS1_DIV256;
  }
  else if(cs == 5) {
    tmpTCCR1B |= CS1_DIV1024;
  }
  else if(cs == 6) {
    tmpTCCR1B |= CS1_EXT_T1_FALL;
  }
  else if(cs == 7) {
    tmpTCCR1B |= CS1_EXT_T1_RISE;
  }

  if(icnc == 1) {
    tmpTCCR1B |= _BV(ICNC1);
  }

  if(ices == 1) {
    tmpTCCR1B |= _BV(ICES1);
  }

  TCCR1A = tmpTCCR1A;
  TCCR1B = tmpTCCR1B;
}
////////////////////////////////////////////////////////////////////////////////
void ATmegaTimer1Class::setIntMask(uint8_t icie,
    uint8_t ociea, uint8_t ocieb, uint8_t toie) {
  uint8_t tmpTIMSK1 = 0x00;

  TIMSK1 = tmpTIMSK1;

  if(icie == 1) {
    tmpTIMSK1 |= _BV(ICIE1);
  }

  if(ociea == 1) {
    tmpTIMSK1 |= _BV(OCIE1A);
  }

  if(ocieb == 1) {
    tmpTIMSK1 |= _BV(OCIE1B);
  }

  if(toie == 1) {
    tmpTIMSK1 |= _BV(TOIE1);
  }

  TIMSK1 = tmpTIMSK1;
}
////////////////////////////////////////////////////////////////////////////////
void ATmegaTimer1Class::setClkSelect(uint8_t cs) {
  stopTimer();

  uint8_t tmpTCCR1B = TCCR1B;
  tmpTCCR1B |= (CS1_EXT_T1_RISE & cs);

  TCCR1B = tmpTCCR1B;
}
////////////////////////////////////////////////////////////////////////////////
void ATmegaTimer1Class::setOutCompare(uint16_t ocra, uint16_t ocrb) {
  OCR1A = ocra;
  OCR1B = ocrb;
}
////////////////////////////////////////////////////////////////////////////////
ATmegaTimer1Class ATmegaTimer1;