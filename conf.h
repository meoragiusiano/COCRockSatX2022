#pragma once
#include "arduino.h"

// Configuration for the RFD 900+
// netID = 73;
#define RSXRADIO Serial8
const long BPS = 57600;
// End configuration for the RFD 900+

// Configuration for the Stepper Motor
const int step_pin = 3;
const int dir_pin = 2;
// End configuration for the Stepper Motor

// Configuration for th SDCard
#define chipSelect BUILTIN_SDCARD
// End configuration for the SDCard
