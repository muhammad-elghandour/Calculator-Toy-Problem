/**********************Includes**********************/
#include "Console.h"
#include "Display.h"
#include "BasicTypes.h"
#include "Decider.h"

/**********************Private MACROS**********************/

/**********************Private Data Types**********************/


/**********************Private Variables Definitions**********************/
static DISPLAY_STATE_t Display_state ;

/**********************Private Functions Prototypes**********************/



/**********************Global Variables Definitions**********************/


/**********************Global Functions Definitions**********************/
void Display_Init(void)
{
    Console_write(STRING , "*********************************This is a Calculator Program**********************************\n");
    Console_write(STRING , "Operations Commands : Add ==> a , Subtract ==> s , Multiply == > m , Divide == > d \n");
    Console_write(STRING , "***********************************************************************************************\n\n");

    Display_state = DISPLAY_READ_OPERANDS ;
}

void Display_Task(void)
{
    TF32 operands[2] ;
    TU08 operation ;
    TF64 res ;


    switch(Display_state)
    {
        case DISPLAY_READ_OPERANDS :
            Console_write(STRING , "Please Enter Two Operands : ") ;
            Console_Read(FLOAT , &operands[0]);
            Console_Read(FLOAT , &operands[1]);
            Decider_SetVariable( OPERANDS , operands) ;
            Display_state = DISPLAY_READ_DECISION ;
            break;

        case DISPLAY_READ_DECISION :
            Console_write(STRING , "Please Enter Operation Type : ") ;
            Console_Read(CHAR , &operation);
            Decider_SetVariable(OPERATION, &operation) ;
            Display_state = DISPLAY_WAIT_RESULT ;
            break;

        case DISPLAY_WAIT_RESULT :
            //Do Nothing
            break;

        case DISPLAY_WRITE_RESULT :
            Console_write(STRING , "The Operation Result is : ") ;
            res = Decider_GetResult() ;
            Console_write(DOUBLE ,&res );
            Console_write(STRING , "\n");
            Display_state = DISPLAY_READ_OPERANDS ;
            break;

         default :
            //Do Nothing
            break;

    }


}

DISPLAY_STATE_t Display_GetState(void)
{
    return Display_state ;
}

void Display_SetState(DISPLAY_STATE_t state_val)
{
    Display_state = state_val ;
}

/**********************Private Functions Definitions**********************/
