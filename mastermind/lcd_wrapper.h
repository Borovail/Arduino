#ifndef LCD_WRAPPER_H
#define LCD_WRAPPER_H



/**
 * Initialize LCD
 *
 * Everything you need to initialize your LCD display, place here.
 * This function should be called in function setup().
 */
void setup_lcd();

/**
 * Clears the LCD display
 *
 * Clears content of the LCD display. After the call is display empty.
 */
void lcd_clear();

/**
 * Set cursor to given position
 *
 * Sets cursor to given position based on y and x coordinates.
 * @param row the row
 * @param col the column
 */
void lcd_set_cursor(int row, int col);

/**
 * Print text on LCD display
 *
 * Prints the given text on the display on the current
 * cursor position.
 * @param text the text to print
 */
void lcd_print(const char *text);

/**
 * Set cursor to given position and print text
 *
 * Sets the cursor to given position based on y and x coordinates
 * and then prints the given text.
 * @param y the row
 * @param x the column
 * @param text the text to print
 */
void lcd_print_at(int row, int col, const char *text);

/**
 * Display rising text
 *
 * Displays text in a rising fashion, where each line of text moves up
 * sequentially until all lines have been displayed.
 * @param lines an array of text lines to display
 * @param num_lines the number of text lines to display
 */
void lcd_display_rising_text(const char *lines[], int num_lines);

void lcd_display_welcome_message();
void lcd_display_guess(const char *guess);
void lcd_display_victory_message(const char *secret);
void lcd_display_attempts_left(int attempts_left);
void lcd_display_defeat_message(const char *secret);

#endif // LCD_WRAPPER_H
