#ifndef SOUND_MANAGER_H
#define SOUND_MANAGER_H

#define PIEZO_PIN A0

#define NOTE_C3 131
#define NOTE_G2 98
#define NOTE_C2 65

/**
 * Plays a sound when the player loses
 */
void play_losing_sound();

/**
 * Sets up the piezo pin
 */
void setup_piezo();

#endif // SOUND_MANAGER_H