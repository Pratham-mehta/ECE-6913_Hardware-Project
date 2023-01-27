#include <stdio.h>
#include"header1.h"
int main()
{
    int A = 1;
    int B = 0;
    int C = 0;
    int D = 0;
    int E = 0;
    int F = 0;
    
    int error = 0;
    setupGPIO();
    while(!error)
    {
        while(A && !error)
        {
            setLED(Green_PIN_17, ON);
            setLED(Yellow_PIN_18, ON);
            setLED(Red_PIN_19, ON);
            delay(DELAY);
            setLED(Yellow_PIN_18, OFF);
            error = setLED(Red_PIN_19, OFF);
            delay(DELAY);
            if(checkBot(TST_PIN_2))
            {
                A = 0;
                B = 1;
            }
        }
        while(B && !error)
        {
            setLED(Green_PIN_17, ON);
            setLED(Yellow_PIN_18, OFF);
            error = setLED(Red_PIN_19, OFF);
            delay(DELAY);
            if(!checkBot(TST_PIN_2) && checkBot(FLA_PIN_7))
            {
                A = 1;
                B = 0;
            }
            else if(!checkBot(FLA_PIN_7))
            {
                B = 0;
                C = 1;
            }
        }
        while(C && !error)
        {
            setLED(Green_PIN_17, OFF);
            setLED(Yellow_PIN_18, ON);
            setLED(Red_PIN_19, OFF);
            delay(DELAY);
            error = setLED(Yellow_PIN_18, OFF);
            delay(DELAY);
            if(checkBot(OLA_PIN_8) && checkBot(FLA_PIN_7))
            {
                B = 1;
                C = 0;
            }
            else if(!checkBot(FLA_PIN_7) && !checkBot(ACK_PIN_9) && checkBot(OLA_PIN_8))
            {
                C = 0;
                D = 1;
            }
            else if(!checkBot(OLA_PIN_8))
            {
                C = 0;
                E = 1;
            }
        }
        while(D && !error)
        {
            setLED(Green_PIN_17, OFF);
            setLED(Yellow_PIN_18, ON);
            error = setLED(Red_PIN_19, OFF);
            delay(DELAY);
            if(checkBot(OLA_PIN_8) && checkBot(FLA_PIN_7))
            {
                C = 1;
                D = 0;
            }
            else if(!checkBot(OLA_PIN_8))
            {
                D = 0;
                E = 1;
            }
        }
        while(E && !error)
        {
            setLED(Green_PIN_17, OFF);
            setLED(Yellow_PIN_18, OFF);
            setLED(Red_PIN_19, ON);
            delay(DELAY);
            error = setLED(Red_PIN_19, OFF);
            delay(DELAY);            
            if(!checkBot(ACK_PIN_9))
            {
                E = 0;
                F = 1;
            }
        }

        while(F && !error)
        {
            setLED(Green_PIN_17, OFF);
            setLED(Yellow_PIN_18, OFF);
            error = setLED(Red_PIN_19, ON);
            delay(DELAY);            
            if(checkBot(OLA_PIN_8))
            {
                F = 0;
                D = 1;
            }
        }
    }
 return 0;
}