#ifndef RSXSDCARD_H
#define RSXSDCARD_H

#include "arduino.h"

bool rsx_sd_begin();
bool is_batch_met(int &, const int);
bool rsx_sd_log(String &, int &);

#endif
