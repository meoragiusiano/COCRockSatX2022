#include "conf.h"
#include "RSXStepperMotor.h"
//Make sure you download these files plus RSXRadio.cpp for this to work


RSXMotor motor = RSXMotor(step_pin, dir_pin);

void setup()
{
}

void loop()
{
  motor.run_motor(1000);
  delay(1000);
}
