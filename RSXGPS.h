#ifndef RSXGPS_H
#define RSXGPS_H

#include "arduino.h"

// Configuration for the GPS
#define GPS_SERIAL Serial7
#define GPS_TIMEOUT 9
// End configuration for the GPS

void gps_begin();
String get_gpgga();

#endif
