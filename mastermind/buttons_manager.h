#ifndef BUTTON_MANAGER_H
#define BUTTON_MANAGER_H

#define VRX_PIN A1
#define VRY_PIN A2
#define BTN_ENTER_PIN A3

#define BTN_1_PIN 10
#define BTN_2_PIN 11
#define BTN_3_PIN 12
#define BTN_4_PIN 13

#define DEBAUNCE_DELAY 200

/**
 * Initializes buttons
 *
 * Sets the pins for the buttons as input.
 * Sets the pin for the enter button as input with pull-up resistor (INPUT_PULLUP).
 */
void setup_buttons();

/**
 * Checks if the button is pressed
 *
 * Checks if the button is pressed and returns true if it is.
 * @param button_state state of the button
 * @return bool true if the button is pressed, false otherwise
 */
bool button_pressed(int button_state);

/**
 * Checks if the joystick is moved up
 *
 * Checks if the joystick is moved up and returns true if it is.
 * @return bool true if the joystick is moved up, false otherwise
 */
bool joystick_up();

/**
 * Checks if the joystick is moved down
 *
 * Checks if the joystick is moved down and returns true if it is.
 * @return bool true if the joystick is moved down, false otherwise
 */
bool joystick_down();

/**
 * Checks if the enter button is pressed
 *
 * Checks if the enter button is pressed and returns true if it is.
 * @return bool true if the enter button is pressed, false otherwise
 */
bool enter_pressed();

/**
 * Reads the state of the buttons
 *
 * Checks the state of the buttons and returns a value based on the pressed button:
 * - Returns 1 if the button connected to BTN_1_PIN is pressed.
 * - Returns 2 if the button connected to BTN_2_PIN is pressed.
 * - Returns 3 if the button connected to BTN_3_PIN is pressed.
 * - Returns 4 if the button connected to BTN_4_PIN is pressed.
 * - Returns -1 if none of the buttons are pressed.
 *
 * @return int Value of the pressed button or -1 if none of the buttons are pressed.
 */
int read_button();

#endif // BUTTON_MANAGER_H