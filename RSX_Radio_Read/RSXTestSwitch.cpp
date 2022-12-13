#include "RSXTestSwitch.h"
#include "arduino.h"

bool check_test_mode()
{
  pinMode(TEST_PIN_OUT, OUTPUT);
  pinMode(TEST_PIN_IN, INPUT);
  digitalWrite(TEST_PIN_OUT, HIGH);
  bool is_test_mode = (digitalRead(TEST_PIN_IN) == HIGH);
  digitalWrite(TEST_PIN_OUT, LOW);
  return is_test_mode;
}
