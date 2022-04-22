#include "RSXIMU.h"
#include "arduino.h"

void imu_begin()
{
  IMU_SERIAL.begin(IMU_BAUD);
  IMU_SERIAL.setTimeout(IMU_TIMEOUT);
}

void imu_request_corrected_data()
{
  IMU_SERIAL.write(CORRECTED_DATA_CMD);
}

String imu_read_data()
{
  return "imu:" + IMU_SERIAL.readStringUntil('\n').concat("\n");
}

long imu_available()
{
  return IMU_SERIAL.available();
}

// RSXIMU::RSXIMU(long bps)
// {
//   IMU_SERIAL.begin(bps);
//   IMU_SERIAL.setTimeout(IMU_TIMEOUT);
// }

// void RSXIMU::request_corrected_data()
// {
//   IMU_SERIAL.write(CORRECTED_DATA_CMD);
// }

// String RSXIMU::read_data()
// {
//   return IMU_SERIAL.readString();
// }

// long RSXIMU::available()
// {
//   return IMU_SERIAL.available();
// }