#ifndef RSXRADIO_H
#define RSXRADIO_H

#include "arduino.h"

// Configuration for the RFD 900+
// netID = 73;
#define RADIO_SERIAL Serial5
#define RADIO_BAUD 57600
#define RADIO_MESSAGE_BUFFER 10000
#define RADIO_TIMEOUT 1000
// End configuration for the RFD 900+

void radio_begin();
void radio_begin(String &);
String radio_read();
void radio_send_message(const String &);
long radio_available();

// do not use this class
// class RSXRadio
// {
// private:
//   String _message;

// public:
//   RSXRadio(long);
//   String read();
//   void write(String message);
//   void write(long message);
//   void send_message();
//   long available();
// };

#endif
