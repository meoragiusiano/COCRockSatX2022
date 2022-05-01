#ifndef RSXUTIL_H
#define RSXUTIL_H

#include "arduino.h"

// Configuration for utils
#define TEMP_MESSAGE_BUFFER 200
// End configuration for utils

void begin_temp_message(String &);
String log_time_stamp();
// void begin_messages(String &, String &);
// void begin_messages(String &, String &, String &);

#endif
