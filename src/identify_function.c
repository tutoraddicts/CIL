#include "identify_function.h"

funcIndex IdentifyFunction(char functionName[])
{
    char ch = functionName[0];
    switch (ch)
    {
    case 'p':
        return PTypeFunctions(functionName);
        break;
    default:
        return INVALID_FUNCTION;
        break;
    }
}

funcIndex PTypeFunctions(char functionName[])
{
    if (strcmp(functionName, "print"))
        return console_print_function;
    else
        return INVALID_FUNCTION;
    
}