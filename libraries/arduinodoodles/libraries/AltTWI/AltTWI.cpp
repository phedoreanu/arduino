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
#include "AltTWI.h"

extern "C" {
  #include "at_twi.h"
}

/** pointer to user defined RX callback function */
void (*AltTWIClass::userRXCallback) (uint8_t*, int16_t);
/** pointer to user defined TX callback function */
void (*AltTWIClass::userTXCallback) (uint8_t);

/** constructor for TWI (Two Wire Interface) class */
AltTWIClass::AltTWIClass() {
  at_twi_attachRXCallback(onRX);
  at_twi_attachTXCallback(onTX);

  char res = at_twi_setBuffers();

  if(res != 0) {
    Serial.println("cannot allocate TWI buffers");
    return;
  }
}
////////////////////////////////////////////////////////////////////////////////
/**
 * Initializes TWI as master.
 *
 * @param f - TWI frequency
 *  - 400 (kHz)
 *  - 100 (kHz, the default value)
 */
void AltTWIClass::init(uint32_t f) {
  switch(f) {
    case 400:
      at_twi_setRate(400000L, 1);
      break;
    default: // set to 100kHz
      at_twi_setRate(100000L, 1);
      break;
  }
  at_twi_setMaster();
}

/**
 * Initializes TWI as slave.
 *
 * @param f - TWI frequency (100 kHz or 400 kHz)
 * @param slAddr - TWI slave address
 * @param slAddrMsk - TWI slave address mask
 */
void AltTWIClass::init(uint32_t f, uint8_t slAddr, uint8_t slAddrMsk) {
  switch(f) {
    case 400:
      at_twi_setRate(400000L, 1);
      break;
    default: // set to 100kHz
      at_twi_setRate(100000L, 1);
      break;
  }
  // TWAR must have last bit 0 to disable General Call
  at_twi_setSlaveAddr((slAddr & 0xF7), slAddrMsk);
  at_twi_setSlave();
}

/**
 * Initializes TWI as slave.
 *
 * @param f - TWI frequency (100 kHz or 400 kHz)
 * @param slAddr - TWI slave address
 */
void AltTWIClass::init(uint32_t f, uint8_t slAddr) {
  init(f, slAddr, 0x00);
}
////////////////////////////////////////////////////////////////////////////////
/**
 * Sets a user defined callback function for TX.<br />
 * This function will be called when TWI TX is finished.<br />
 * The parameter is 0 if TX was succesful or TW_STATUS if not.
 *
 * @see TW_STATUS (http://www.nongnu.org/avr-libc/user-manual/group__util__twi.html)
 */
void AltTWIClass::setTXCallback(void (*function) (uint8_t)) {
  userTXCallback = function;
}

/**
 * Sets a user defined callback function for RX.<br />
 * This function will be called when TWI RX is finished.<br />
 * The parameters are:
 *  - pointer to the received byte array
 *  - length of the received message
 */
void AltTWIClass::setRXCallback(void (*function) (uint8_t*, int16_t)) {
  userRXCallback = function;
}
////////////////////////////////////////////////////////////////////////////////
/**
 * Set message to send to TWI master.
 * The master decides when to start the transfer and read the message.
 *
 * @param *data - byte array with message
 * @param len - message length (<= number of bytes in *data)
 * @param opt - additional options: not used
 */
void AltTWIClass::sendToMaster(uint8_t *data, int16_t len, uint8_t opt) {
  if(len < AT_TWI_TX_BUFFER_SIZE) {
    at_twi_setTXBuffer(data, len);
  }
}
////////////////////////////////////////////////////////////////////////////////
/**
 * Send message to TWI slave.
 *
 * @param addr - TWI slave address
 * @param *data - byte array with message
 * @param len - message length (<= number of bytes in *data)
 * @param opt - additional options:
 *  - 0 none
 *  - 1 restart (do no send STOP condition on bus)
 */
void AltTWIClass::sendToSlave(uint8_t addr, uint8_t *data, int16_t len, uint8_t opt) {
  if(len < AT_TWI_TX_BUFFER_SIZE) {
    at_twi_setTXBuffer(data, len);
    at_twi_masterWrite(addr, opt);
  }
}
////////////////////////////////////////////////////////////////////////////////
/**
 * Get message from TWI slave.
 *
 * @param addr - TWI slave address
 * @param len - message length (you have to know how many bytes you want to get)
 * @param opt - additional options: not used
 */
void AltTWIClass::getFromSlave(uint8_t addr, int16_t len, uint8_t opt) {
  if((len + 1) < AT_TWI_RX_BUFFER_SIZE) {
    at_twi_masterRead(addr, (len + 1), opt);
  }
}
////////////////////////////////////////////////////////////////////////////////
/** Default TX callback function. */
void AltTWIClass::onTX(uint8_t status) {
  if(userTXCallback == NULL) {
    Serial.print("TX: ");
    Serial.println(status, HEX);
  }
  else {
    //Serial.println("call user TX");
    userTXCallback(status);
  }
}

/** Default RX callback function. */
void AltTWIClass::onRX(uint8_t* data, int16_t len) {
  if(userRXCallback == NULL) {
    Serial.print("RX: ");
    Serial.print(len, DEC);
    Serial.println(" byte(s)");
    for(int i = 0; i < len; i++) {
      Serial.print("0x");
      Serial.println(data[i], HEX);
    }
  }
  else {
    //Serial.println("call user RX");
    userRXCallback(data, len);
  }
}
////////////////////////////////////////////////////////////////////////////////
/**
 * prints all internal registers of the TWI controller.
 *
 * @warning use for debug only
 */
void AltTWIClass::printAllRegs() {
  Serial.print("TWBR: ");
  Serial.println(TWBR, HEX);
  Serial.print("TWCR: ");
  Serial.println(TWCR, HEX);
  Serial.print("TWSR: ");
  Serial.println(TWSR, HEX);
  Serial.print("TWDR: ");
  Serial.println(TWDR, HEX);
  Serial.print("TWAR: ");
  Serial.println(TWAR, HEX);
  Serial.print("TWAMR: ");
  Serial.println(TWAMR, HEX);
  Serial.print("SREG: ");
  Serial.println(SREG, HEX);
}

/**
 * prints TW_STATUS.
 *
 * @warning use for debug only
 * @see TW_STATUS (http://www.nongnu.org/avr-libc/user-manual/group__util__twi.html)
 */
void AltTWIClass::printTWIStatus() {
  Serial.print("TW_STATUS: ");
  Serial.println(at_twi_get_TW_STATUS(), HEX);
}
////////////////////////////////////////////////////////////////////////////////
AltTWIClass AltTWI;