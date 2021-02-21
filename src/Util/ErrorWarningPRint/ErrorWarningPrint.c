#include<stdio.h>
#include "ErrorWarningPrint.h"

int Error(const char* massage,  int program_counter){
    va_list args;
    printf("\033[0;31m");
    printf(massage, program_counter+1);
    printf("\033[0m");
}

int Warning(const char* massage, int program_counter){
    printf("\033[0;33m");
    printf(massage, program_counter+1);
    printf("\033[0m");
}