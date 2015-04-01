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
#ifndef QUICKRF_h
#define QUICKRF_h

#include "WProgram.h"

const int QRF_ADDR_SIZE = 2;

const uint8_t QRF_PHY_START = 0xAA;
const uint8_t QRF_PHY_END = 0xAA;

/*
 * 1 byte START
 * 2 bytes SRC_ADDR
 * 2 bytes DST_ADDR
 * 1 byte data length
 * 1 byte sequence number
 * 1 byte device info
 * n bytes data
 * 1 byte CRC-8 (WCDMA x^8 + x^7 + x^4 + x^3 + x + 1)
 * 1 byte STOP
 * frame length = (n + 10)
 */

class QuickRFClass
{
  public:
    int16_t init();
    int16_t init(uint8_t *sAddr);
    int16_t setPayload(uint8_t *data, uint8_t len);
    int16_t startTX(uint8_t *dAddr);
    void sendBit();
    uint8_t txOn;

  private:
    uint8_t srcAddr[QRF_ADDR_SIZE];
    uint8_t dstAddr[QRF_ADDR_SIZE];
    uint8_t devInfo;
    uint8_t *phyPayload;
};

extern QuickRFClass QuickRF;

#endif
////////////////////////////////////////////////////////////////////////////////