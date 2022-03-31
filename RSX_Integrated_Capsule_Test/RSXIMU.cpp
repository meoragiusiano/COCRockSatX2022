#include "RSXIMU.h"
#include "conf.h"
#include "arduino.h"
#include <SoftwareSerial.h>


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
