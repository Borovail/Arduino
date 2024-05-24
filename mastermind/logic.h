#ifndef LOGIC_H
#define LOGIC_H

#define MAX_ATTEMPTS 10
#define NUMBER_QUANTITY 5

#define DEBOUNCE_DELAY 200

/**
 * Generate secret code
 *
 * Generates secret code, which consists from digits only as a string.
 * No two digits in the code combination can be same! Only if the repeat
 * parameter is set to true.
 * The length of generated code is set by the parameter length. If the given
 * parameter is less than 1, function will generate no code and returns NULL.
 * @param repeat if set to true, numbers in the generated code can repeat
 * @param length the length of the code
 * @return Pointer to the random generated code as string of given length. If length param is less than 1, return NULL.
 */
char *generate_code(bool repeat, int length);

/**
 * Returns score for the given guess
 *
 * @param secret the pointer to the secret code
 * @param guess the pointer to the current guess
 * @param peg_a output parameter to get number of As for current guess
 * @param peg_b output parameter to get number of Bs for current guess
 */
void get_score(const char *secret, const char *guess, int &peg_a, int &peg_b);

/**
 * Handle enter button pressed
 *
 * Handles the enter button pressed event. If the history mode is active,
 * the current guess is replaced with the selected guess from the history.
 * @param history the array of history guesses
 * @param history_index the pointer to the current history index
 * @param guess the pointer to the current guess
 */
void handle_enter_pressed(char *guess,const char (&history)[MAX_ATTEMPTS][NUMBER_QUANTITY], int &history_index);

/**
 * Move history up
 *
 * Moves the history index up and displays the guess from the history.
 * @param history the array of history guesses
 * @param history_index the pointer to the current history index
 */
void move_history_up(char *secret,const char (&history)[MAX_ATTEMPTS][NUMBER_QUANTITY], int &history_index,int attempts,bool &in_history_mode);

/**
 * Move history down
 *
 * Moves the history index down and displays the guess from the history.
 * @param history the array of history guesses
 * @param history_index the pointer to the current history index
 */
void move_history_down(char *secret,const char (&history)[MAX_ATTEMPTS][NUMBER_QUANTITY], int &history_index,int attempts,bool &in_history_mode);

/**
 * Update guess
 *
 * Updates the guess with the given button index.
 * @param guess the pointer to the current guess
 * @param button_index the index of the button pressed
 */
void update_guess(char *guess, int button_index);

/**
 * Display history
 *
 * Displays the history for the given entry number.
 * @param secret the pointer to the secret code
 * @param history the array of history guesses
 * @param entry_nr the entry number in the history
 */
void render_history(char *secret,const char (&history)[MAX_ATTEMPTS][NUMBER_QUANTITY], const int entry_nr);

#endif // LOGIC_H
