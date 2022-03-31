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
  RSXRADIO_SERIAL.available();
}
