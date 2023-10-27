/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.h

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

#ifndef _EXAMPLE_FILE_NAME_H    /* Guard against multiple inclusion */
#define _EXAMPLE_FILE_NAME_H


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

/* This section lists the other files that are included in this file.
 */

/* TODO:  Include other files here if needed. */
#include <proc/p32mk0512mcm064.h>

/* Provide C++ Compatibility */
#ifdef __cplusplus
extern "C" {
#endif


    /* ************************************************************************** */
    /* ************************************************************************** */
    /* Section: Constants                                                         */
    /* ************************************************************************** */
    /* ************************************************************************** */

    /*  A brief description of a section can be given directly below the section
        banner.
     */


    /* ************************************************************************** */
    /** Descriptive Constant Name

      @Summary
        Brief one-line summary of the constant.
    
      @Description
        Full description, explaining the purpose and usage of the constant.
        <p>
        Additional description in consecutive paragraphs separated by HTML 
        paragraph breaks, as necessary.
        <p>
        Type "JavaDoc" in the "How Do I?" IDE toolbar for more information on tags.
    
      @Remarks
        Any additional remarks
     */
#define STOP_BTN        PORTGbits.RG7
#define LEFT_BTN        PORTGbits.RG8
#define RIGHT_BTN       PORTGbits.RG6
#define UP_BTN          PORTBbits.RB14
#define DOWN_BTN        PORTAbits.RA12
#define UP_RIGHT_BTN    PORTAbits.RA7
#define UP_LEFT_BTN     PORTBbits.RB15
#define DOWN_RIGHT_BTN  PORTGbits.RG9
#define DOWN_LEFT_BTN   PORTAbits.RA11
    
    // *****************************************************************************
    // *****************************************************************************
    // Section: Data Types
    // *****************************************************************************
    // *****************************************************************************

    /*  A brief description of a section can be given directly below the section
        banner.
     */


    // *****************************************************************************

    /** Descriptive Data Type Name

      @Summary
        Brief one-line summary of the data type.
    
      @Description
        Full description, explaining the purpose and usage of the data type.
        <p>
        Additional description in consecutive paragraphs separated by HTML 
        paragraph breaks, as necessary.
        <p>
        Type "JavaDoc" in the "How Do I?" IDE toolbar for more information on tags.

      @Remarks
        Any additional remarks
        <p>
        Describe enumeration elements and structure and union members above each 
        element or member.
     */
    typedef struct _example_struct_t {
        /* Describe structure member. */
        int some_number;

        /* Describe structure member. */
        bool some_flag;

    } example_struct_t;


    // *****************************************************************************
    // *****************************************************************************
    // Section: Interface Functions
    // *****************************************************************************
    // *****************************************************************************

    /*  A brief description of a section can be given directly below the section
        banner.
     */

    // *****************************************************************************
    /**
      @Function
        int ExampleFunctionName ( int param1, int param2 ) 

      @Summary
        Brief one-line description of the function.

      @Description
        Full description, explaining the purpose and usage of the function.
        <p>
        Additional description in consecutive paragraphs separated by HTML 
        paragraph breaks, as necessary.
        <p>
        Type "JavaDoc" in the "How Do I?" IDE toolbar for more information on tags.

      @Precondition
        List and describe any required preconditions. If there are no preconditions,
        enter "None."

      @Parameters
        @param param1 Describe the first parameter to the function.
    
        @param param2 Describe the second parameter to the function.

      @Returns
        List (if feasible) and describe the return values of the function.
        <ul>
          <li>1   Indicates an error occurred
          <li>0   Indicates an error did not occur
        </ul>

      @Remarks
        Describe any special behavior not described above.
        <p>
        Any additional remarks.

      @Example
        @code
        if(ExampleFunctionName(1, 2) == 0)
        {
            return 3;
        }
     */
    int ExampleFunction(int param1, int param2);

typedef union {
//    find way of assigning values
    struct{
        uint32_t STOP : 1;
        uint32_t LEFT : 1;  //        PORTGbits.RG8
        uint32_t RIGHT : 1;  //       PORTGbits.RG6
        uint32_t UP : 1;    //         PORTBbits.RB14
        uint32_t DOWN : 1;  //       PORTAbits.RA12
        uint32_t UP_RIGHT : 1;    //    PORTAbits.RA7
        uint32_t UP_LEFT : 1;   //    PORTBbits.RB15
        uint32_t DOWN_RIGHT : 1;    //  PORTGbits.RG9
        uint32_t DOWN_LEFT : 1; //   PORTAbits.RA11
    }specific;
} __button_t;
extern volatile __button_t button;

#define STOP PORTGbits.RG7
#define LEFT PORTGbits.RG8
#define RIGHT PORTGbits.RG6
#define UP PORTBbits.RB14
#define DOWN PORTAbits.RA12
#define UP_RIGHT PORTAbits.RA7
#define UP_LEFT PORTBbits.RB15
#define DOWN_RIGHT PORTGbits.RG9
#define DOWN_LEFT PORTAbits.RA11

//void ButtonWatch(__button_t button);

    /* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif /* _EXAMPLE_FILE_NAME_H */

/* *****************************************************************************
 End of File
 */
