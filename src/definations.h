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

EC_DEFINATIONS enum function_Indexes{
    INVALID_FUNCTION = -1,
    console_print_function = 0,
};

EC_DEFINATIONS typedef struct variables variables;

struct variables{
    variables* next;
    String name;
    String data;
};

extern variables* vars;

#endif