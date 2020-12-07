#pragma once

#include "Util/string.h"

enum function_Indexes{
    INVALID_FUNCTION = -1,
    console_print_function = 0,
};
typedef enum function_Indexes funcIndex;

// Function names
static const char *Sprint = "print"; // print data



typedef struct 
{
    struct _IntVars* next;
    String name;
    int val;
}_IntVars;

typedef struct 
{
    struct _FloatVars* next;
    String name;
    float val;
}_FloatVars;

typedef struct 
{
    struct _CharVars* next;
    String name;
    char val;
}_CharVars;

typedef struct 
{
    struct StringVars* next;
    String name;
    String val;
}StringVars;

extern StringVars* stringVars;