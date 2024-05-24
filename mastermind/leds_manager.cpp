#include <Arduino.h>

#include "leds_manager.h"
#include "log_wrapper.h"

int leds[] = {
    LED_BLUE_1, LED_RED_1, LED_BLUE_2, LED_RED_2, LED_BLUE_3, LED_RED_3, LED_BLUE_4, LED_RED_4};

void setup_leds()
{
  for (int i = 0; i < 8; i++)
  {
    pinMode(leds[i], OUTPUT);
  }

  Log.info("Leds setup");
}

void turn_on_leds()
{
  for (int i = 0; i < 8; i++)
  {
    digitalWrite(leds[i], HIGH);
  }
}

void turn_off_leds()
{
  for (int i = 0; i < 8; i++)
  {
    digitalWrite(leds[i], LOW);
  }
}

static void sweepLeftToRight()
{
  for (int i = 0; i < 8; i++)
  {
    digitalWrite(leds[i], HIGH);
    delay(ANIMATION_SPEED_DELAY);
  }
  turn_off_leds();
}

static void sweepRightToLeft()
{
  for (int i = 7; i >= 0; i--)
  {
    digitalWrite(leds[i], HIGH);
    delay(ANIMATION_SPEED_DELAY);
  }
  turn_off_leds();
}

static void meetInTheMiddle()
{
  for (int i = 0; i < 4; i++)
  {
    digitalWrite(leds[i], HIGH);
    digitalWrite(leds[7 - i], HIGH);
    delay(ANIMATION_SPEED_DELAY);
  }
  turn_off_leds();
}

static void moveFromCenter()
{
  for (int i = 3; i >= 0; i--)
  {
    digitalWrite(leds[i], HIGH);
    digitalWrite(leds[7 - i], HIGH);
    delay(ANIMATION_SPEED_DELAY);
  }
  turn_off_leds();
}

static void randomBlinking()
{
  for (int i = 0; i < 20; i++)
  {
    int led = random(8);
    digitalWrite(leds[led], !digitalRead(leds[led]));
    delay(ANIMATION_SPEED_DELAY);
  }
  turn_off_leds();
}

void play_winning_lights()
{
  sweepLeftToRight();
  delay(ANIMATION_SPEED_DELAY);
  sweepRightToLeft();
  delay(ANIMATION_SPEED_DELAY);
  meetInTheMiddle();
  delay(ANIMATION_SPEED_DELAY);
  moveFromCenter();
  delay(ANIMATION_SPEED_DELAY);
  randomBlinking();
  delay(ANIMATION_SPEED_DELAY);
  turn_on_leds();
  delay(3000);
  turn_off_leds();
  delay(100);

  Log.info("Winning lights played");
}

void render_leds(const int peg_a, const int peg_b)
{

  for (int i = 0; i < peg_a; i++)
  {
    if (i * 2 + 1 < 8)
    {
      digitalWrite(leds[i * 2 + 1], HIGH); 
    }
  }

  for (int i = 0; i < peg_b; i++)
  {
    if (i * 2 < 8)
    {
      digitalWrite(leds[i * 2], HIGH); 
    }
  }

  Log.trace("Leds rendered with peg_a: %d, peg_b: %d", peg_a, peg_b);
}
