/**********************Includes**********************/
#include "Decider.h"
#include "Display.h"


/**********************Private MACROS**********************/
#define DECIDER_ADD()   (Decider_result = Decider_operands[0] + Decider_operands[1])
#define DECIDER_SUB()   (Decider_result = Decider_operands[0] - Decider_operands[1])
#define DECIDER_MUL()   (Decider_result = Decider_operands[0] * Decider_operands[1])
#define DECIDER_DIV()   (Decider_result = Decider_operands[0] / Decider_operands[1])

/**********************Private Data Types**********************/
typedef enum
{
    ADD = 'a' ,
    SUBTRACT = 's' ,
    MULTIPLY = 'm' ,
    DIVIDE = 'd' ,
    NO_OPERATION = 'z' ,
}
DECIDER_OPERATION_t ;

/**********************Private Variables Definitions**********************/
static TF64 Decider_result ;
static TF32 Decider_operands[2];
static DECIDER_OPERATION_t Decider_operation ;

/**********************Private Functions Prototypes**********************/
static void Decider_ExecuteOperation(void);

/**********************Global Variables Definitions**********************/


/**********************Global Functions Definitions**********************/
void Decider_Init(void)
{
    Decider_result = 0;
    Decider_operands[0]=0;
    Decider_operands[1]=0;
    Decider_operation = NO_OPERATION ;
}


void Decider_Task(void)
{
    DISPLAY_STATE_t state ;

    state = Display_GetState();

    switch(state)
    {
        case DISPLAY_READ_DECISION :
        case DISPLAY_READ_OPERANDS :
            //Wait for complete data filling
            break ;

        case DISPLAY_WAIT_RESULT :
            Decider_ExecuteOperation();
            Display_SetState(DISPLAY_WRITE_RESULT);
            break ;

        default :
            //Do Nothing
            break ;
    }
}


TF64 Decider_GetResult(void)
{
    return Decider_result ;
}

void Decider_SetVariable(DECIDER_VARIABLE_t var , void* data)
{
    switch(var)
    {
        case OPERANDS :
            Decider_operands[0] =  ((TF32*)data)[0] ;
            Decider_operands[1] =  ((TF32*)data)[1] ;
            break;

        case OPERATION :
            Decider_operation = (DECIDER_OPERATION_t)(*(TU08*)data) ;
            break;

        case RESULT :
            //Not Valid Operation
            break;

        default :
            //Do Nothing
            break;
    }
}

/**********************Private Functions Definitions**********************/
static void Decider_ExecuteOperation(void)
{
    switch(Decider_operation)
    {
        case ADD :
            DECIDER_ADD();
            break ;

        case SUBTRACT :
            DECIDER_SUB();
            break ;

        case MULTIPLY :
            DECIDER_MUL();
            break ;

        case DIVIDE :
            DECIDER_DIV();
            break ;

        case NO_OPERATION :
            //Do nothing
            break;


    }
}

