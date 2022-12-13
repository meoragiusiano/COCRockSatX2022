#ifndef RSXSDCARD_H
#define RSXSDCARD_H

#include "arduino.h"

// Configuration for th SDCard
// declare a global {String message = "";} and set buffer using {message.reserve(message_buffer);}.
// NOTE: use {message.concat();} to add data to the buffer.
#define SD_MESSAGE_BUFFER 10000
#define SD_CHIP_SELECT 10
#define SD_BATCH_SIZE 50

// End configuration for the SDCard

bool sd_begin();
bool sd_begin(String &);
bool is_batch_met(int &);
bool sd_log(String &);
void clear_sd_message(int &, String &);

#endif
