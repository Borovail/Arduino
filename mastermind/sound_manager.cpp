#include <Arduino.h>

#include "sound_manager.h"
#include "log_wrapper.h"

int melody[] = {
    NOTE_C3, NOTE_G2, NOTE_C2};

int noteDurations[] = {
    6, 6, 3};

void play_losing_sound()
{
  for (int thisNote = 0; thisNote < 3; thisNote++)
  {
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(PIEZO_PIN, melody[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 3;
    delay(pauseBetweenNotes);
    noTone(PIEZO_PIN);
  }
}

void setup_piezo()
{
  pinMode(PIEZO_PIN, OUTPUT);

  Log.notice("Piezo setup");
}
