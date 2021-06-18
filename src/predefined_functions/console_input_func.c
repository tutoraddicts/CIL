#include "predefined_functions.h"
#include "../definations.h"

static variables* IsVarCreated(String Varname, variables* __var){
    // printf("start checking if car created\n");
    
    if ( __var == NULL) return NULL;
    // cheking if the string actually empty it is I am checking this in some cases 
    //__var == NULL giving me false even though the there were no variable present
    if ( IsStringEmpty(__var->name) ) return NULL; 

    if ( strcmp(__var->name, Varname ) ){
        // printf(":%s:\n", Varname);
        return __var;
    }
    else if ( __var->next )
        return IsVarCreated(Varname, __var->next);
    else 
        return NULL;

}


PREDEFINED_FUNCTION_H void console_get_func(String data){

    char* var_name = (char*)malloc(50);

    int i = 0;
    while (data[i])
    {
        if (data[i] != ',' || data[i] != ' '){
            var_name[i] = data[i];
            i++;
        }
        else{
            var_name[i] = '\0' ;
            printf(":%s:\n", "going for second variable");
            console_get_func(data+i+1);
            break;
        }
        // else if ( IsStringEmpty(data+1) ) {
        //     printf(":%s:\n", data);
        //     console_get_func(data+1);
        //     break;
        // }
        
    }
    

    variables* existing_var = IsVarCreated(var_name, vars);

    if (existing_var != NULL){
        switch ( existing_var->type )
        {
        case 's':
            scanf("%s", ((string_data*)existing_var->data)->data);
            break;
        case 'i':
            scanf("%d", &((int_data*)existing_var->data)->data);
            break;
        case 'f':
            scanf("%f", &((float_data*)existing_var->data)->data);
            break;
        default:
            break;
        }
    }

    // printf("Running\n");
}