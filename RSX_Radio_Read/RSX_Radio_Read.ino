#include "RSXRadio.h"
#include "conf.h"
//Make sure you download these files plus RSXRadio.cpp for this to work

RSXRadio rsxradio(BPS);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
}

void serialEvent8() {
  Serial.print(rsxradio.read());
}
