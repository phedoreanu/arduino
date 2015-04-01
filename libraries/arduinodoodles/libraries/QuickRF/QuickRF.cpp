/*
This file is part of QuickRF.

QuickRF is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

QuickRF is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with QuickRF.  If not, see <http://www.gnu.org/licenses/>.
*/
////////////////////////////////////////////////////////////////////////////////
#include "QuickRF.h"
////////////////////////////////////////////////////////////////////////////////
int16_t QuickRFClass::init() {
  uint8_t tmp[QRF_ADDR_SIZE] = {0xBA, 0xBE};
  return init(tmp);
}
////////////////////////////////////////////////////////////////////////////////
int16_t QuickRFClass::init(uint8_t *sAddr) {
  for(int i = 0; i < QRF_ADDR_SIZE; i++) {
    srcAddr[i] = sAddr[i];
  }
  devInfo = 0x00;
  txOn = 0;

  return 0;
}
////////////////////////////////////////////////////////////////////////////////
int16_t QuickRFClass::setPayload(uint8_t *data, uint8_t len) {
  phyPayload = (uint8_t *) malloc(len);

  if(phyPayload == NULL)
    return 1;

  for(int i = 0; i < len; i++)
    phyPayload[i] = data[i];

  return 0;
}
////////////////////////////////////////////////////////////////////////////////
int16_t QuickRFClass::startTX(uint8_t *dAddr) {
  for(int i = 0; i < QRF_ADDR_SIZE; i++) {
    dstAddr[i] = dAddr[i];
  }
  txOn = 1;

  return 0;
}
////////////////////////////////////////////////////////////////////////////////
void QuickRFClass::sendBit() {

}
////////////////////////////////////////////////////////////////////////////////
QuickRFClass QuickRF;