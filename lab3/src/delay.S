.section .text
.align 2
.globl delay
#include "memoryMap.inc"
# a0 is milliseconds passed through parameter
delay:
 addi sp, sp, -16
# allocate a stack frame, moves the stack up by 16 bits
 sw ra, 12(sp) # save return address on stack
 li t0, MTIME # load the timer register
 lw t1, 0(t0) # load the current value of the timer
 li t2, MTIME_FREQUENCY # get our approximate clock freq
 mul t2, t2, a0 # multiply milliseconds with freq
 add t2, t1, t2 # the target MTIME is now in t2
1:
 lw t1, 0(t0) # read M value again
 blt t1, t2, 1b # keep looping until time out
 lw ra, 12(sp) # restore return address
 addi sp, sp, 16 # deallocate the stack frame
 ret
