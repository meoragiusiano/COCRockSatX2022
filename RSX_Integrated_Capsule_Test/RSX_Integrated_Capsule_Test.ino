#include "conf.h"
#include "util.h"
#include "RSXRadio.h"
#include "RSXSDCard.h"
#include "RSXIMU.h"
#include "RSXGPS.h"

String sd_message;
String temp_message;
int message_count = 0;

void setup()
{
  imu_begin();
  gps_begin();
  radio_begin();
  Serial.begin(9600);
  if (!sd_begin(sd_message))
    Serial.println("SD card failed");
  begin_temp_message(temp_message);
  Serial.println("System start");
}

void loop()
{
  imu_request_corrected_data();

  while (!imu_available())
    ;
  temp_message.concat(imu_read_data());
  temp_message.concat(get_gpgga());
  log_time_stamp(temp_message);

  sd_message.concat(temp_message);

  radio_send_message(temp_message);

  if (is_batch_met(message_count))
  {

    if (!sd_log(sd_message))
    {
      Serial.println("Failed to write");
    }
    else
    {
      clear_sd_message(message_count, sd_message);
    }
  }
  Serial.print(temp_message);
  temp_message = "";
  delay(5);
}