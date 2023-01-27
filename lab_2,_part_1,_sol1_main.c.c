#include <stdio.h>
#include <header1.h>
int main()
{
    int error = 0;
    int ledNum = 0;
    int colors[NUM_LEDS] = {GREEN_LED, BLUE_LED, RED_LED};
    setupGPIO();

    while (!error)
    {
        setLED(RED_LED, ON);
        delay(DELAY);
        setLED(RED_LED, OFF);

        setLED(GREEN_LED, ON);
        delay(DELAY);
        setLED(GREEN_LED, OFF);

        setLED(BLUE_LED, ON);
        delay(DELAY);
        error = setLED(BLUE_LED, OFF);
        if (ledNum >= NUM_LEDS)
            ledNum = 0;
    }
    return 0;
}