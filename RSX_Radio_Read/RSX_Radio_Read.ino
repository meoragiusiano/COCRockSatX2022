#include "RSXRadio.h"
#include "RSXTestSwitch.h"
#include "RSXStepperMotor.h"
#include "RSXSDCard.h"

#define TE1_PIN 19
#define MOTOR_RUN_TIME 10000
#define NICHROME_BURN_PIN 21

RSXMotor motor = RSXMotor();

bool timing_event_triggered = false;
bool test_mode = false;
bool test_no_radio = false;
bool ejection_complete = false;
String message;

void setup()
{
  radio_begin();
  Serial.begin(9600);

  pinMode(NICHROME_BURN_PIN, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(TE1_PIN), timing_event_interrupt, RISING);


  test_mode = check_test_mode();

  if (!test_mode && sd_begin(message)) {
    Serial.println("SD begin, bruh");
  } else {Serial.println("SD no begin, bruh");}

  while (!test_no_radio && radio_read() != "2")
  {
    radio_send_message("1");
  }
}

void loop()
{
  if (radio_available())
  {
    message.concat(radio_read());
    if (!test_mode && sd_log(message)) {
      //      Serial.println("Andruwu");
    } else {
      //      Serial.println("Svaruwu");
    }
    Serial.print(message);
    message = "";
  }

  if (timing_event_triggered && !ejection_complete && !test_mode) {
    digitalWrite(NICHROME_BURN_PIN, HIGH);
    long t = millis();
    while (millis() - t < MOTOR_RUN_TIME) {
      motor.run_motor(250, false);
    }
    digitalWrite(NICHROME_BURN_PIN, LOW);


    ejection_complete = true;
  }

}

void timing_event_interrupt() {
  timing_event_triggered = true;
}
