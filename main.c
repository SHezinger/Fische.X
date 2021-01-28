/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.6
        Device            :  PIC12LF1571
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"


typedef enum {
    STATE_UNDEFINED = 0,
    STATE_WAIT_TIME,    //Ausgang 1 = 0, Ausgang 2 = 0 #S1 min 1 Sekunde gedr�ckt 
    STATE_OPEN_VALVE,    //Ausgang 1 = 1, Ausgang 2 = 0
    STATE_CLOSE_VALVE,   //Ausgang 1 = 0, Ausgang 2 = 1 #f�r 30 Sekunden
    STATE_END,          //Ausgang 1 = 0, Ausgang 2 = 0        
}states_t;

states_t currentState = STATE_UNDEFINED;

volatile uint16_t currentSecondsTick = 0;
uint16_t demandedSecondsTick = 0;

void setState(states_t newState);
void secondsTick();

/*
                         Main application
 */
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    
    TMR1_SetInterruptHandler(secondsTick);

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    
        

    TMR1_StartTimer();
      
    setState(STATE_WAIT_TIME);
    

    while (1)
    {
                    
        switch(currentState)
        {
            case STATE_WAIT_TIME:
                if(INPUT_START_GetValue())
                {
                    if(currentSecondsTick >= demandedSecondsTick)  //wait 1 second
                    {
                        setState(STATE_OPEN_VALVE);
                    }   
                    else if(INPUT_STOP_GetValue())
                    {
                        setState(STATE_CLOSE_VALVE);
                    }
                }
                else
                {
                    setState(STATE_END);
                }
                break;
                    
            case STATE_OPEN_VALVE:
                //shutdown after button press or 20 minutes
                if(INPUT_STOP_GetValue() || (currentSecondsTick >= demandedSecondsTick))
                {
                    setState(STATE_CLOSE_VALVE);
                }
                break;

            case STATE_CLOSE_VALVE:
                if(INPUT_START_GetValue())
                {
                    setState(STATE_OPEN_VALVE);
                }
                else if(currentSecondsTick >= demandedSecondsTick) //end after 10 seconds
                {
                    setState(STATE_END);
                }
                break;

            case STATE_END:
                //Enable interrupt on rising edge for the start button
             //   IOCAPbits.IOCAP5 = 1;
               
                TMR1_StopTimer();
                
                //wait till dooms day (or button pressed :) )
                asm("SLEEP");
                asm("NOP");
                
                TMR1_StartTimer();
                
                
//                INTCONbits.IOCIF = 0;   //Reset interrupt flag
//                
//                //Disable interrupt on rising edge for the start button
//                IOCAPbits.IOCAP5 = 0;
//                
                //Processor will resume work here after deep sleep
                setState(STATE_WAIT_TIME);
                break;
        }
        


    }
}
/**
 End of File
*/


void setState(states_t newState)
{
    if(newState == currentState)
        return;
    
    
    //Reset seconds tick
    currentSecondsTick = 0;
    
    
    switch(newState)
    {
        case STATE_WAIT_TIME:
            OUTPUT_1_FORWARD_SetLow();
            OUTPUT_2_RETURN_SetLow();
            currentSecondsTick = 0;
            demandedSecondsTick = currentSecondsTick + 2;
            break;
                    
        case STATE_OPEN_VALVE:
            OUTPUT_1_FORWARD_SetHigh();
            OUTPUT_2_RETURN_SetLow();
            currentSecondsTick = 0;
            demandedSecondsTick = currentSecondsTick + 1200; //20 Minutes
            break;
                    
        case STATE_CLOSE_VALVE:
            OUTPUT_1_FORWARD_SetLow();
            OUTPUT_2_RETURN_SetHigh();
            currentSecondsTick = 0;
            demandedSecondsTick = currentSecondsTick + 10;
            break;
                    
        case STATE_END:
            OUTPUT_1_FORWARD_SetLow();
            OUTPUT_2_RETURN_SetLow();
            break;
    }
    
    currentState = newState;
}


void secondsTick()
{
    currentSecondsTick++;
}


