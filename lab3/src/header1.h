#define DELAY 450
#define ON 0x01
#define OFF 0x00
#define NUM_LEDS 0x03

#define RED_LED 0x400000
#define BLUE_LED 0x200000
#define GREEN_LED 0x080000
#define TST_PIN_2 0x40000 //GPIO pin 2 offset
#define FLA_PIN_7 0x800000 //GPIO pin 2 offset
#define OLA_PIN_8 0x1 //GPIO pin 2 offset
#define ACK_PIN_9 0x2 //GPIO pin 2 offset
#define Green_PIN_17 0x800 //GPIO pin 2 offset
#define Yellow_PIN_18 0x1000 //GPIO pin 2 offset
#define Red_PIN_19 0x2000 //GPIO pin 2 offset
void setupGPIO();
int setLED(int color, int state);
void delay(int milliseconds);