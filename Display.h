#ifndef DISPLAY_H_INCLUDED
#define DISPLAY_H_INCLUDED



/**********************Includes**********************/


/**********************Global MACROS**********************/


/**********************Global Data Types**********************/
typedef enum
{
    DISPLAY_READ_OPERANDS ,
    DISPLAY_READ_DECISION ,
    DISPLAY_WAIT_RESULT ,
    DISPLAY_WRITE_RESULT ,
}
DISPLAY_STATE_t ;

/**********************Global Variables Declarations**********************/


/**********************Global Functions Prototypes**********************/
void Display_Init(void);
void Display_Task(void) ;
DISPLAY_STATE_t Display_GetState(void);
void Display_SetState(DISPLAY_STATE_t state_val) ;

#endif // DISPLAY_H_INCLUDED
