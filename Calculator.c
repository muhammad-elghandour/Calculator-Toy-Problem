#include "Display.h"
#include "Decider.h"

int main()
{

   Display_Init();
   Decider_Init();



    while(1)
    {
        Display_Task();
        Decider_Task();
    }
}
