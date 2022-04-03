#include "RSXIMU.h"
#include "conf.h"
#include "arduino.h"

RSXIMU::RSXIMU(long bps)
{
  RSXIMU_SERIAL.begin(bps);
  RSXIMU_SERIAL.setTimeout(IMU_TIMEOUT);
}

void RSXIMU::request_corrected_data()
{
  RSXIMU_SERIAL.write(CORRECTED_DATA_CMD);
}

String RSXIMU::read_data()
{
  return RSXIMU_SERIAL.readString();
}

long RSXIMU::available()
{
  return RSXIMU_SERIAL.available();
}

void imu_begin()
{
  RSXIMU_SERIAL.begin(BPS_IMU);
  RSXIMU_SERIAL.setTimeout(IMU_TIMEOUT);
}

void imu_request_corrected_data()
{
  RSXIMU_SERIAL.write(CORRECTED_DATA_CMD);
}

String imu_read_data()
{
  return "imu:" + RSXIMU_SERIAL.readStringUntil('\n').concat("\n");
}

long imu_available()
{
  return RSXIMU_SERIAL.available();
}
