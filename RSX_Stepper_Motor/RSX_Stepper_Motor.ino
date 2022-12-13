#include "conf.h"
#include "RSXStepperMotor.h"
//Make sure you download these files plus RSXRadio.cpp for this to work


RSXMotor motor = RSXMotor(step_pin, dir_pin);

void setup()
{
  pinMode(20, OUTPUT);
  digitalWrite(20, HIGH);
  pinMode(21, INPUT);
  attachInterrupt(21, LimitSwitchInt, RISING);
}

void loop()
{
  motor.run_motor(1000, true);
}

void LimitSwitchInt() {
  delay(1000);
  motor.run_motor(1000, false);
  delay(1000);
}
