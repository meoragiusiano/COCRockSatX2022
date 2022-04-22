#include "util.h"
#include "arduino.h"

void begin_temp_message(String &message)
{
  message.reserve(TEMP_MESSAGE_BUFFER);
}

void log_time_stamp(String &temp)
{
  temp.concat("ts:");
  temp.concat(micros() / 1000);
  temp.concat('\n');
}

// void begin_messages(String &sd_message, String &temp_message)
// {
//   sd_message.reserve(SD_MESSAGE_BUFFER);
//   temp_message.reserve(100);
// }

// void begin_messages(String &sd_message, String &temp_message, String &radio_message)
// {
//   sd_message.reserve(SD_MESSAGE_BUFFER);
//   temp_message.reserve(100);
//   radio_message.reserve(RADIO_MESSAGE_BUFFER);
// }
