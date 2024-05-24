#ifndef GAME_H
#define GAME_H

#include "logic.h"

struct Game
{
  char guess[NUMBER_QUANTITY]; 
  char history[MAX_ATTEMPTS][NUMBER_QUANTITY]; 
  char secret[NUMBER_QUANTITY];
  int attempts;
  int history_index;
  bool found;
};

Game create_game(const char *secret);
void play_game(Game &game);

#endif // GAME__H
