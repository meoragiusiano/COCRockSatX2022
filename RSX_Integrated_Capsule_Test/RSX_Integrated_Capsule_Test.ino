#include "util.h"
#include "RSXRadio.h"
#include "RSXSDCard.h"
#include "RSXIMU.h"
#include "RSXGPS.h"

String sd_message;
String temp_message;
int message_count = 0;
bool test = false;
bool ser = true;

void setup()
{
  radio_begin();
  while (!radio_available())
    ;
  radio_read() == "1" ? test = true : test = false;
  radio_send_message("2");
  delay(10000);

  gps_begin();
  imu_begin();
  if (ser)
    Serial.begin(9600);

  if (!test && !sd_begin(sd_message) && ser)
    Serial.println("SD card failed");
    else Serial.println("bruh");
  begin_temp_message(temp_message);
  if (ser)
    Serial.println("System start");
}

void loop()
{
  imu_request_corrected_data();

  while (!imu_available());
  temp_message.concat(imu_read_data());
  temp_message.concat(get_gpgga());
  temp_message.concat(log_time_stamp());

  sd_message.concat(temp_message);

  radio_send_message(temp_message);

  if (is_batch_met(message_count))
  {

    if (!sd_log(sd_message) && ser)
    {
      Serial.println("Failed to write");
    }
    else
    {
      clear_sd_message(message_count, sd_message);
    }
  }
  if (ser)
    Serial.print(temp_message);
  temp_message = "";
  delay(5);
}
