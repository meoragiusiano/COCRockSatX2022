#include "conf.h"
#include "RSXRadio.h"
#include"RSXSDCard.h"
#include "RSXIMU.h"
#include "RSXGPS.h"


String message;
String temp;
int message_count = 0;
RSXRadio radio(RADIO_BPS);
RSXIMU imu(BPS_IMU);


void setup() {
  gps_begin();
  Serial.begin(9600);
  if (!rsx_sd_begin()) Serial.println("SD card failed");
  message.reserve(SD_MESSAGE_BUFFER);
  temp.reserve(100);
  Serial.println("System start");
}

void loop() {
  imu.request_corrected_data();

  while (!imu.available());
  temp.concat(imu.read_data());
  temp.concat(get_gpgga());

  message.concat(temp);
  radio.write(temp);

  if (is_batch_met(message_count, BATCH_SIZE)) {
    radio.send_message();
    if (!rsx_sd_log(message, message_count)) {
      Serial.println("Failed to write");
    }
  }
  Serial.print(temp);
  temp = "";
}
