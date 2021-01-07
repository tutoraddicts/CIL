#ifndef EC_DEFINATIONS
#define EC_DEFINATIONS

#include "Util/Util.h"

#pragma once

// Error Massages
EC_DEFINATIONS static const String no_args = "No File Inserted\n";
EC_DEFINATIONS static const String wrong_extension = "Use .ec in the end of the file my boy :)\n";
EC_DEFINATIONS static const String no_such_file = "There is no file with such name\n";

// Names
EC_DEFINATIONS static const String extension_name = ".ec";
EC_DEFINATIONS static const String console_print = "say"; // print data

EC_DEFINATIONS typedef enum function_Indexes funcIndex;
EC_DEFINATIONS typedef char Vartype;
EC_DEFINATIONS typedef struct variables variables;
EC_DEFINATIONS typedef struct int_data int_data;
EC_DEFINATIONS typedef struct float_data float_data;
EC_DEFINATIONS typedef struct string_data string_data;

EC_DEFINATIONS enum function_Indexes{
    INVALID_FUNCTION = -1,
    console_print_function = 0,
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

extern variables* vars;

#endif