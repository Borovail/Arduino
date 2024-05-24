# Mastermind for Arduino

## Overview
Mastermind is a classic game for two players, often known as Logik in some regions. This project implements the game using an Arduino prototyping board. One player sets a secret combination of colors (or numbers, in our case), and the other player tries to guess it. The game provides feedback on each guess to help the player deduce the correct combination.

## Project Description
This implementation modifies the traditional Mastermind game:
- The secret combination consists of four digits (0-9).
- The player interacts with the game via a joystick and an LCD display.
- Feedback is provided using RGB LEDs.
- The game runs on an Arduino UNO board.

## Game Rules
1. The Arduino generates a secret 4-digit combination.
2. The player tries to guess the combination by entering digits using a joystick.
3. Each guess is evaluated:
    - A red LED indicates a correct digit in the correct position.
    - A blue LED indicates a correct digit in the wrong position.
4. The game continues until the player guesses the combination or exhausts all attempts.
5. The player can navigate through the history of attempts using the joystick.

## Gameplay Features
- **Default Settings**: The game defaults to a 4-digit secret code and 10 attempts. To change these settings, modify the `logic.h` file.
- **No Repeating Numbers**: By default, the secret code will not have repeating numbers. This can be changed by passing `false` to the `generate_code()` function in `mastermind.ino`.
- **Random Number Generation**: The random number generation may not be perfect, leading to the same code being generated often.
- **History Navigation**: You can navigate through the history of attempts after making at least two guesses. While viewing the history, pressing Enter will set the displayed guess as your current guess without counting it as a new attempt.
