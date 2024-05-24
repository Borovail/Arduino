#include <Arduino.h>

#include "logic.h"
#include "lcd_wrapper.h"
#include "buttons_manager.h"
#include "leds_manager.h"
#include "sound_manager.h"
#include "log_wrapper.h"

char *generate_code(bool repeat, int length) {
  Log.trace("Generating code with repeat: %d, length: %d", repeat, length);

  if (length < 1) {
    Log.error("Invalid code length provided, length should be greater then 0");
    return NULL;
  }


  bool used_digits[10] = { false };

  randomSeed(analogRead(0));

  char *code = (char *)malloc((length + 1) * sizeof(char));
  if (code == NULL) {
    Log.error("Failed to allocate memory");
    return NULL;
  }

  for (int i = 0; i < length; ++i) {
    int digit;

    if (repeat)
      digit = random() % 10;
    else {
      do {
        digit = random() % 10;
      } while (used_digits[digit]);
      used_digits[digit] = true;
    }

    code[i] = '0' + digit;
  }

  code[length] = '\0';
  Log.notice("Generated code: %s", code);

  return code;
}

void get_score(const char *secret, const char *guess, int &peg_a, int &peg_b) {
  Log.trace("get_score with secret: %s, guess: %s, peg_a: %d, peg_b: %d", secret, guess, peg_a, peg_b);

  int len = strlen(secret);
  peg_a = 0;
  peg_b = 0;

  bool secret_matched[len];
  bool guess_matched[len];
  memset(secret_matched, false, len * sizeof(bool));
  memset(guess_matched, false, len * sizeof(bool));

  for (int i = 0; i < len; ++i) {
    if (secret[i] == guess[i]) {
      peg_a++;
      secret_matched[i] = true;
      guess_matched[i] = true;
    }
  }

  for (int i = 0; i < len; ++i) {
    if (!guess_matched[i]) {
      for (int j = 0; j < len; ++j) {
        if (!secret_matched[j] && guess[i] == secret[j]) {
          peg_b++;
          secret_matched[j] = true;
          break;
        }
      }
    }
  }

  Log.trace("Score:  peg_a: %d, peg_b: %d", peg_a, peg_b);
}

void handle_enter_pressed(char *guess,const char (&history)[MAX_ATTEMPTS][NUMBER_QUANTITY], int &history_index) {
  Log.trace("Selecting guess from history at index: %d", history_index);
  strcpy(guess, history[history_index]);
  lcd_display_guess(guess);
  delay(DEBOUNCE_DELAY);
}

void move_history_up(char *secret, const char (&history)[MAX_ATTEMPTS][NUMBER_QUANTITY], int &history_index, int attempts,bool &in_history_mode) {

   if (history_index > 0) { 
    Log.notice("Moving history up");
    history_index--;
    in_history_mode = true;
    render_history(secret, history, history_index);
  }
}

void move_history_down(char *secret, const char (&history)[MAX_ATTEMPTS][NUMBER_QUANTITY], int &history_index, int attempts,bool &in_history_mode) {
   if (history_index < attempts-1) { 
    Log.notice("Moving history down");
    history_index++;
    in_history_mode = true;
    render_history(secret, history, history_index);
  }
}

void update_guess(char *guess, int button_index) {
  if (button_index >= 1 && button_index <= 4) {
    guess[button_index - 1] = (guess[button_index - 1] - '0' + 1) % 10 + '0';
    Log.trace("Updated guess: %s", guess);
  }
}

void render_history(char *secret,const char (&history)[MAX_ATTEMPTS][NUMBER_QUANTITY], const int entry_nr) {
  // Log.trace("Rendering history with entry_nr: %d", entry_nr);
  int peg_a, peg_b;

  turn_off_leds();
  get_score(secret, history[entry_nr], peg_a, peg_b);
  render_leds(peg_a, peg_b);

  lcd_clear();
  lcd_print("History: ");
  
  char formatted_guess[16];
  snprintf(formatted_guess, sizeof(formatted_guess), "%d: %s", entry_nr + 1, history[entry_nr]);

  lcd_print_at(1, 0, formatted_guess);
  // Log.trace("History rendered with peg_a: %d, peg_b: %d", peg_a, peg_b);
}
