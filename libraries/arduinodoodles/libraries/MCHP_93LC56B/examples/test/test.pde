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
#include <SPI.h>
////////////////////////////////////////////////////////////////////////////////
const long DEFAULT_RS232_RATE = 19200L;

const char *APP_PROMPT = "93LC56B EEPROM demo";

const int pinCS = 10;
const int MAX_ADDR = 128;

MCHP_93LC56B eeprom1 = MCHP_93LC56B(pinCS);
////////////////////////////////////////////////////////////////////////////////
void setup() {
  Serial.begin(DEFAULT_RS232_RATE);
  //Serial.println(APP_PROMPT);
}
////////////////////////////////////////////////////////////////////////////////
void readAll() {
  word res;

  Serial.println(APP_PROMPT);
  for(byte i = 0; i < MAX_ADDR/4; i++) {
    Serial.print("0x");
    Serial.print(4*i, HEX);
    Serial.print(": ");

    res = eeprom1.read(4*i);
    Serial.print(res, HEX);
    Serial.print(" ");
    res = eeprom1.read(4*i + 1);
    Serial.print(res, HEX);
    Serial.print(" ");
    res = eeprom1.read(4*i + 2);
    Serial.print(res, HEX);
    Serial.print(" ");
    res = eeprom1.read(4*i + 3);
    Serial.print(res, HEX);
    Serial.print(" ");
    Serial.println();
  }
}
////////////////////////////////////////////////////////////////////////////////
void writeAll() {
  int tmp = lowByte(random(255)) << 8;

  for(byte i = 0; i < MAX_ADDR; i++) {
    eeprom1.write(byte(i), (tmp + i));
  }
}
////////////////////////////////////////////////////////////////////////////////
void eraseSome() {
  eeprom1.erase(0x01);
  eeprom1.erase(0x03);
  eeprom1.erase(0x05);
  eeprom1.erase(0x07);
}
////////////////////////////////////////////////////////////////////////////////
void loop() {
  writeAll();
  readAll();
  delay(4000);

  eraseSome();
  readAll();
  delay(4000);

  eeprom1.eral();
  readAll();
  delay(4000);

  eeprom1.wral(0xABCD);
  readAll();
  delay(4000);

  eeprom1.ewds();
  eeprom1.wral(0x4567);
  readAll();
  delay(4000);

  eeprom1.ewen();
  eeprom1.wral(0x4567);
  readAll();
  delay(4000);

  while(1) {} //pause program
}
////////////////////////////////////////////////////////////////////////////////