/*
This file is part of TSL230R.

TSL230R is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

TSL230R is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with TSL230R.  If not, see <http://www.gnu.org/licenses/>.
*/
////////////////////////////////////////////////////////////////////////////////
#include "TSL230R.h"

TSL230R::TSL230R(int16_t pOE, int16_t pS0, int16_t pS1, int16_t pS2, int16_t pS3) {
  pinOE = pOE;
  pinS0 = pS0;
  pinS1 = pS1;
  pinS2 = pS2;
  pinS3 = pS3;

  pinMode(pinOE, OUTPUT);
  pinMode(pinS0, OUTPUT);
  pinMode(pinS1, OUTPUT);
  pinMode(pinS2, OUTPUT);
  pinMode(pinS3, OUTPUT);

  setSensitivity(TSL230R_SENS_10x);
  setFreqScaling(TSL230R_SCALE_2);
  disableOut();
}
////////////////////////////////////////////////////////////////////////////////
void TSL230R::setSensitivity(uint8_t data) {
  if(data == TSL230R_PWR_DOWN) {
    digitalWrite(pinS0, LOW);
    digitalWrite(pinS1, LOW);
  }
  else if(data == TSL230R_SENS_1x) {
    digitalWrite(pinS0, HIGH);
    digitalWrite(pinS1, LOW);
  }
  else if(data == TSL230R_SENS_10x) {
    digitalWrite(pinS0, LOW);
    digitalWrite(pinS1, HIGH);
  }
  else if(data == TSL230R_SENS_100x) {
    digitalWrite(pinS0, HIGH);
    digitalWrite(pinS1, HIGH);
  }
  else
    return;
  sensitivity = data;
}
////////////////////////////////////////////////////////////////////////////////
void TSL230R::setFreqScaling(uint8_t data) {
  if(data == TSL230R_SCALE_1) {
    digitalWrite(pinS2, LOW);
    digitalWrite(pinS3, LOW);
  }
  else if(data == TSL230R_SCALE_2) {
    digitalWrite(pinS2, HIGH);
    digitalWrite(pinS3, LOW);
  }
  else if(data == TSL230R_SCALE_10) {
    digitalWrite(pinS2, LOW);
    digitalWrite(pinS3, HIGH);
  }
  else if(data == TSL230R_SCALE_100) {
    digitalWrite(pinS2, HIGH);
    digitalWrite(pinS3, HIGH);
  }
  else
    return;
  freqScaling = data;
}
////////////////////////////////////////////////////////////////////////////////
float TSL230R::freq2irradiance(float f) {
  float freq = 0.0;
  float Ee = 0.0;

  if(freqScaling == TSL230R_SCALE_1) {
    freq = f;
  }
  else if(freqScaling == TSL230R_SCALE_2) {
    freq = 2.0*f;
  }
  else if(freqScaling == TSL230R_SCALE_10) {
    freq = 10.0*f;
  }
  else if(freqScaling == TSL230R_SCALE_100) {
    freq = 100.0*f;
  }

  Serial.print("freq: ");
  Serial.print(freq, 4);
  Serial.print(" Hz");
  Serial.println();

/*
 * THE FOLLOWING RELATION IS APPROXIMATE
 * from datasheet (page 4, Figure 1) it looks like the line has a slope of pi/4:
 * log(Ee) = log(freq) + n
 * measuring n on graph we get:
 * log(Ee) = log(freq) + 2.155
 * log(Ee) = log(freq) + log(142.946)
 */
  Ee = 142.946*freq;

  if(sensitivity == TSL230R_SENS_10x) {
    Ee = Ee/10.0;
  }
  else if(sensitivity == TSL230R_SENS_100x) {
    Ee = Ee/100.0;
  }

  Serial.print("irradiance: ");
  Serial.print(Ee, 4);
  Serial.print(" uW/cm^2");
  Serial.println();
}
////////////////////////////////////////////////////////////////////////////////