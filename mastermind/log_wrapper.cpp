#include "log_wrapper.h"

void setup_logging()
{
  Serial.begin(9600);
  while (!Serial) {}
  Log.begin(LOG_LEVEL_TRACE, &Serial);
   Log.setSuffix([](Print *_logOutput, int logLevel) {
    _logOutput->println();
  });

  Log.info("Logging setup");
}

void clean_screen()
{
  for (int i = 0; i < 50; i++)
  {
    Serial.println();
  }

  Log.info("Serial monitor cleaned");
}

