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
#include <math.h>
#include <stdlib.h>
#include <inttypes.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/twi.h>

#include "at_twi.h"
////////////////////////////////////////////////////////////////////////////////
static uint8_t *at_twi_txBuffer;
volatile static uint8_t at_twi_txBufferIdx;
static uint8_t at_twi_txBufferSize = 0;
static uint8_t *at_twi_rxBuffer;
volatile static uint8_t at_twi_rxBufferIdx;
static uint8_t at_twi_rxBufferSize = 0;

volatile static uint8_t at_twi_state = AT_TWI_STATE_INIT;
static uint8_t at_twi_sla; /**< TWI 7 bit slave address + Read/not Write bit */
static uint8_t at_twi_txopt = 0; /**< additional options for TX */
volatile static uint8_t at_twi_status = TW_NO_INFO;

static void (*at_twi_onTX) (uint8_t);/**< TX callback function */
static void (*at_twi_onRX) (uint8_t*, int16_t); /**< RX callback function */
////////////////////////////////////////////////////////////////////////////////
/**
 * allocate memory for TX and RX buffers.
 */
uint8_t at_twi_setBuffers() {
  at_twi_txBuffer = (uint8_t*) calloc(AT_TWI_TX_BUFFER_SIZE, sizeof(uint8_t));
  if(at_twi_txBuffer == NULL) {
    return 1;
  }
  at_twi_rxBuffer = (uint8_t*) calloc(AT_TWI_RX_BUFFER_SIZE, sizeof(uint8_t));
  if(at_twi_rxBuffer == NULL) {
    return 2;
  }
  at_twi_txBufferSize = 0;
  at_twi_rxBufferSize = AT_TWI_RX_BUFFER_SIZE;
  at_twi_txBufferIdx = 0;
  at_twi_rxBufferIdx = 0;
  return 0;
}

/**
 * copy data to TX buffer.
 */
void at_twi_setTXBuffer(uint8_t* buff, int16_t len) {
  int i;

  if(len <= AT_TWI_TX_BUFFER_SIZE) {
    for(i = 0; i < len; i++) {
      at_twi_txBuffer[i] = buff[i];
    }
    at_twi_txBufferSize = len;
  }
}
////////////////////////////////////////////////////////////////////////////////
void at_twi_attachRXCallback( void (*function)(uint8_t*, int16_t) ) {
  at_twi_onRX = function;
}

void at_twi_attachTXCallback( void (*function)(uint8_t) ) {
  at_twi_onTX = function;
}
////////////////////////////////////////////////////////////////////////////////
/**
 * set bit rate register.
 *
 * @param f - desired frequency (in Hz)
 * @param prescaler - rate prescaler
 *
 * @todo - can be improved to handle errors in frequency calculation
 */
void at_twi_setRate(uint32_t f, uint8_t prescaler) {
  uint8_t tmp;

  switch(prescaler) {
    case 4:
      TWSR = _BV(TWPS0);
      break;
    case 16:
      TWSR = _BV(TWPS1);
      break;
    case 64:
      TWSR = (_BV(TWPS1) | _BV(TWPS0));
      break;
    default: // prescaler set to 1
      TWSR = 0x00;
      break;
  }
  tmp = ((uint8_t)(F_CPU/f) - 16)/2; // see datasheet - 21.5.2 Bit Rate Generator Unit
  TWBR = tmp;
}

/**
 * set slave address registers.
 *
 * @param addr - slave address
 * @param mask - slave address mask
 */
void at_twi_setSlaveAddr(uint8_t addr, uint8_t mask) {
  TWAMR = mask;
  TWAR = addr;
}

void at_twi_setMaster() {
  at_twi_state = AT_TWI_STATE_MASTER_IDLE;
  // enble TWI interface and TWI interrupt
  TWCR = (_BV(TWEN) | _BV(TWIE));
}

void at_twi_setSlave() {
  at_twi_state = AT_TWI_STATE_SLAVE_IDLE;
  // enble TWI interface, ACK and TWI interrupt
  TWCR = (_BV(TWEA) | _BV(TWEN) | _BV(TWIE));
}
////////////////////////////////////////////////////////////////////////////////
/** clears the INT bit and sets the Start bit in the TWI control register. */
void at_twi_setSTA() {
  TWCR = (_BV(TWINT) | _BV(TWSTA) | _BV(TWEN) | _BV(TWIE));
}

/** clears the INT bit and sets the Stop bit in the TWI control register. */
void at_twi_setSTO() {
  TWCR = (_BV(TWINT) | _BV(TWSTO) | _BV(TWEN) | _BV(TWIE));
}

/** clears the INT bit and sets or clears the Acnowledge bit in the TWI control register. */
void at_twi_setACK(uint8_t ack) {
  if(ack) {
    TWCR = (_BV(TWINT) | _BV(TWEA) | _BV(TWEN) | _BV(TWIE));
  }
  else {
    TWCR = (_BV(TWINT) | _BV(TWEN) | _BV(TWIE));
  }
}
////////////////////////////////////////////////////////////////////////////////
/**
 * sets the Write bit for the transfer and initiates Start condition on bus.
 */
void at_twi_masterWrite(uint8_t addr, uint8_t opt) {
  while(at_twi_state != AT_TWI_STATE_MASTER_IDLE) {
    //if there's already a TX in progress wait
  }
  at_twi_state = AT_TWI_STATE_MASTER_TX;
  at_twi_sla = (addr & 0xFE); //set write bit
  at_twi_txopt = opt;
  at_twi_setSTA();
}

/**
 * sets the Read bit for the transfer, writes the slave address as the first byte of the RX buffer and
 * sets the RX buffer index to 1, then initiates Start condition on bus.
 */
void at_twi_masterRead(uint8_t addr, uint8_t len, uint8_t opt) {
  while(at_twi_state != AT_TWI_STATE_MASTER_IDLE) {
    //if there's already a TX in progress wait
  }
  at_twi_state = AT_TWI_STATE_MASTER_RX;
  at_twi_sla = (addr | 0x01); //set read bit
  at_twi_rxBufferSize = len;
  at_twi_txopt = opt;
  at_twi_rxBuffer[0] = addr;
  at_twi_rxBufferIdx = 1;
  at_twi_setSTA();
}
////////////////////////////////////////////////////////////////////////////////
uint8_t at_twi_get_TW_STATUS(){
  return TW_STATUS;
}

/** returns the internal state of this TWI sw. */
uint8_t at_twi_getState() {
  return at_twi_state;
}
////////////////////////////////////////////////////////////////////////////////
/**
 * interrupt handler.
 */
ISR(TWI_vect) {
  at_twi_status = TW_STATUS;
  switch(TW_STATUS) {
    case TW_REP_START: // sent repeated start condition
    case TW_START:     // sent start condition
      TWDR = at_twi_sla;
      at_twi_txBufferIdx = 0;
      at_twi_setACK(0);
      break;
    case TW_NO_INFO:   // no state information
    case TW_BUS_ERROR: // bus error, illegal stop/start
      at_twi_onTX(TW_STATUS);
      break;

    // master transmit
    case TW_MT_SLA_ACK:  // slave receiver acked address
    case TW_MT_DATA_ACK: // slave receiver acked data
      if(at_twi_txBufferIdx < at_twi_txBufferSize) {
        TWDR = at_twi_txBuffer[at_twi_txBufferIdx++];
        at_twi_setACK(0);
      }
      else {
        if(at_twi_txopt != AT_TWI_TXOPT_NOSTOP) {
          at_twi_setSTO();
          at_twi_state = AT_TWI_STATE_MASTER_IDLE;
          at_twi_onTX(at_twi_status);
        }
      }
      break;
    case TW_MT_SLA_NACK:  // address sent, nack received
    case TW_MT_DATA_NACK: // data sent, nack received
      at_twi_setSTO();
      at_twi_state = AT_TWI_STATE_MASTER_IDLE;
      at_twi_onTX(at_twi_status);
      break;
    case TW_MT_ARB_LOST: // lost bus arbitration
      at_twi_setACK(1);
      at_twi_state = AT_TWI_STATE_MASTER_IDLE;
      at_twi_onTX(at_twi_status);
      break;

    // master receive
    case TW_MR_DATA_ACK: // data received, ack sent
      at_twi_rxBuffer[at_twi_rxBufferIdx++] = TWDR;
    case TW_MR_SLA_ACK:  // address sent, ack received
      if(at_twi_rxBufferIdx < at_twi_rxBufferSize) {
        at_twi_setACK(1);
      }
      else {
        at_twi_setACK(0);
      }
      break;
    case TW_MR_DATA_NACK: // data received, nack sent
      at_twi_rxBuffer[at_twi_rxBufferIdx++] = TWDR;
    case TW_MR_SLA_NACK: // address sent, nack received
      at_twi_setSTO();
      at_twi_state = AT_TWI_STATE_MASTER_IDLE;
      at_twi_onRX(at_twi_rxBuffer, at_twi_rxBufferIdx);
      break;
    // TW_MR_ARB_LOST = TW_MT_ARB_LOST

    // slave receive
    case TW_SR_SLA_ACK:   // addressed, returned ack
    case TW_SR_GCALL_ACK: // addressed generally, returned ack
    case TW_SR_ARB_LOST_SLA_ACK:   // lost arbitration, returned ack
    case TW_SR_ARB_LOST_GCALL_ACK: // lost arbitration, returned ack
      at_twi_state = AT_TWI_STATE_SLAVE_RX;
      at_twi_rxBuffer[0] = TWDR;
      at_twi_rxBufferIdx = 1;
      at_twi_setACK(1);
      break;
    case TW_SR_DATA_ACK:       // data received, returned ack
    case TW_SR_GCALL_DATA_ACK: // data received generally, returned ack
      if(at_twi_rxBufferIdx < at_twi_rxBufferSize) {
        at_twi_rxBuffer[at_twi_rxBufferIdx++] = TWDR;
        at_twi_setACK(1);
      }
      else {
        at_twi_setACK(0);
      }
      break;
    case TW_SR_DATA_NACK:       // data received, returned nack
    case TW_SR_GCALL_DATA_NACK: // data received generally, returned nack
      if(at_twi_rxBufferIdx < at_twi_rxBufferSize) {
        at_twi_rxBuffer[at_twi_rxBufferIdx++] = TWDR;
      }
      at_twi_setACK(0);
      break;
    case TW_SR_STOP: // stop or repeated start condition received
      at_twi_setACK(1);
      at_twi_state = AT_TWI_STATE_SLAVE_IDLE;
      at_twi_onRX(at_twi_rxBuffer, at_twi_rxBufferIdx);
      break;

    // slave transmit
    case TW_ST_SLA_ACK:          // addressed, returned ack
    case TW_ST_ARB_LOST_SLA_ACK: // arbitration lost, returned ack
      at_twi_state = AT_TWI_STATE_SLAVE_TX;
      at_twi_txBufferIdx = 0;
    case TW_ST_DATA_ACK: // data transmitted, ACK received
      TWDR = at_twi_txBuffer[at_twi_txBufferIdx++];
      if(at_twi_txBufferIdx < at_twi_txBufferSize) {
        at_twi_setACK(1);
      }
      else {
        at_twi_setACK(0);
      }
      break;
    case TW_ST_DATA_NACK: // data transmitted, NACK received
    case TW_ST_LAST_DATA: // last data byte transmitted, ACK received
      at_twi_setACK(1);
      at_twi_state = AT_TWI_STATE_SLAVE_IDLE;
      at_twi_onTX(at_twi_status);
      break;
  }
}
////////////////////////////////////////////////////////////////////////////////