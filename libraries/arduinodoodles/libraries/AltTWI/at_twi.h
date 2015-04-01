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
#ifndef AT_TWI_h
#define AT_TWI_h

#include <inttypes.h>

#define AT_TWI_TX_BUFFER_SIZE 32
#define AT_TWI_RX_BUFFER_SIZE 32

#define AT_TWI_STATE_INIT 0
#define AT_TWI_STATE_MASTER_IDLE 1
#define AT_TWI_STATE_MASTER_TX 3
#define AT_TWI_STATE_MASTER_RX 5
#define AT_TWI_STATE_SLAVE_IDLE 2
#define AT_TWI_STATE_SLAVE_TX 4
#define AT_TWI_STATE_SLAVE_RX 6

#define AT_TWI_TXOPT_NONE 0
#define AT_TWI_TXOPT_NOSTOP 1

uint8_t at_twi_setBuffers();
void at_twi_setTXBuffer(uint8_t* buff, int16_t len);
void at_twi_attachRXCallback(void (*function) (uint8_t*, int16_t));
void at_twi_attachTXCallback(void (*function) (uint8_t));

void at_twi_setRate(uint32_t f, uint8_t prescaler);
void at_twi_setSlaveAddr(uint8_t addr, uint8_t mask);
void at_twi_setMaster();
void at_twi_setSlave();
void at_twi_masterWrite(uint8_t addr, uint8_t opt);
void at_twi_masterRead(uint8_t addr, uint8_t len, uint8_t opt);

uint8_t at_twi_get_TW_STATUS();
uint8_t at_twi_getState();

void at_twi_slRX(uint8_t ack);

#endif
////////////////////////////////////////////////////////////////////////////////