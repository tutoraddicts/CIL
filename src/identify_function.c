#include "identify_function.h"

funcIndex IdentifyFunction(const String functionName)
{
    if (!strcmp(functionName, Sprint))      return console_print_function;
    else                                    return INVALID_FUNCTION;
}