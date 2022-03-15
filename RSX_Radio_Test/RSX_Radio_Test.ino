#include "RSXRadio.h"
#include "conf.h"
//Make sure you download these files plus RSXRadio.cpp for this to work


RSXRadio rsxradio(BPS);

void setup() {
  // put your setup code here, to run once:
  RSXRADIO.begin(57600);
}

void loop() {
  // put your main code here, to run repeatedly:
  rsxradio.write("This is going to a be a longer string");
  rsxradio.write("that might represent a large block of data");
  rsxradio.write("being transfered. Oh, and millis: ");
  rsxradio.write(String(micros()));
  rsxradio.send_message();
  delay(1000);
}
// uno
