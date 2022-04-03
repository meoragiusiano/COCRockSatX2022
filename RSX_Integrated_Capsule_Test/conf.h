#ifndef CONF_H
#define CONF_H

#include "arduino.h"

// Configuration for the RFD 900+
// netID = 73;
#define RSXRADIO_SERIAL Serial5
#define RADIO_BPS 57600
#define RADIO_MESSAGE_BUFFER 10000
#define RADIO_TIMEOUT 1000
// End configuration for the RFD 900+

// Configuration for the Stepper Motor
#define step_pin 3
#define dir_pin 2
// End configuration for the Stepper Motor

// Configuration for th SDCard
// declare a global {String message = "";} and set buffer using {message.reserve(message_buffer);}.
// NOTE: use {message.concat();} to add data to the buffer.
#define SD_MESSAGE_BUFFER 10000
#define SD_CHIP_SELECT BUILTIN_SDCARD
#define BATCH_SIZE 50
// End configuration for the SDCard

// Configuration for the IMU
#define RSXIMU_SERIAL Serial8
#define BPS_IMU 115200
#define CORRECTED_DATA_CMD ":32\n"
#define IMU_TIMEOUT 10
// End configuration for the IMU

// Configuration for the GPS
#define RSXGPS_SERIAL Serial7
#define GPS_TIMEOUT 9
// End configuration for the GPS

#endif
