#ifndef CONSOLE_H_INCLUDED
#define CONSOLE_H_INCLUDED


/**********************Includes**********************/


/**********************Global MACROS**********************/


/**********************Global Data Types**********************/
typedef enum
{
    CHAR ,
    INT ,
    FLOAT ,
    DOUBLE ,
    STRING ,
}
CONSOLE_DATA_t;

/**********************Global Variables Declarations**********************/


/**********************Global Functions Prototypes**********************/
 void Console_Read(CONSOLE_DATA_t read_type , void* data );
 void Console_write(CONSOLE_DATA_t write_type , void* data);




#endif // CONSOLE_H_INCLUDED
