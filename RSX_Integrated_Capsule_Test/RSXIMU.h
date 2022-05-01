#ifndef RSXIMU_H
#define RSXIMU_H

#include "arduino.h"

// Configuration for the IMU
#define IMU_SERIAL Serial3
#define IMU_BAUD 115200
#define CORRECTED_DATA_CMD ":32\n"
#define IMU_TIMEOUT 10
// End configuration for the IMU
;
void imu_begin();
void imu_request_corrected_data();
String imu_read_data();
long imu_available();

// avoid using the class
// class RSXIMU
// {
// public:
//   RSXIMU(long);
//   void request_corrected_data();
//   String read_data();
//   long available();
// };

#endif
