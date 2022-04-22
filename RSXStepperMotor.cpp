/*
Contributors:
  Svarun Soda
  Andrew Nowakowski

Important Notes:
  This software has only been tested and vairfied on the following hardware:
    Stepper Motor:
      > NEMA 17HS4401 Stepper Motor
          -----------------
          |               |> 6 Connected
          |               |> 5 Not Connected
          |       \/      |> 4 Connected
          |       /\      |> 3 Connected
          |               |> 2 Not Connected
          |               |> 1 Connected
          -----------------
    Stepper Motor Driver Module:
      > A4988 Stepper Driver Module
         Enable(NC) 1 <-----------------> 16 VMOTor(C**)
            MS1(NC) 2 <|               |> 15 GND (C**)
            MS2(NC) 3 <|   ----        |> 14 2B(C-1)
            MS3(NC) 4 <|   |  |        |> 13 2A(C-3)
            RST(C*) 5 <|   |  |        |> 12 1A(C-4)
            SLP(C*) 6 <|      _|_      |> 11 1B(C-6)
            STEP(C) 7 <|       |       |> 10 VDD(C)
             DIR(C) 8 <-----------------> 9  GND(C)
        *RST and SLP are bridged together
        **connected to 8V-35V power source with a 47microF capacitor
*/

#include "RSXStepperMotor.h"
#include "arduino.h"

RSXMotor::RSXMotor(int spin_delay)
{
  /*
  _step_pin: the pin that connects to the STEP on the stepper motor driver.
  _dir_pin: the pin that connects to the DIR on the stepper motor driver.
  _spin_delay: the delay between each step in microseconds.
  */
  _step_pin = STEP_PIN;
  _dir_pin = DIR_PIN;
  _spin_delay = spin_delay;
  pinMode(step_pin, OUTPUT);
  pinMode(dir_pin, OUTPUT);
};

RSXMotor::RSXMotor(int step_pin, int dir_pin, int spin_delay)
{
  /*
  _step_pin: the pin that connects to the STEP on the stepper motor driver.
  _dir_pin: the pin that connects to the DIR on the stepper motor driver.
  _spin_delay: the delay between each step in microseconds.
  */
  _step_pin = step_pin;
  _dir_pin = dir_pin;
  _spin_delay = spin_delay;
  pinMode(step_pin, OUTPUT);
  pinMode(dir_pin, OUTPUT);
};

void RSXMotor::run_motor(int step_num, bool spin_clockwise) // TODO: pass in limit switches to make sure motor does not run if limit is reached
{
  /*
  step_num: the number of steps to be completed by the stepper motor.
  sping_clockwise: true -> clockwise, false -> counter clockwise.
  */
  if (spin_clockwise)
  {
    digitalWrite(_dir_pin, HIGH);
  }
  else
  {
    digitalWrite(_dir_pin, LOW);
  }
  for (int i = 0; i < step_num; i++)
  {
    digitalWrite(_step_pin, HIGH);
    delayMicroseconds(_spin_delay);
    digitalWrite(_step_pin, LOW);
    delayMicroseconds(_spin_delay);
  }
}
