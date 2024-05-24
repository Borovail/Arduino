#include <Arduino.h>

#include "buttons_manager.h"
#include "log_wrapper.h"

void setup_buttons()
{
    pinMode(BTN_1_PIN, INPUT);
    pinMode(BTN_2_PIN, INPUT);
    pinMode(BTN_3_PIN, INPUT);
    pinMode(BTN_4_PIN, INPUT);
    pinMode(BTN_ENTER_PIN, INPUT_PULLUP);

    Log.info("Buttons setup");
}

bool button_pressed(int button_state)
{
    int button_unpressed_state = -1;
    return button_state != button_unpressed_state;
}

// reversed value  cause position of joystick rotated horizontaly to player but for joystick it is not rotated
bool joystick_up()
{
    if (analogRead(VRX_PIN) < 200)
    {
         Log.info("Joystick up");
         delay(DEBAUNCE_DELAY);
        return true;
    }

    return false;
}

bool joystick_down()
{
    if (analogRead(VRX_PIN)>800)
    {
         Log.info("Joystick down");
         delay(DEBAUNCE_DELAY);
        return true;
    }

    return false;
}

bool enter_pressed()
{
    if (digitalRead(BTN_ENTER_PIN) != LOW)
        return false;

     Log.info("Enter pressed");
         delay(DEBAUNCE_DELAY);
    return true;
}

int read_button()
{
    if (digitalRead(BTN_1_PIN) == HIGH)
    {
         Log.info("Button 1 pressed");
         delay(DEBAUNCE_DELAY);
        return 1;
    }
    else if (digitalRead(BTN_2_PIN) == HIGH)
    {
         Log.info("Button 2 pressed");
         delay(DEBAUNCE_DELAY);
        return 2;
    }
    else if (digitalRead(BTN_3_PIN) == HIGH)
    {
         Log.info("Button 3 pressed");
         delay(DEBAUNCE_DELAY);
        return 3;
    }
    else if (digitalRead(BTN_4_PIN) == HIGH)
    {
         Log.info("Button 4 pressed");
         delay(DEBAUNCE_DELAY);
        return 4;
    }
    return -1;
}
