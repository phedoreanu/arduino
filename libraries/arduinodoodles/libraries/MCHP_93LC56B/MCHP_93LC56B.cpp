/*
This file is part of MCHP_93LC56B.

MCHP_93LC56B is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

MCHP_93LC56B is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with MCHP_93LC56B.  If not, see <http://www.gnu.org/licenses/>.
*/
////////////////////////////////////////////////////////////////////////////////
#include "MCHP_93LC56B.h"
////////////////////////////////////////////////////////////////////////////////
MCHP_93LC56B::MCHP_93LC56B(int16_t pCS) {
  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV128);
  SPI.setBitOrder(MSBFIRST);

  pinCS = pCS;
  pinMode(10, OUTPUT); // pin 10 has to be output since the SPI library suports only master mode
  if(pinCS != 10) {
    pinMode(pinCS, OUTPUT);
  }
  digitalWrite(pinCS, LOW);
}
////////////////////////////////////////////////////////////////////////////////
uint16_t MCHP_93LC56B::read(uint8_t addr) {
  uint8_t tfr[4];

  digitalWrite(pinCS, HIGH);
  //CPOL = 0; CPHA = 0
  SPI.setDataMode(SPI_MODE0);
  tfr[0] = SPI.transfer(0x06);
  tfr[1] = SPI.transfer(0x7F & addr);
  //CPOL = 0; CPHA = 1
  SPI.setDataMode(SPI_MODE1);
  tfr[2] = SPI.transfer(0x00);
  tfr[3] = SPI.transfer(0x00);
  digitalWrite(pinCS, LOW);

  uint16_t res = (word(tfr[2]) << 8) | word(tfr[3]);
  /*
  Serial.print("read: ");
  Serial.print(addr, HEX);
  Serial.print("-");
  Serial.print(res, HEX);
  Serial.println();
  */
  return res;
}
////////////////////////////////////////////////////////////////////////////////
void MCHP_93LC56B::write(uint8_t addr, uint16_t data) {
  byte hB = byte(data >> 8);
  byte lB = byte(data & 0xFF);
  /*
  Serial.print("write: ");
  Serial.print(addr, HEX);
  Serial.print("-");
  Serial.print(hB, HEX);
  Serial.print("-");
  Serial.print(lB, HEX);
  Serial.println();
  */
  digitalWrite(pinCS, HIGH);
  //CPOL = 0; CPHA = 0
  SPI.setDataMode(SPI_MODE0);
  SPI.transfer(0x05);
  SPI.transfer(0x7F & addr);
  SPI.transfer(hB);
  SPI.transfer(lB);
  digitalWrite(pinCS, LOW);

  delay(6); //** wait for TWC (program cycle time)
}
////////////////////////////////////////////////////////////////////////////////
void MCHP_93LC56B::erase(uint8_t addr) {
  digitalWrite(pinCS, HIGH);
  //CPOL = 0; CPHA = 0
  SPI.setDataMode(SPI_MODE0);
  SPI.transfer(0x07);
  SPI.transfer(0x7F & addr);
  digitalWrite(pinCS, LOW);

  delay(6); //** wait for TWC (program cycle time)
}
////////////////////////////////////////////////////////////////////////////////
void MCHP_93LC56B::eral() {
  digitalWrite(pinCS, HIGH);
  //CPOL = 0; CPHA = 0
  SPI.setDataMode(SPI_MODE0);
  SPI.transfer(0x04);
  SPI.transfer(0x80);
  digitalWrite(pinCS, LOW);

  delay(6); //** wait for TEC (program cycle time)
}
////////////////////////////////////////////////////////////////////////////////
void MCHP_93LC56B::wral(uint16_t data) {
  byte hB = byte(data >> 8);
  byte lB = byte(data & 0xFF);

  digitalWrite(pinCS, HIGH);
  //CPOL = 0; CPHA = 0
  SPI.setDataMode(SPI_MODE0);
  SPI.transfer(0x04);
  SPI.transfer(0x40);
  SPI.transfer(hB);
  SPI.transfer(lB);
  digitalWrite(pinCS, LOW);

  delay(15); //** wait for TWL (program cycle time)
}
////////////////////////////////////////////////////////////////////////////////
void MCHP_93LC56B::ewds() {
  digitalWrite(pinCS, HIGH);
  //CPOL = 0; CPHA = 0
  SPI.setDataMode(SPI_MODE0);
  SPI.transfer(0x04);
  SPI.transfer(0x00);
  digitalWrite(pinCS, LOW);

  delay(1); //** wait for TCSL
}
////////////////////////////////////////////////////////////////////////////////
void MCHP_93LC56B::ewen() {
  digitalWrite(pinCS, HIGH);
  //CPOL = 0; CPHA = 0
  SPI.setDataMode(SPI_MODE0);
  SPI.transfer(0x04);
  SPI.transfer(0xC0);
  digitalWrite(pinCS, LOW);

  delay(1); //** wait for TCSL
}
////////////////////////////////////////////////////////////////////////////////