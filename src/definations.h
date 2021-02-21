#ifndef EC_DEFINATIONS
#define EC_DEFINATIONS

#include "Util/Util.h"

#pragma once

// Error Massages
EC_DEFINATIONS static const String no_args = "ERROR : No File Inserted\n";
EC_DEFINATIONS static const String wrong_extension = "ERROR : Use .ec in the end of the file my boy :)\n";
EC_DEFINATIONS static const String no_such_file = "ERROR : There is no file with such name\n";
EC_DEFINATIONS static const String wrong_syntex = "ERROR : Wrong Syntex";

EC_DEFINATIONS static const String no_var_found = "WARNING : No Variable Found Witch Such Name";
// Names
EC_DEFINATIONS static const String extension_name = ".ec";
EC_DEFINATIONS static const String console_print = "say"; // print data
EC_DEFINATIONS static const String exit_ec = "exit"; 

EC_DEFINATIONS typedef enum function_Indexes funcIndex; // index for predefined Function
EC_DEFINATIONS typedef enum instruction_index incIndex; // index for instructions

EC_DEFINATIONS typedef char Vartype;

EC_DEFINATIONS typedef struct variables variables; // all type of created Variables
EC_DEFINATIONS typedef struct int_data int_data; // integer type of data
EC_DEFINATIONS typedef struct float_data float_data; // float type of data
EC_DEFINATIONS typedef struct string_data string_data; // string type of data you can also store char data too

EC_DEFINATIONS typedef struct code_mem code_mem;

EC_DEFINATIONS enum function_Indexes{
    INVALID_FUNCTION = -1,
    console_print_function = 0,
    exit_ec_function,
};

EC_DEFINATIONS enum instruction_index{
    ADDITION = '+',
    SUBTRACTION = '-',
    DIVISION = '/',
    MULTIPLICATION = '*',
};

EC_DEFINATIONS enum argument_index{
    file_name = 1,
    options = 2,
};

/*
 * Charecter to identify the variable Type
 * f -> for a float type variable
 * i -> integer type variable
 * s -> string type variable
 */
EC_DEFINATIONS static const Vartype Var_Type_Int = 'i';
EC_DEFINATIONS static const Vartype Var_Type_Float = 'f';
EC_DEFINATIONS static const Vartype Var_Type_String = 's';

struct int_data{
    int data;
};
struct float_data{
    float data;
};
struct string_data{
    String data;
};
struct variables{
    variables* next;
    String name;
    void* data;
    Vartype type;
};

/**
 * @brief This is the code memory stack where are storing the code in a array
 * We do not need too big of data
 * max line size will be 512 initially
 */
struct code_mem{
    char** code;
    size_t no_of_line;
    size_t program_counter;
};

extern variables* vars;
extern code_mem* main_code;

#endif