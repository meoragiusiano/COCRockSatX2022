#include "RSXSDCard.h"
#include "arduino.h"
#include <SD.h>

bool sd_begin(String &message)
{
  pinMode(10, OUTPUT);
  message.reserve(SD_MESSAGE_BUFFER);
  return SD.begin(SD_CHIP_SELECT);
}

bool is_batch_met(int &count)
{
  return (++count < SD_BATCH_SIZE);
}

bool sd_log(String &message)
{
  File data_file = SD.open("datalog.txt", FILE_WRITE);
  if (data_file)
  {
    data_file.print(message);
    data_file.close();
    return true;
  }
  return false;
}

void clear_sd_message(int &count, String &message)
{
  count = 0;
  message = "";
}
