#ifndef RSXSTEPPERMOTOR_H
#define RSXSTEPPERMOTOR_H

// Configuration for the Stepper Motor
#define STEP_PIN 22
#define DIR_PIN 23
#define DEFAULT_SPIN_DELAY 900

// End configuration for the Stepper Motor

class RSXMotor
{
  private:
    int _step_pin;
    int _dir_pin;
    int _spin_delay;

  public:
    RSXMotor(int spin_delay = DEFAULT_SPIN_DELAY);
    RSXMotor(int step_pin, int dir_pin, int spin_delay = DEFAULT_SPIN_DELAY);
    void run_motor(int step_num, bool spin_clockwise = true);
};

void limit_switch_interrupt();


#endif
