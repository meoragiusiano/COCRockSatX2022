#include "conf.h"
#include <SD.h>
#include <SPI.h>
#include "arduino.h"
#include "RSXSDCard.h"

bool rsx_sd_begin()
{
  return SD.begin(chipSelect);
}

void rsx_sd_log(String message)
{
  File dataFile = SD.open("datalog.txt", FILE_WRITE);
  if (dataFile)
  {
    dataFile.println(message);
    dataFile.close();
  }
}
