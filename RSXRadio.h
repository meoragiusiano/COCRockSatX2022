#pragma once
#include "arduino.h"


class RSXRadio {
  private:
    String message;
  public:
    RSXRadio(long);
    String read();
    void write(String message);
    void send_message();
};
