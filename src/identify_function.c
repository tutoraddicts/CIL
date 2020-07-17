#include "identify_function.h"

funcIndex IdentifyFunction(char functionName[])
{
    char ch = functionName[0];
    switch (ch)
    {
    case 'p':
        // printf("found P");
        return PTypeFunctions(functionName);

        break;
    default:
        return INVALID_FUNCTION;
        break;
    }
}

funcIndex PTypeFunctions(char functionName[])
{
    if (strcmp(functionName, preDefFunc.console_print_function) == 0)
         return console_print_function;
    else
        return INVALID_FUNCTION;
    
}