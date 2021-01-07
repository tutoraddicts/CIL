#include<stdio.h>
#include "ErrorWarningPrint.h"

int Error(const char* massage){

    printf("\033[0;31m");
    printf(massage);
    printf("\033[0m");
}

int Warning(const char* massage){
    printf("\033[0;33m");
    printf(massage);
    printf("\033[0m");
}