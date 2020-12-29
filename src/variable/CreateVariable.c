#include "CreateVariable.h"
#include <stdlib.h>

variables* vars;
static variables* last_node = NULL;
/*
 return the pointer of the data if it is a var
 if not then return NULL;
 */
static String IsThisAVar(String data) {
    data = RemoveSpaces(data);
    if (*data=='='){
        *data = ' ';
        data = RemoveSpaces(data);
        return data;
    }else {
        return NULL;
    }
}

/*
 * Will return the variable pointer if it finds a variable with same name
 * if not then will return new Var to store data;
 */
static variables* IsVarCreated(String Varname, variables* __var){
    if (__var == NULL) return NULL;

    if ( !strcmp(__var->name, Varname ) )
        return __var;
    else 
        return IsVarCreated(Varname, __var->next);
}

/*
 * data_size -> size of the data
 * name_size -> size of the name of the variable
 */
static variables* CreateStringVariable(size_t data_size, size_t name_size){
    variables *_temp_var = (variables*)malloc(sizeof(sizeof(variables)));

    _temp_var->data = New_String(data_size);
    _temp_var->name = New_String(name_size);

    return _temp_var;
}

void CreateVariable(String Varname, String data){
    
    data = IsThisAVar(data);
    if ( data == NULL ) return;
    if ( IsVarCreated(Varname, vars) != NULL)
    {
        // printf("Creating\n");
        return;
    }
    else {
        if (last_node == NULL){
            int name_size = strlen(Varname);
            int data_size = stringLenth(data);
            vars = CreateStringVariable(name_size, data_size);
            vars->name = StringCopy(Varname, vars->name,name_size);
            if ( *data == '"'){
                vars->data = StringCopy(data+1, vars->data,data_size-2);
            }else {
                vars->data = StringCopy(data, vars->data,data_size);
            }
            last_node = vars;
        }else {
            // printf("Creating\n");
            int name_size = strlen(Varname);
            int data_size = stringLenth(data);
            last_node->next = CreateStringVariable(name_size, data_size);
            last_node->next->name = StringCopy(Varname, last_node->next->name, name_size);
            // printf("%s\n", last_node->next->name);
            if ( *data == '"'){
                last_node->next->data = StringCopy(data+1, last_node->next->data, data_size-2);
            }else {
                last_node->next->data = StringCopy(data, last_node->next->data, data_size);
            }
            last_node = last_node->next;
        }
    }
}