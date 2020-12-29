#include "predefined_functions.h"
#include "../variable/FindVariable.h"

static int print(const String data, int index){

    switch ( *(data+index) ){
        case '/':
            if (data[index+1] == 'n'){
                ++index;
                printf("\n"); 
                break;
            }
            else if (data[index+1] == 't'){
                ++index;
                printf("\t");
                break;
            }
            
        default:
            printf("%c", data[index]);
            break;
    }

    return index+1;
}

PREDEFINED_FUNCTION_H void console_print_func(String data){
    int data_length = stringLenth(data);

    for (int i = 0; i < data_length; i++){

        switch ( *(data+i ) )
        {
        case '"':
            ++i;
            while ( *(data+i) != '"' )
                i = print(data, i);
            break;
        case ' ':
            break;
        case '+':
            break;
        default:
            printf("%s", (String)FindVar(data, &i));
            break;
        }
    }
}