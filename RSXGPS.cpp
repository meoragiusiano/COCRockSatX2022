#include "RSXGPS.h"
#include "arduino.h"

void gps_begin()
{
  GPS_SERIAL.begin(9600);
  GPS_SERIAL.setTimeout(GPS_TIMEOUT);
}

String get_gpgga()
{
  String gps = GPS_SERIAL.readStringUntil('\n');
  if (!gps.startsWith("$GPGGA"))
  {
    return "";
  }
  return "gps:" + gps.concat('\n');
}
