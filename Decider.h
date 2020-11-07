#ifndef DECIDER_H_INCLUDED
#define DECIDER_H_INCLUDED

/**********************Includes**********************/
#include "BasicTypes.h"

/**********************Global MACROS**********************/


/**********************Global Data Types**********************/
typedef enum
{
    OPERANDS ,
    OPERATION ,
    RESULT ,

}
DECIDER_VARIABLE_t ;
/**********************Global Variables Declarations**********************/


/**********************Global Functions Prototypes**********************/
void Decider_Init(void);
void Decider_Task(void) ;
TF64 Decider_GetResult(void);
void Decider_SetVariable(DECIDER_VARIABLE_t var , void* data) ;


#endif // DECIDER_H_INCLUDED
