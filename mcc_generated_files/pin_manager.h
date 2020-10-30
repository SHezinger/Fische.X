/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.6
        Device            :  PIC12F1571
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.30 and above
        MPLAB 	          :  MPLAB X 5.40	
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set OUTPUT_1_FORWARD aliases
#define OUTPUT_1_FORWARD_TRIS                 TRISAbits.TRISA1
#define OUTPUT_1_FORWARD_LAT                  LATAbits.LATA1
#define OUTPUT_1_FORWARD_PORT                 PORTAbits.RA1
#define OUTPUT_1_FORWARD_WPU                  WPUAbits.WPUA1
#define OUTPUT_1_FORWARD_OD                   ODCONAbits.ODA1
#define OUTPUT_1_FORWARD_ANS                  ANSELAbits.ANSA1
#define OUTPUT_1_FORWARD_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define OUTPUT_1_FORWARD_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define OUTPUT_1_FORWARD_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define OUTPUT_1_FORWARD_GetValue()           PORTAbits.RA1
#define OUTPUT_1_FORWARD_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define OUTPUT_1_FORWARD_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define OUTPUT_1_FORWARD_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define OUTPUT_1_FORWARD_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define OUTPUT_1_FORWARD_SetPushPull()        do { ODCONAbits.ODA1 = 0; } while(0)
#define OUTPUT_1_FORWARD_SetOpenDrain()       do { ODCONAbits.ODA1 = 1; } while(0)
#define OUTPUT_1_FORWARD_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define OUTPUT_1_FORWARD_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set OUTPUT_2_RETURN aliases
#define OUTPUT_2_RETURN_TRIS                 TRISAbits.TRISA2
#define OUTPUT_2_RETURN_LAT                  LATAbits.LATA2
#define OUTPUT_2_RETURN_PORT                 PORTAbits.RA2
#define OUTPUT_2_RETURN_WPU                  WPUAbits.WPUA2
#define OUTPUT_2_RETURN_OD                   ODCONAbits.ODA2
#define OUTPUT_2_RETURN_ANS                  ANSELAbits.ANSA2
#define OUTPUT_2_RETURN_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define OUTPUT_2_RETURN_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define OUTPUT_2_RETURN_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define OUTPUT_2_RETURN_GetValue()           PORTAbits.RA2
#define OUTPUT_2_RETURN_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define OUTPUT_2_RETURN_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define OUTPUT_2_RETURN_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define OUTPUT_2_RETURN_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define OUTPUT_2_RETURN_SetPushPull()        do { ODCONAbits.ODA2 = 0; } while(0)
#define OUTPUT_2_RETURN_SetOpenDrain()       do { ODCONAbits.ODA2 = 1; } while(0)
#define OUTPUT_2_RETURN_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define OUTPUT_2_RETURN_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set INPUT_STOP aliases
#define INPUT_STOP_TRIS                 TRISAbits.TRISA4
#define INPUT_STOP_LAT                  LATAbits.LATA4
#define INPUT_STOP_PORT                 PORTAbits.RA4
#define INPUT_STOP_WPU                  WPUAbits.WPUA4
#define INPUT_STOP_OD                   ODCONAbits.ODA4
#define INPUT_STOP_ANS                  ANSELAbits.ANSA4
#define INPUT_STOP_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define INPUT_STOP_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define INPUT_STOP_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define INPUT_STOP_GetValue()           PORTAbits.RA4
#define INPUT_STOP_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define INPUT_STOP_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define INPUT_STOP_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define INPUT_STOP_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define INPUT_STOP_SetPushPull()        do { ODCONAbits.ODA4 = 0; } while(0)
#define INPUT_STOP_SetOpenDrain()       do { ODCONAbits.ODA4 = 1; } while(0)
#define INPUT_STOP_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define INPUT_STOP_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set INPUT_START aliases
#define INPUT_START_TRIS                 TRISAbits.TRISA5
#define INPUT_START_LAT                  LATAbits.LATA5
#define INPUT_START_PORT                 PORTAbits.RA5
#define INPUT_START_WPU                  WPUAbits.WPUA5
#define INPUT_START_OD                   ODCONAbits.ODA5
#define INPUT_START_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define INPUT_START_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define INPUT_START_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define INPUT_START_GetValue()           PORTAbits.RA5
#define INPUT_START_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define INPUT_START_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define INPUT_START_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define INPUT_START_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define INPUT_START_SetPushPull()        do { ODCONAbits.ODA5 = 0; } while(0)
#define INPUT_START_SetOpenDrain()       do { ODCONAbits.ODA5 = 1; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/