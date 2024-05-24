# Mastermind for Arduino - Instruction Guide

## Installation
1. **Download the Arduino IDE**:
   - From the official [Arduino website](https://www.arduino.cc/en/software).
   - Alternatively, install it from your Linux distribution’s repository:
     - Fedora: `sudo dnf install arduino`
     - Ubuntu: `sudo apt-get install arduino`

2. **Download and install Fritzing** (optional for drawing circuit diagrams):
   - From the [Fritzing website](http://fritzing.org/download/).

## Setup
1. **Connect the hardware**:
   - Follow the wiring diagram to connect your components to the Arduino board.
   
   ![Mastermind Schematic](schematic.png)
   Note: The diagram shows a basic version with buttons. This implementation uses a joystick instead of 5 buttons and includes an optional buzzer for sound feedback.

2. **Upload the code**:
   - Open the Arduino IDE.
   - Load the provided code file (`mastermind.ino`).
   - Connect your Arduino UNO to your computer via USB.
   - Select the correct board and port in the Arduino IDE.
   - Upload the code to the Arduino.

## Playing the Game
1. **Power on the Arduino**.
2. **Game Initialization**:
   - The LCD display will welcome you and provide instructions.
3. **Make a Guess**:
   - Use the joystick to set each digit of your guess.
   - Confirm your guess by pressing the joystick button.
4. **Receive Feedback**:
   - LEDs will light up to indicate the accuracy of your guess.
   - The LCD will display the results.
5. **Navigate History**:
   - Use the joystick to scroll through previous attempts after making at least two guesses.
   - You can set the displayed guess as your current guess by pressing Enter without counting it as a new attempt.
6. **Win or Lose**:
   - The game ends when you guess the correct combination or run out of attempts.
   - The LCD will display a message indicating whether you won or lost.

## Additional Notes
- The buzzer provides sound feedback upon losing or winning the game. If you prefer a silent game, you can omit the buzzer.
- The implementation can be modified to suit different hardware configurations or game rules.

## Changing Game Settings
- **Number of Attempts and Digits**: Modify the `logic.h` file to change the default number of attempts and the length of the secret code.
- **Repeating Numbers**: To allow repeating numbers in the secret code, change the parameter in the `generate_code()` function in `mastermind.ino`.
