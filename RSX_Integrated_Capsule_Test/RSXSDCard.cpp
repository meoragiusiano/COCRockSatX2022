#include "conf.h"
#include <SD.h>
#include "arduino.h"
#include "RSXSDCard.h"

bool rsx_sd_begin()
{
  pinMode(10, OUTPUT);
  return SD.begin(SD_CHIP_SELECT);
}

bool is_batch_met(int &count, const int batch_size)
{
  if (count++ < batch_size)
  {
    return false;
  }
  return true;
}

bool rsx_sd_log(String &message, int &count)
{
  File data_file = SD.open("datalog.txt", FILE_WRITE);
  if (data_file)
  {
    data_file.print(message);
    data_file.close();
    message = "";
    count = 0;
    return true;
  }
  return false;
}
