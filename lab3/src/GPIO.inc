.equ GPIO_OUTPUT_EN, 0x008 # Enable Output to selected pins
.equ GPIO_OUTPUT_VAL, 0x00C # Set Output Value
.equ GPIO_OUTPUT_XOR, 0x040 # inverse logic on selected pins
.equ GPIO_INPUT_EN, 0x04 # Set Input enable for selected pins
.equ GPIO_INPUT_VAL, 0x00 # Read Input value of selected pins
.equ GPIO_INPUT_PULUP, 0x10 # enable pull up
.equ PIN_2, 0x40000 # GPIO pin 2 offset
.equ PIN_7, 0x800000 # GPIO pin 7 offset
.equ PIN_8, 0x1 # GPIO pin 8 offset
.equ PIN_9, 0x2 # GPIO pin 9 offset
.equ PIN_17, 0x800 # GPIO pin 17 offset
.equ PIN_18, 0x1000 # GPIO pin 18 offset
.equ PIN_19, 0x2000 # GPIO pin 19 offset
.equ GPIO_RGB_PINS, 0x680000 # All 3 LED's bit offset
.equ GPIO_RED_LED, 0x400000 # Red LED offset
.equ GPIO_BLUE_LED, 0x200000 # Blue LED offset
.equ GPIO_GREEN_LED, 0x080000 # Green LED offset