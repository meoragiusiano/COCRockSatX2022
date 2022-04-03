#include "RSXRadio.h"
#include "conf.h"
#include "arduino.h"

RSXRadio::RSXRadio(long bps)
{
  RSXRADIO_SERIAL.begin(bps);
  _message = "";
  _message.reserve(RADIO_MESSAGE_BUFFER);
}

String RSXRadio::read()
{
  return RSXRADIO_SERIAL.readString();
}

void RSXRadio::write(String message)
{
  _message.concat(message);
}

void RSXRadio::write(long message)
{
  _message.concat(message);
}

void RSXRadio::send_message()
{
  RSXRADIO_SERIAL.println(_message);
  _message = "";
}

long RSXRadio::available()
{
  return RSXRADIO_SERIAL.available();
}

void radio_begin()
{
  RSXRADIO_SERIAL.begin(RADIO_BPS);
  RSXRADIO_SERIAL.setTimeout(RADIO_TIMEOUT);
}

String radio_read()
{
  return RSXRADIO_SERIAL.readString();
}

void radio_send_message(const String &message)
{

  RSXRADIO_SERIAL.print(message);
}

long radio_available()
{

  return RSXRADIO_SERIAL.available();
}
