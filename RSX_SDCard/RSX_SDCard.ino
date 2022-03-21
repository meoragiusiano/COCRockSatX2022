#include "conf.h"
#include "RSXSDCard.h"

int i = 0;

void setup()
{

  Serial.begin(9600);

  // see if the card is present and can be initialized:
  if (!rsx_sd_begin())
  {
    while (1)
    {
    }
  }
}

void loop()
{
  String dataString = "Data value: ";
  dataString += String(i);

  // open the file.
  rsx_sd_log(dataString);
  i++;
  delay(100); // run at a reasonable not-too-fast speed
}
