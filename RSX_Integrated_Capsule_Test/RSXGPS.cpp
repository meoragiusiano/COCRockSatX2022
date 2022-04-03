#include "conf.h"
#include "RSXGPS.h"

void gps_begin()
{
  RSXGPS_SERIAL.begin(9600);
  RSXGPS_SERIAL.setTimeout(GPS_TIMEOUT);
}

String get_gpgga()
{
  String gps = Serial7.readStringUntil('\n');
  if (!gps.startsWith("$GPGGA"))
  {
    return "";
  }
  return "gps:" + gps.concat('\n');
}
