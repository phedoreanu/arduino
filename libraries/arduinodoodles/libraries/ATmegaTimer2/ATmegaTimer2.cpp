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
#include "ATmegaTimer2.h"
////////////////////////////////////////////////////////////////////////////////
void ATmegaTimer2Class::setControlRegs(uint8_t coma, uint8_t comb,
    uint8_t wgm, uint8_t cs) {
  uint8_t tmpTCCR2A = 0x00;
  uint8_t tmpTCCR2B = 0x00;

  TCCR2A = tmpTCCR2A;
  TCCR2B = tmpTCCR2B;

  if(coma == 1) {
    tmpTCCR2A |= COM2A_TOGGLE;
  }
  else if(coma == 2) {
    tmpTCCR2A |= COM2A_CLEAR;
  }
  else if(coma == 3) {
    tmpTCCR2A |= COM2A_SET;
  }

  if(comb == 1) {
    tmpTCCR2A |= COM2B_TOGGLE;
  }
  else if(comb == 2) {
    tmpTCCR2A |= COM2B_CLEAR;
  }
  else if(comb == 3) {
    tmpTCCR2A |= COM2B_SET;
  }

  if(wgm == 1) {
    tmpTCCR2A |= WGM2_PWM_PH;
  }
  else if(wgm == 2) {
    tmpTCCR2A |= WGM2_CTC;
  }
  else if(wgm == 3) {
    tmpTCCR2A |= WGM2_PWM_FAST;
  }
  else if(wgm == 4) {
    return;
  }
  else if(wgm == 5) {
    tmpTCCR2B |= _BV(WGM22);
    tmpTCCR2A |= WGM2_PWM_PH;
  }
  else if(wgm == 6) {
    return;
  }
  else if(wgm == 7) {
    tmpTCCR2B |= _BV(WGM22);
    tmpTCCR2A |= WGM2_PWM_FAST;
  }

  if(cs == 1) {
    tmpTCCR2B |= CS2_DIV1;
  }
  else if(cs == 2) {
    tmpTCCR2B |= CS2_DIV8;
  }
  else if(cs == 3) {
    tmpTCCR2B |= CS2_DIV32;
  }
  else if(cs == 4) {
    tmpTCCR2B |= CS2_DIV64;
  }
  else if(cs == 5) {
    tmpTCCR2B |= CS2_DIV128;
  }
  else if(cs == 6) {
    tmpTCCR2B |= CS2_DIV256;
  }
  else if(cs == 7) {
    tmpTCCR2B |= CS2_DIV1024;
  }

  TCCR2A = tmpTCCR2A;
  TCCR2B = tmpTCCR2B;
}
////////////////////////////////////////////////////////////////////////////////
void ATmegaTimer2Class::setIntMask(uint8_t ociea, uint8_t ocieb, uint8_t toie) {
  uint8_t tmpTIMSK2 = 0x00;

  TIMSK2 = tmpTIMSK2;

  if(ociea == 1) {
    tmpTIMSK2 |= _BV(OCIE2A);
  }

  if(ocieb == 1) {
    tmpTIMSK2 |= _BV(OCIE2B);
  }

  if(toie == 1) {
    tmpTIMSK2 |= _BV(TOIE2);
  }

  TIMSK2 = tmpTIMSK2;
}
////////////////////////////////////////////////////////////////////////////////
void ATmegaTimer2Class::setClkSelect(uint8_t cs) {
  stopTimer();

  uint8_t tmpTCCR2B = TCCR2B;
  tmpTCCR2B |= (CS2_DIV1024 & cs);

  TCCR2B = tmpTCCR2B;
}
////////////////////////////////////////////////////////////////////////////////
void ATmegaTimer2Class::setOutCompare(uint8_t ocra, uint8_t ocrb) {
  OCR2A = ocra;
  OCR2B = ocrb;
}
////////////////////////////////////////////////////////////////////////////////
ATmegaTimer2Class ATmegaTimer2;