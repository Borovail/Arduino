#ifndef LOG_WRAPPER_H
#define LOG_WRAPPER_H
#include <ArduinoLog.h>

/**
 * Setup logging
 * 
 * This function initializes the serial communication and sets the log level to verbose.
 */
void setup_logging();


/**
 * Clean screen
 * 
 * This function prints 50 new lines to the serial output.
 */
void clean_screen();



#endif // LOG_WRAPPER_H