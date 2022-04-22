#ifndef RSXSTEPPERMOTOR_H
#define RSXSTEPPERMOTOR_H

// Configuration for the Stepper Motor
#define STEP_PIN 3
#define DIR_PIN 2
// End configuration for the Stepper Motor

class RSXMotor
{
private:
  int _step_pin;
  int _dir_pin;
  int _spin_delay;

public:
  RSXMotor(int spin_delay = 700);
  RSXMotor(int step_pin, int dir_pin, int spin_delay = 700);
  void run_motor(int step_num, bool spin_clockwise = true);
};

#endif
