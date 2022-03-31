#ifndef RSXRADIO_H
#define RSXRADIO_H

#include "arduino.h"


class RSXRadio
{
  private:
    String _message;

  public:
    RSXRadio(long);
    String read();
    void write(String message);
    void write(long message);
    void send_message();
    long available();
};

#endif