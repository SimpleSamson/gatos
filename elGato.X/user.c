/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/


//#include <plib.h>            /* Include to use PIC32 peripheral libraries     */
#include <stdint.h>          /* For uint32_t definition                       */
#include <stdbool.h>         /* For true/false definition                     */
#include "user.h"            /* variables/params used by user.c               */
//#include <xc.h>          /* Defines special funciton registers, CP0 regs  */
#include <proc/p32mk0512mcm064.h>
#include "core/ctrl_buttons.h"
/******************************************************************************/
/* User Functions                                                             */
/******************************************************************************/

/* TODO Initialize User Ports/Peripherals/Project here */

void InitApp(void)
{
    /* Setup analog functionality and port direction */
    
    //Wheels port direction
    //NOTE the directions of rotation can be combined for front wheels to one motor
    TRISAbits.TRISA10 = 0;  //RA10    //front wheels right
    TRISBbits.TRISB13 = 0;  //RB13    //front wheels right anticlockwise
    TRISBbits.TRISB12 = 0;  //RB12    //front wheels left
    TRISBbits.TRISB11 = 0;  //RB11    //front wheels left anticlockwise
    TRISBbits.TRISB10 = 0;  //RB10    //hind wheels right 
    TRISFbits.TRISF1 = 0;   //RF1     //hind wheels right anticlockwise
    TRISFbits.TRISF0 = 0;   //RF0     //hind wheels left
    TRISCbits.TRISC9 = 0;   //RC9     //hind wheels left anticlockwise

    //butttons
    TRISGbits.TRISG7 = 1;     //STOP
    TRISGbits.TRISG8 = 1;     //LEFT
    TRISGbits.TRISG6 = 1;    //RIGHT
    TRISBbits.TRISB14 = 1;    //UP
    TRISAbits.TRISA12 = 1;    //DOWN
    TRISAbits.TRISA7 = 1;     //UP_RIGHT
    TRISBbits.TRISB15 = 1;    //UP_LEFT
    TRISGbits.TRISG9 = 1;     //DOWN_RIGHT
    TRISAbits.TRISA11 = 1;    //DOWN_LEFT
    
    /* Initialize peripherals */
            //todo write button parameters
//    polling
//    if(ButtonWatch(button.STOP == 1)){
//    }
//    if(ButtonWatch(button.specific.LEFT) == 1){
//        //interrupt
//        RotateAntiClockwise();
//    }
//    if(ButtonWatch(RIGHT_BTN)){
//        RotateClockwise();
//    }
//    if(ButtonWatch(UP_BTN)){
//        MoveForward();
//    }
//    if(ButtonWatch(DOWN_BTN)){
//        Reverse();
//    }
//    if(ButtonWatch(UP_RIGHT_BTN)){
//        TurnRight();
//    }
//    if(ButtonWatch(UP_LEFT_BTN)){
//        TurnLeft();
//    }
//    if(ButtonWatch(DOWN_RIGHT_BTN)){
//        ReverseTurnR();
//    }
//    if(ButtonWatch(DOWN_LEFT_BTN)){
//        ReverseTurnL();
//    }
}
void hindWheelsRReverse(){
    PORTBbits.RB10 = 1;
    PORTFbits.RF1 = 1;
}
void hindWheelsLReverse(){
    PORTFbits.RF0 = 1;
    PORTCbits.RC9 = 1;
}

//sw interrupt flag
//enable bits
//interrupt priority     