#include "predefined_functions.h"
#include "../Util/Util.h"
#include "../definations.h"

PREDEFINED_FUNCTION_H int console_exit_func(String data){
    if (*data != '(')
        return Error(wrong_syntex, main_code->program_counter) & printf(" : You Might miss type : exit(0)");

    int size = strlen(data)-1;

    char* value = (data+1);
    *(value+size-1) = '\0';
    exit(StringToInt(value));
}