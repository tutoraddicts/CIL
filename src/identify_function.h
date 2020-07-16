#pragma once 
#ifndef IDENTIFY_FUNCTION_H
#define IDENTIFY_FUNCTION_H

#include <string.h>

#include "pre_defined_functions.h"

/*
 * This header file contain  functions to identify the function and return the index of the function 
 * by whihc letter we gonna identify what we have to do next
 */
    typedef enum function_Indexes funcIndex;

    // this is the function which will identify the functions index 
    funcIndex IdentifyFunction(char[]); 
    
    // Group the functions with there frst letter
    funcIndex PTypeFunctions(char[]);

#endif