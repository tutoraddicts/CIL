#include "identify_function.h"

funcIndex IdentifyFunction(char *functionName)
{
    // Settings up pre def functions with there name
    static PreDefinedFunctions _PreDefinedFunctions;
    setup_predef_functions(&_PreDefinedFunctions);

    // mean user want to print any function
    if (strcmp(functionName, _PreDefinedFunctions.console_print_function) == 0) { 
        return console_print_function;
    }else {
        return INVALID_FUNCTION;
    }
}