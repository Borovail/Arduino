#include "game.h"
#include "log_wrapper.h"
#include "lcd_wrapper.h"
#include "leds_manager.h"
#include "buttons_manager.h"
#include "sound_manager.h"

void setup()
{
  setup_logging();
  setup_leds();
  setup_lcd();
  setup_buttons();
  setup_piezo();

  clean_screen();

  const int length = 4;
  const bool repeat = false;

  char *secret_code = generate_code(repeat, length);
  Game game = create_game(secret_code);
  if (secret_code != NULL)
  {
    play_game(game);
    free(secret_code);
  }
}

void loop()
{
}
