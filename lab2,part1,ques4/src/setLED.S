.section .text
.align 2
.globl setLED
#include "memoryMap.inc"
#include "GPIO.inc"
.equ NOERROR, 0x0
.equ ERROR, 0x1
.equ LEDON, 0x1
# which LED to set comes into register a0
# desired On/Off state comes into a1
setLED:
 addi sp, sp, -16
# allocate a stack frame, moves the stack up by 16 bits
 sw ra, 12(sp) # save return address on stack

 li t0, GPIO_CTRL_ADDR # load GPIO address
 lw t1, GPIO_OUTPUT_VAL(t0) # get the current value of the pins
 beqz a1, ledOff # Branch to ledOff if a1 == OFF (0x0)
 li t2, LEDON # load up value of LEDON into temp register
 beq a1, t2, ledOn # branch to ledOn if a1 == ON (0x1)
 li a0, ERROR # return an error for a bad status request
 j exit
ledOn:
 xor t1, t1, a0 # XOR to only change the value of requested LED
 sw t1, GPIO_OUTPUT_VAL(t0) # write the new output value to GPIO out
 li a0, NOERROR # no error
 j exit
ledOff:
 xor a0, a0, 0xffffffff
# invert everything so that all bits are one except the LED we are turning off
 and t1, t1, a0
# AND a0 and t1 to get the LED we want to turn off
 sw t1, GPIO_OUTPUT_VAL(t0) # write the new output value
 li a0, NOERROR
exit:
 lw ra, 12(sp) # restore the return address
 addi sp, sp, 16 # deallocating stack frame
 ret