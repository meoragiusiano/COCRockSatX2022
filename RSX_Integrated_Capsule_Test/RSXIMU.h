#ifndef RSXIMU_H
#define RSXIMU_H

#include "arduino.h"


class RSXIMU
{
  public:
    RSXIMU(long);;
    void request_corrected_data();
    String read_data();
    long available();
};

#endif
