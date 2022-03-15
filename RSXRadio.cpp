#include "RSXRadio.h"
#include "conf.h"
#include "arduino.h"

RSXRadio::RSXRadio(long bps)
{
  RSXRADIO.begin(bps);
  _message = "";
}

String RSXRadio::read()
{
  return RSXRADIO.readString();
}

void RSXRadio::write(String message)
{
  _message += message;
}

void RSXRadio::write(long message)
{
  _message += String(message);
}

void RSXRadio::send_message()
{
  RSXRADIO.println(message);
  _message = "";
}
