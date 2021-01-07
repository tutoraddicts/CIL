#include "predefined_functions.h"
#include "../variable/FindVariable.h"

static int printChar(const String data, int index){

    switch ( *(data+index) ){
        case 92:
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

static void PrintVariable(variables* _varToPrint){

    if (!_varToPrint)
        return;
    int i;
    i = 0;

    switch(_varToPrint->type){
        case 's':
            while ( ((string_data*)_varToPrint->data)->data[i] )
            {
                i = printChar( ((string_data*)_varToPrint->data)->data, i);
            }
            break;
        case 'i':
            printf("%d", ((int_data*)_varToPrint->data)->data);
            break;
        case 'f':
            printf("%f", ((float_data*)_varToPrint->data)->data);
            break;
        default:
            break;
    }
}

PREDEFINED_FUNCTION_H void console_print_func(String data){
    int data_length = stringLenth(data);

    for (int i = 0; i < data_length; i++){

        switch ( *(data+i ) )
        {
        case '"':
            ++i;
            while ( *(data+i) != '"' )
                i = printChar(data, i);
            break;
        case ' ':
            break;
        case '+':
            break;
        default:
            PrintVariable(FindVar(data, &i));
            break;
        }
    }
}