#include <Arduino.h>

#include "game.h"
#include "log_wrapper.h"
#include "logic.h"
#include "lcd_wrapper.h"
#include "leds_manager.h"
#include "buttons_manager.h"
#include "sound_manager.h"



Game create_game(const char *secret) {
  Log.trace("Creating game");
  Game game;
  memset(game.guess, '0', NUMBER_QUANTITY - 1);
  game.guess[NUMBER_QUANTITY - 1] = '\0';

  for (int i = 0; i < MAX_ATTEMPTS; i++) {
    memset(game.history[i], '0', NUMBER_QUANTITY - 1);
    game.history[i][NUMBER_QUANTITY - 1] = '\0';
  }

  strncpy(game.secret, secret, NUMBER_QUANTITY - 1);
  game.secret[NUMBER_QUANTITY - 1] = '\0';

  game.attempts = 0;
  game.history_index = 0;
  game.found = false;

  Log.info("Game created");

  return game;
}

void check_guess(Game &game) {
  Log.trace("Checking guess with guess: %s, attempts: %d, history_index: %d", game.guess, game.attempts, game.history_index);
  strcpy(game.history[game.attempts], game.guess);
  game.attempts++;

  int peg_a = 0, peg_b = 0;
  get_score(game.secret, game.guess, peg_a, peg_b);
  turn_off_leds();
  render_leds(peg_a, peg_b);

  lcd_display_guess(game.guess);

  Log.info("Checking guess: %s, Peg A: %d, Peg B: %d", game.guess, peg_a, peg_b);

  if (peg_a == 4) {
    game.found = true;
    Log.info("Secret combination found!");
  } else {
    lcd_display_guess(game.guess);
    lcd_set_cursor(1,0);
    lcd_display_attempts_left(MAX_ATTEMPTS - game.attempts );
    memset(game.guess, '0', NUMBER_QUANTITY - 1);
    game.guess[NUMBER_QUANTITY - 1] = '\0';
    Log.info("Secret combination not found, resetting guess for next attempt");
  }

  Log.trace("Guess checked");
}

void player_turn(Game &game) {
  Log.trace("Player turn with guess: %s, attempts: %d, history_index: %d", game.guess, game.attempts, game.history_index);
  bool in_history_mode = false;

  while (true) {
    int button = read_button();

    update_guess(game.guess, button);

    if (joystick_up()) {
      move_history_up(game.secret, game.history, game.history_index,game.attempts,in_history_mode);
    } else if (joystick_down()) {
      move_history_down(game.secret, game.history, game.history_index,game.attempts,in_history_mode);
    }

    if (button_pressed(button)) {
      lcd_display_guess(game.guess);
      game.history_index=0;
      delay(DEBOUNCE_DELAY);
      in_history_mode = false;
    }

    if (enter_pressed()) {
      // Log.trace("Enter pressed, in_history_mode: %d", in_history_mode);
      if (!in_history_mode)
        break;

      handle_enter_pressed(game.guess, game.history, game.history_index);
      game.history_index = 0;
      in_history_mode = false;
    }
  }

  Log.trace("Player turn ended");
}

void play_game(Game &game) {
  Log.trace("Playing game with guess: %s, attempts: %d, history_index: %d", game.guess, game.attempts, game.history_index);
  lcd_display_welcome_message();
  lcd_display_guess(game.guess);

  while (game.attempts < MAX_ATTEMPTS && !game.found) {
    player_turn(game);
    check_guess(game);
  }

  if (game.found) {
    lcd_display_victory_message(game.secret);
    play_winning_lights();
  } else {
    play_losing_sound();
    lcd_display_defeat_message(game.secret);
  }
}
