/*
This file is part of DHT11.

DHT11 is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

DHT11 is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with DHT11.  If not, see <http://www.gnu.org/licenses/>.
*/
////////////////////////////////////////////////////////////////////////////////
#include <DHT11.h>
////////////////////////////////////////////////////////////////////////////////
const long DEFAULT_RS232_RATE = 19200L;

const char *APP_PROMPT = "DHT11 demo";

const int pinOWIRE = 9;
////////////////////////////////////////////////////////////////////////////////
void setup() {
  Serial.begin(DEFAULT_RS232_RATE);
  Serial.println(APP_PROMPT);

  DHT11.setPin(pinOWIRE);
}
////////////////////////////////////////////////////////////////////////////////
void loop() {
  int res = DHT11.read();
  if(res != 0) {
    Serial.print("read error: ");
    Serial.println(res, DEC);
  }
  else {
    Serial.print("temperature: ");
    Serial.println(DHT11.temp, DEC);
    Serial.print("humidity   : ");
    Serial.println(DHT11.rh, DEC);
  }
  delay(4000);
}
////////////////////////////////////////////////////////////////////////////////