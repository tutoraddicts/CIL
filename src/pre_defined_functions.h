#pragma once

#ifndef PREDEFINEDFUNCTIONS
#define PREDEFINEDFUNCTIONS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Util/string.h"
// FunctionNames Header File
/*
 * Here We are going to store all the pre defined functions names that we are going to compare with the found function name
 */

struct PreDefinedFunctions 
{
    char *console_print_function;
};
typedef struct PreDefinedFunctions PreDefinedFunctions;


enum function_Indexes{
    INVALID_FUNCTION = -1,
    console_print_function = 0,
};

// pre defined functions 

void ConsolePrintFunc(char[], int);
void RemoveStringSpaces(char[],int);
void setup_predef_functions(PreDefinedFunctions*);

#endif