#include "Calculations.h"

void* Do_Calculation(String data){
    String Instruction = (String)malloc(sizeof(char)*100);

    if (*data != '(')
        return;

    int i = 1;
    int j = 0;    
    while (*data+i != ')')
    {
        *(Instruction+i-1) = *(data+i);
        i++;
    }
    i--;


}