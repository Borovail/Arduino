#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Arduino.h>

#include "lcd_wrapper.h"
#include "log_wrapper.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup_lcd()
{
  lcd.init();
  lcd.backlight();
  lcd.clear();

  Log.info("LCD setup");
}

void lcd_clear()
{
  lcd.clear();

  Log.info("LCD display cleared");
}

void lcd_set_cursor(int y, int x)
{
  lcd.setCursor(x, y);
}

void lcd_print(const char *text)
{
  lcd.print(text);
}

void lcd_print_at(int y, int x, const char *text)
{
  lcd_set_cursor(y, x);
  lcd_print(text);
}

void lcd_display_rising_text(const char *lines[], int num_lines)
{
  for (int i = 0; i < num_lines; i++)
  {
    lcd_clear();
    lcd_print_at(0, 0, lines[i]);
    delay(1500);
  }
}

void lcd_display_welcome_message()
{
  lcd_clear();
  lcd_print_at(0, 0, "Welcome to the");
  lcd_print_at(1, 0, "Game!");
  delay(2000);
  lcd_clear();

  Log.info("Welcome message displayed");
}

void lcd_display_guess(const char *guess)
{
  lcd_clear();
  lcd_print("Your guess: ");
  lcd_print(guess);
}

void lcd_display_victory_message(const char *secret)
{
  const char *victory_lines[] = {"Congratulations!", "You've found", "the secret", "combination!"};
  lcd_display_rising_text(victory_lines, 4);
  lcd_clear();
  lcd_print_at(0, 0, "Combination:");
  lcd_print_at(1, 0, secret);

  Log.info("Victory message displayed");
}

void lcd_display_attempts_left(int attempts_left)
{
  lcd_print("Attempts left: ");
  lcd_print(String(attempts_left).c_str());
}

void lcd_display_defeat_message(const char *secret)
{
  const char *defeat_lines[] = {"Game over!", "You've run out", "of attempts."};
  lcd_display_rising_text(defeat_lines, 3);
  lcd_clear();
  lcd_print_at(0, 0, "Combination was:");
  lcd_print_at(1, 0, secret);

  Log.info("Defeat message displayed");
}
