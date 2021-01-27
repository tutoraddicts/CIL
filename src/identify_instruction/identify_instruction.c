#include "identify_instruction.h"

IDENTIFY_INSTRUCTION_H funcIndex identify_instruction(const String functionName)
{
    if ( !strcmp(functionName, console_print) )
        return console_print_function;
    else if ( !strcmp(functionName, exit_ec))
        return exit_ec_function;
    else
        return INVALID_FUNCTION;
}