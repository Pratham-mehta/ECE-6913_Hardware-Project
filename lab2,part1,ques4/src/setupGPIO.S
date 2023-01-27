.section .text
.align 2
.globl setupGPIO
#include "memoryMap.inc"
#include "GPIO.inc"
setupGPIO:
 addi sp, sp, -16
# allocate a stack frame, moves the stack up by 16 bits
 sw ra, 12(sp)
 li t0, GPIO_CTRL_ADDR # load GPIO base address
 li t1, PIN_2 # load address of pin 2 into t1
 sw t1, GPIO_INPUT_EN(t0) # set pin 2 for input enable
 sw t1, GPIO_INPUT_PULUP(t0) # enable pull up
 li t1, GPIO_RGB_PINS # get RGB pins offset
 sw t1, GPIO_OUTPUT_EN(t0)
# write the GPIO RGP pins to GPIO Enable offset
# (Enable output on RGP pins so we can write)
 sw t1, GPIO_OUTPUT_XOR(t0) # set the XOR so the RGB pins are active high
 sw x0, GPIO_OUTPUT_VAL(t0)
 lw ra, 12(sp) # return the return address
 addi sp, sp, 16 # deallocate the stack
 ret