/******************************************************************************/
/* User Level #define Macros                                                  */
/******************************************************************************/
#define FRONT_WHEEL_R_CLOCKWISE    PORTAbits.RA10    //front wheels right
#define FRONT_WHEEL_R_ANTICLOCKWISE    PORTBbits.RB13    //front wheels right anticlockwise
#define FRONT_WHEEL_L_CLOCKWISE    PORTBbits.RB12    //front wheels left
#define FRONT_WHEEL_L_ANTICLOCKWISE    PORTBbits.RB11    //front wheels left anticlockwise
#define HIND_WHEEL_R_ACCELERATE    PORTBbits.RB10    //hind wheels right 
#define HIND_WHEEL_R_REVERSE    hindWheelsRReverse()     //hind wheels right anticlockwise
#define HIND_WHEEL_L_ACCELERATE    PORTFbits.RF0     //hind wheels left
#define HIND_WHEEL_L_REVERSE    hindWheelsLReverse()     //hind wheels left anticlockwise
            

/* TODO Application specific user parameters used in user.c may go here */

/******************************************************************************/
/* User Function Prototypes                                                    /
/******************************************************************************/

/* TODO User level functions prototypes (i.e. InitApp) go here */

void InitApp(void);         /* I/O and Peripheral Initialization */
//hind wheels actions state 1 for ON or 0 for OFF default is off i.e accelerate
void hindWheelsRReverse();
void hindWheelsLReverse();