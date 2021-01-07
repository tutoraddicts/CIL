#include "CreateVariable.h"
#include <stdlib.h>

variables* vars;
static variables* last_node = NULL;

/*
 * File Responsible to Create a Variable and Change the Value too
 * the Starting Function is CreateVariable
 */

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

static variables* CreateStringVariable(String Varname, String data){
    // printf("(%s) : (%s)", Varname, data);
    variables *_temp_var = (variables*)malloc(sizeof(sizeof(variables)));

    int name_size = strlen(Varname);
    int data_size = stringLenth(data);
            
    _temp_var->name = New_String(name_size);
    _temp_var->name = StringCopy(Varname, _temp_var->name,name_size);

    string_data *s_data = (string_data*)malloc(sizeof(string_data));
    s_data->data = New_String(data_size);
    s_data->data = StringCopy(data+1, s_data->data, data_size-1);
    _temp_var->data = s_data;
    // printf(" : (%s)\n", ((string_data*)_temp_var->data)->data);
    _temp_var->type = Var_Type_String;

    return _temp_var;
}

/**
 * @brief Create a Float Variable object
 * @param Varname 
 * @param data 
 * @return variables* 
 */
static variables* CreateFloatVariable(String Varname, String data){
    variables *_temp_var = (variables*)malloc(sizeof(sizeof(variables)));

    int name_size = strlen(Varname);
    int data_size = stringLenth(data);
            
    _temp_var->name = New_String(name_size);
    _temp_var->name = StringCopy(Varname, _temp_var->name, name_size);

    float_data* f_data = (float_data*)malloc(sizeof(float_data));
    f_data->data = StringToFloat(data);
    _temp_var->data = f_data;
    _temp_var->type = Var_Type_Float;

    return _temp_var;
}

/**
 * @brief Create a Int Variable object
 * @param Varname 
 * @param data 
 * @return variables* 
 */
static variables* CreateIntVariable(String Varname, String data){
    // printf("Creating Int Variable\n");
    variables *_temp_var = (variables*)malloc(sizeof(sizeof(variables)));

    int name_size = strlen(Varname);
    int data_size = stringLenth(data);
            
    _temp_var->name = New_String(name_size);
    _temp_var->name = StringCopy(Varname, _temp_var->name, name_size);

    int_data* i_data = (int_data*) malloc(sizeof(int_data));
    i_data->data = StringToInt(data);
    // printf("%d\n", i_data->data);
    _temp_var->data = i_data;
    // printf("%d\n", ((int_data*)_temp_var->data)->data);
    _temp_var->type = Var_Type_Int;

    return _temp_var;
}

/**
 * @brief THis Function Will return Which Type of variable user wants
 * @param data 
 * @return Vartype 
 */
static Vartype WhichTypeOfVar(String data){
    if (*data == '"')   return Var_Type_String;
    else {
        int i = 0;
        while ( data[i] )
        {
            if (data[i] == '.') return Var_Type_Float;
            i++;
        }
        
        return Var_Type_Int;
    }
}

/*
 * Create Your Variable Really Quick or just change the value of existing Variable
 */
void CreateVariable(String Varname, String data){
    
    data = IsThisAVar(data); // Cheacking if the instruction actually for Variable or not
    if ( data == NULL ) return;
    variables* existing_var = IsVarCreated(Varname, vars);
    if (  existing_var != NULL) // cheacking if the Variable Allready Created
    {
        // printf("Changing Value\n");
        switch ( WhichTypeOfVar(data) )
        {
        case 's':
            ((string_data*)existing_var->data)->data = StringCopy(data+1, ((string_data*)existing_var->data)->data, stringLenth(data)-1);
            break;
        case 'i':
            ((int_data*)existing_var->data)->data = StringToInt(data);;
            break;
        case 'f':
            ((float_data*)existing_var->data)->data = StringToFloat(data);
            break;
        default:
            break;
        }
        
        return;
    }
    else {
        if (last_node == NULL){

            switch (WhichTypeOfVar(data))
            {
            case 's':
                vars = CreateStringVariable(Varname, data);
                break;
            case 'i':
                vars = CreateIntVariable(Varname, data);
                break;
            case 'f':
                vars = CreateFloatVariable(Varname, data);
                break;
            default:
                break;
            }
                
            last_node = vars;
        }else {
            switch (WhichTypeOfVar(data))
            {
            case 's':
                last_node->next = CreateStringVariable(Varname, data);
                break;
            case 'i':
                last_node->next = CreateIntVariable(Varname, data);
                break;
            case 'f':
                last_node->next = CreateFloatVariable(Varname, data);
                break;
            default:
                break;
            }
            
            last_node = last_node->next;
        }
    }
}