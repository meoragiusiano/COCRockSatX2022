#include "RSXRadio.h"
#include "arduino.h"

void radio_begin()
{
  RADIO_SERIAL.begin(RADIO_BAUD);
  RADIO_SERIAL.setTimeout(RADIO_TIMEOUT);
}

void radio_begin(String &message)
{
  message.reserve(RADIO_MESSAGE_BUFFER);
  RADIO_SERIAL.begin(RADIO_BAUD);
  RADIO_SERIAL.setTimeout(RADIO_TIMEOUT);
}

String radio_read()
{
  return RADIO_SERIAL.readString();
}

void radio_send_message(const String &message)
{
  RADIO_SERIAL.print(message);
}

long radio_available()
{
  return RADIO_SERIAL.available();
}

//// RSXRadio::RSXRadio(long bps)
//// {
////   RADIO_SERIAL.begin(bps);
////   _message = "";
////   _message.reserve(RADIO_MESSAGE_BUFFER);
//// }
//
//// String RSXRadio::read()
//// {
////   return RADIO_SERIAL.readString();
//// }
//
//// void RSXRadio::write(String message)
//// {
////   _message.concat(message);
//// }
//
//// void RSXRadio::write(long message)
//// {
////   _message.concat(message);
//// }
//
//// void RSXRadio::send_message()
//// {
////   RADIO_SERIAL.println(_message);
////   _message = "";
//// }
//
//// long RSXRadio::available()
//// {
////   return RADIO_SERIAL.available();
//// }
