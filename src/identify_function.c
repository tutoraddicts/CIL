#include "identify_function.h"

funcIndex IdentifyFunction(char functionName[])
{
    // Settings up pre def functions with there name
    static PreDefinedFunctions _PreDefinedFunctions;
    setup_predef_functions(&_PreDefinedFunctions);

    char ch = functionName[0];
    switch (ch)
    {
    case 'p':
        // printf("found P");
        return PTypeFunctions(functionName, &_PreDefinedFunctions);

        break;
    default:
        return INVALID_FUNCTION;
        break;
    }
}

funcIndex PTypeFunctions(char functionName[], PreDefinedFunctions* _preDefF)
{

    if (strcmp(functionName, _preDefF->console_print_function) == 0)
         return console_print_function;
    else
        return INVALID_FUNCTION;
    
}