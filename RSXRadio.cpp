#include "RSXRadio.h"
#include "conf.h"
#include "arduino.h"


RSXRadio::RSXRadio(long bps) {
  RSXRADIO.begin(bps);
  message = "";
}

String RSXRadio::read() {
  return RSXRADIO.readString();
}

void RSXRadio::write(String message) {
  this->message += message;
}

void RSXRadio::send_message() {
  RSXRADIO.println(message);
  this->message = "";
}
