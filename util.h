#ifndef RSXUTIL_H
#define RSXUTIL_H

#include "arduino.h"

// Configuration for utils
#define TEMP_MESSAGE_BUFFER 200
// End configuration for utils

void begin_temp_message(String &);
void log_time_stamp(String &);
// void begin_messages(String &, String &);
// void begin_messages(String &, String &, String &);

#endif
