#ifndef LEDS_MANAGER_H
#define LEDS_MANAGER_H

#define LED_RED_1 2
#define LED_BLUE_1 3
#define LED_RED_2 4
#define LED_BLUE_2 5
#define LED_RED_3 6
#define LED_BLUE_3 7
#define LED_RED_4 8
#define LED_BLUE_4 9

#define ANIMATION_SPEED_DELAY 200

/**
 * Set up the LEDs
 *
 * Sets up the LEDs for the game. The function should be called only once at the beginning of the game.
 */
void setup_leds();

/**
 * Turns on all LEDs.
 */
void turn_on_leds();

/**
 * Turns off all LEDs.
 */
void turn_off_leds();

/**
 * Plays the winning lights animation.
 */
void play_winning_lights();

/**
 * Render the LEDs
 *
 * Renders the LEDs based on the given pegs.
 * @param peg_a the number of pegs A
 * @param peg_b the number of pegs B
 */
void render_leds(const int peg_a, const int peg_b);

#endif // LEDS_MANAGER_H
