#include <stdio.h>
#include <header1.h>
int main()
{
 int error = 0;
 int ledNum = 0;
 int colors[NUM_LEDS] = {GREEN_LED, BLUE_LED, RED_LED};
 setupGPIO();
 while(!error)
 {
    ledNum++;
    if(ledNum >= NUM_LEDS)
        ledNum = 0;

    setLED(Blue_PIN_2, ON);
    delay(DELAY);
    error = setLED(Blue_PIN_2, ON);
    delay(DELAY);
 }
return 0;
}
