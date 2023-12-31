/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

//#ifdef __XC32
//    #include <xc.h>          /* Defines special funciton registers, CP0 regs  */
//#endif

//#include <plib.h>            /* Include to use PIC32 peripheral libraries     */
#include <sys/attribs.h>     /* For __ISR definition                          */
#include <stdint.h>          /* For uint32_t definition                       */
#include <stdbool.h>         /* For true/false definition                     */
#include "user.h"
#include <proc/p32mk0512mcm064.h>
/******************************************************************************/
/* Interrupt Vector Options                                                   */
/******************************************************************************/
/*                                                                            */
/* VECTOR NAMES:                                                              */
/*                                                                            */
/* _CORE_TIMER_VECTOR          _COMPARATOR_2_VECTOR                           */
/* _CORE_SOFTWARE_0_VECTOR     _UART_2A_VECTOR                                */
/* _CORE_SOFTWARE_1_VECTOR     _I2C_2A_VECTOR                                 */
/* _EXTERNAL_0_VECTOR          _SPI_2_VECTOR                                  */
/* _TIMER_1_VECTOR             _SPI_2A_VECTOR                                 */
/* _INPUT_CAPTURE_1_VECTOR     _I2C_4_VECTOR                                  */
/* _OUTPUT_COMPARE_1_VECTOR    _UART_3_VECTOR                                 */
/* _EXTERNAL_1_VECTOR          _UART_2_VECTOR                                 */
/* _TIMER_2_VECTOR             _SPI_3A_VECTOR                                 */
/* _INPUT_CAPTURE_2_VECTOR     _I2C_3A_VECTOR                                 */
/* _OUTPUT_COMPARE_2_VECTOR    _UART_3A_VECTOR                                */
/* _EXTERNAL_2_VECTOR          _SPI_4_VECTOR                                  */
/* _TIMER_3_VECTOR             _I2C_5_VECTOR                                  */
/* _INPUT_CAPTURE_3_VECTOR     _I2C_2_VECTOR                                  */
/* _OUTPUT_COMPARE_3_VECTOR    _FAIL_SAFE_MONITOR_VECTOR                      */
/* _EXTERNAL_3_VECTOR          _RTCC_VECTOR                                   */
/* _TIMER_4_VECTOR             _DMA_0_VECTOR                                  */
/* _INPUT_CAPTURE_4_VECTOR     _DMA_1_VECTOR                                  */
/* _OUTPUT_COMPARE_4_VECTOR    _DMA_2_VECTOR                                  */
/* _EXTERNAL_4_VECTOR          _DMA_3_VECTOR                                  */
/* _TIMER_5_VECTOR             _DMA_4_VECTOR                                  */
/* _INPUT_CAPTURE_5_VECTOR     _DMA_5_VECTOR                                  */
/* _OUTPUT_COMPARE_5_VECTOR    _DMA_6_VECTOR                                  */
/* _SPI_1_VECTOR               _DMA_7_VECTOR                                  */
/* _I2C_3_VECTOR               _FCE_VECTOR                                    */
/* _UART_1A_VECTOR             _USB_1_VECTOR                                  */
/* _UART_1_VECTOR              _CAN_1_VECTOR                                  */
/* _SPI_1A_VECTOR              _CAN_2_VECTOR                                  */
/* _I2C_1A_VECTOR              _ETH_VECTOR                                    */
/* _SPI_3_VECTOR               _UART_4_VECTOR                                 */
/* _I2C_1_VECTOR               _UART_1B_VECTOR                                */
/* _CHANGE_NOTICE_VECTOR       _UART_6_VECTOR                                 */
/* _ADC_VECTOR                 _UART_2B_VECTOR                                */
/* _PMP_VECTOR                 _UART_5_VECTOR                                 */
/* _COMPARATOR_1_VECTOR        _UART_3B_VECTOR                                */
/*                                                                            */
/* Refer to the device specific .h file in the C32 Compiler                   */
/* pic32mx\include\proc directory for a complete Vector and IRQ mnemonic      */
/* listings for the PIC32 device.                                             */
/*                                                                            */
/* PRIORITY OPTIONS:                                                          */
/*                                                                            */
/* (default) IPL0AUTO, IPL1, IPL2, ... IPL7 (highest)                         */
/*                                                                            */
/* Example Shorthand Syntax                                                   */
/*                                                                            */
/* void __ISR(<Vector Name>,<PRIORITY>) user_interrupt_routine_name(void)     */
/* {                                                                          */
/*     <Clear Interrupt Flag>                                                 */
/* }                                                                          */
/*                                                                            */
/* For more interrupt macro examples refer to the C compiler User Guide in    */
/* the C compiler /doc directory.                                             */
/*                                                                            */
/******************************************************************************/
/* Interrupt Routines                                                         */
/******************************************************************************/

/* TODO Add interrupt routine code here. */

//move forward
void __ISR(_INPUT_CAPTURE_1_VECTOR, IPL7AUTO) MoveForward(){
//    turn on both L and R MOTORS simultaneously
    //rb10 and rf0            
    HIND_WHEEL_R_ACCELERATE = 1;
    HIND_WHEEL_L_ACCELERATE = 1;
    //clear flag
    IFS0bits.IC1IF = 0;
}
//reverse
void __ISR(_INPUT_CAPTURE_2_VECTOR, IPL6AUTO) Reverse(){
    HIND_WHEEL_R_REVERSE;
    HIND_WHEEL_L_REVERSE;
    
    //clear flag
    IFS0bits.IC2IF = 0;
}
//turn left
void __ISR(_INPUT_CAPTURE_3_VECTOR, IPL5AUTO) TurnLeft(){
    HIND_WHEEL_R_ACCELERATE = 1;
    HIND_WHEEL_L_ACCELERATE = 0;
    
    //clear flag
    IFS0bits.IC3IF = 0;
}
//turn right
void __ISR(_INPUT_CAPTURE_4_VECTOR, IPL6AUTO) TurnRight(){
    HIND_WHEEL_R_ACCELERATE = 0;
    HIND_WHEEL_L_ACCELERATE = 1;
    
    //clear flag
    IFS0bits.IC4IF = 0;
}

//reverse turn
void __ISR(_INPUT_CAPTURE_5_VECTOR, IPL5AUTO) ReverseTurnR(){
    HIND_WHEEL_L_REVERSE;
    
    //clear flag
    IFS0bits.IC5IF = 0;
}
void __ISR(_INPUT_CAPTURE_6_VECTOR, IPL4AUTO) ReverseTurnL(){
    HIND_WHEEL_R_REVERSE;
    
    //clear flag
    IFS2bits.IC6IF = 0;
}

//rotate clockwise
void __ISR(_INPUT_CAPTURE_7_VECTOR, IPL3AUTO) RotateClockwise(){
    HIND_WHEEL_L_ACCELERATE = 1;
    HIND_WHEEL_R_REVERSE;

        //clear flag
    IFS2bits.IC7IF = 0;

}
void __ISR(_INPUT_CAPTURE_8_VECTOR, IPL2AUTO) RotateAntiClockwise(){
    HIND_WHEEL_R_ACCELERATE = 1;
    HIND_WHEEL_L_REVERSE;

    //clear flag
    IFS2bits.IC8IF = 0;
}