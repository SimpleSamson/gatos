/******************************************************************************/
/*  Files to Include                                                          */
/******************************************************************************/
#ifdef __XC32
    #include <xc.h>          /* Defines special funciton registers, CP0 regs  */
#endif

//#include <plib.h>           /* Include to use PIC32 peripheral libraries      */
#include <proc/p32mk0512mcm064.h>
#include <stdint.h>         /* For uint32_t definition                        */
#include <stdbool.h>        /* For true/false definition                      */

#include "system.h"         /* System funct/params, like osc/periph config    */
#include "user.h"           /* User funct/params, such as InitApp             */
#include "core/ctrl_buttons.h"
/******************************************************************************/
/* Global Variable Declaration                                                */
/******************************************************************************/

/* i.e. uint32_t <variable_name>; */

/******************************************************************************/
/* Main Program                                                               */
/******************************************************************************/

int32_t main(void)
{

//#ifndef PIC32_STARTER_KIT
//    /*The JTAG is on by default on POR.  A PIC32 Starter Kit uses the JTAG, but
//    for other debug tool use, like ICD 3 and Real ICE, the JTAG should be off
//    to free up the JTAG I/O */
//    DDPCONbits.JTAGEN = 0;
//#endif

    /*Refer to the C32 peripheral library documentation for more
    information on the SYTEMConfig function.
    
    This function sets the PB divider, the Flash Wait States, and the DRM
    /wait states to the optimum value.  It also enables the cacheability for
    the K0 segment.  It could has side effects of possibly alter the pre-fetch
    buffer and cache.  It sets the RAM wait states to 0.  Other than
    the SYS_FREQ, this takes these parameters.  The top 3 may be '|'ed
    together:
    
    SYS_CFG_WAIT_STATES (configures flash wait states from system clock)
    SYS_CFG_PB_BUS (configures the PB bus from the system clock)
    SYS_CFG_PCACHE (configures the pCache if used)
    SYS_CFG_ALL (configures the flash wait states, PB bus, and pCache)*/

    /* TODO Add user clock/system configuration code if appropriate.  */
//    SYSTEMConfig(SYS_FREQ, SYS_CFG_ALL); 

    /* Initialize I/O and Peripherals for application */
    InitApp();

    /*Configure Multivector Interrupt Mode.  Using Single Vector Mode
    is expensive from a timing perspective, so most applications
    should probably not use a Single Vector Mode*/
//    INTConfigureSystem(INT_SYSTEM_CONFIG_MULT_VECTOR);
    INTCONbits.MVEC = 1;

    /* TODO <INSERT USER APPLICATION CODE HERE> */

    while(1)
    {
        //buttons on pressed result in a flag and afterwards their is a response
        if(IFS0bits.IC1IF == 1){
            MoveForward();
        }
        if(IFS0bits.IC2IF == 1){
            Reverse();
        }
        if(IFS0bits.IC3IF == 1){
            TurnLeft();
        }
        if(IFS0bits.IC4IF == 1){
            TurnRight();
        }
        if(IFS0bits.IC5IF == 1){
            ReverseTurnR();
        }
        if(IFS2bits.IC6IF == 1){
            ReverseTurnL();
        }
        if(IFS2bits.IC7IF == 1){
            RotateClockwise();
        }
        if(IFS2bits.IC8IF == 1){
            RotateAntiClockwise();
        }
    }
}
