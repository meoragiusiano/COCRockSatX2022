#ifndef RSXIMU_H
#define RSXIMU_H

#include "arduino.h"

class RSXIMU
{
public:
  RSXIMU(long);
  void request_corrected_data();
  String read_data();
  long available();
};

void imu_begin();
void imu_request_corrected_data();
String imu_read_data();
long imu_available();

#endif
