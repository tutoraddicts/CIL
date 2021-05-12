#include "CreateVariable.h"
#include <stdlib.h>

variables* vars;
static variables* last_node = NULL;

static Vartype WhichTypeOfVar(String data);

/*
 * File Responsible to Create a Variable and Change the Value too
 * the Starting Function is CreateVariable
 */

/**
 * @brief Will return the variable pointer if it finds a variable with same name
 * if not then will return new Var to store data;
 * @param Varname name of the variable
 * @param _var the pointer to the variable
 */
static variables* IsVarCreated(String Varname, variables* __var){
    // printf("start checking if car created\n");
    if ( __var == NULL) return NULL;
    // cheking if the string actually empty it is I am checking this in some cases 
    //__var == NULL giving me false even though the there were no variable present
    if ( IsStringEmpty(__var->name) ) return NULL; 

    if ( Stringcomp(__var->name, Varname ) )
        return __var;
    else if ( __var->next )
        return IsVarCreated(Varname, __var->next);
    else 
        return NULL;

}

/**
 * @brief Create a String Variable object
 * @param Varname 
 * @param data 
 * @return variables* 
 */
static variables* CreateStringVariable(String Varname, String data){
    variables *_temp_var = (variables*)malloc(sizeof(sizeof(variables)));

    _temp_var->next = NULL;

    int name_size = strlen(Varname);
    int data_size = stringLenth(data);

    if ( *data == '"') data++;

    _temp_var->name = New_String(name_size);
    _temp_var->name = StringCopy(Varname, _temp_var->name,name_size);

    string_data *s_data = (string_data*)malloc(sizeof(string_data));
    s_data->data = New_String(data_size);
    s_data->data = StringCopy(data, s_data->data, data_size-1);
    _temp_var->data = s_data;
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

    _temp_var->next = NULL;

    int name_size = strlen(Varname);
    int data_size = stringLenth(data);
            
    _temp_var->name = New_String(name_size);
    _temp_var->name = StringCopy(Varname, _temp_var->name, name_size);

    float_data* f_data = (float_data*)malloc(sizeof(float_data));
    f_data->data = StringToFloat(data);
    _temp_var->data = (void*)f_data;
    _temp_var->type = Var_Type_Float;

    // printf("float var created > \n");
    return _temp_var;
}

/**
 * @brief Create a Int Variable object
 * @param Varname 
 * @param data 
 * @return variables* 
 */
static variables* CreateIntVariable(String Varname, String data){
    variables *_temp_var = (variables*)malloc(sizeof(sizeof(variables)));

    // printf("var_data : %s:", data);

    _temp_var->next = NULL;

    int name_size = strlen(Varname);
    int data_size = stringLenth(data);
            
    _temp_var->name = New_String(name_size);
    _temp_var->name = StringCopy(Varname, _temp_var->name, name_size);

    int_data* i_data = (int_data*) malloc(sizeof(int_data));
    // printf("data : %d:\n", StringToInt(data));
    i_data->data = StringToInt(data);
    _temp_var->data = (void*)i_data;
    _temp_var->type = Var_Type_Int;

    return _temp_var;
}

/**
 * @brief in this function we are transfering data from one variable to another variable
 * @param data 
 * @param VarName 
 * @param existingVar prev created variable
 */
static void TransferData(const String data, String VarName, variables* existingVar){

    // printf("Transfering data > (%s) (%s)\n", data, VarName);
    int i = 0;
    
    variables* _temp = FindVar(data, &i);
    if (!_temp) return;
    
    // printf("Done Finding Variable\n");

    if (existingVar == NULL){

        // printf("existing var is null need to create first\n");
        switch (_temp->type)
        {
        case 's':
            existingVar = CreateStringVariable(VarName, ((string_data*)_temp->data)->data);
            break;
        case 'i':
            existingVar = CreateIntVariable(VarName, "0");
            ((int_data*)existingVar->data)->data = ((int_data*)_temp->data)->data; 
            break;
        case 'f':
            existingVar = CreateFloatVariable(VarName, "0.0");
            ((float_data*)existingVar->data)->data = ((float_data*)_temp->data)->data;
            break;
        }

        last_node->next = existingVar;
    }
    else if (_temp->type != existingVar->type)
    {
        // printf("type convertion\n");
        Warning(Wrong_type_convertion, main_code->program_counter);
        switch (existingVar->type)
        {
        case 's':

            if ( _temp->type == 'i')
                ((string_data*)existingVar->data)->data = (String)((int_data*)_temp->data)->data;
            else if ( _temp->type == 'f')
                ((string_data*)existingVar->data)->data = (String)(int)((float_data*)_temp->data)->data; 
            break;

        case 'i':

            if ( _temp->type == 's')
                ((int_data*)existingVar->data)->data = (int)((string_data*)_temp->data)->data;
            else if ( _temp->type == 'f')
                ((int_data*)existingVar->data)->data = (int)((float_data*)_temp->data)->data;                
            break;

        case 'f':
            
            if ( _temp->type == 's')
                ((float_data*)existingVar->data)->data = (int)((string_data*)_temp->data)->data;
            else if ( _temp->type == 'i')
                ((float_data*)existingVar->data)->data = ((int_data*)_temp->data)->data;
                
            break;

        }

    }
    else {

        // printf("data transfer\n");
        switch (_temp->type)
        {
        case 's':
            ((string_data*)existingVar->data)->data = StringCopy(((string_data*)_temp->data)->data, ((string_data*)existingVar->data)->data, stringLenth(((string_data*)_temp->data)->data)-1);
            break;
        case 'i':
            ((int_data*)existingVar->data)->data = ((int_data*)_temp->data)->data;
            break;
        case 'f':
            ((float_data*)existingVar->data)->data = ((float_data*)_temp->data)->data;
            break;
        default:
            break;
        }
    }
    
}

/**
 * @brief THis Function Will return Which Type of variable user wants
 * @param data 
 * @return Vartype 
 */
static Vartype WhichTypeOfVar(String data){
    // printf("checking which type of var is this > %s\n", data);

    if (*data == '"')   return Var_Type_String;
    else if ((*data == '-') || (*data > 47 && *data < 58)){
        int i = 0;
        while ( data[i] )
        {
            if (data[i] == '.') return Var_Type_Float;
            i++;
        }
        
        return Var_Type_Int;
    }

    return 0;
}

/**
 * @brief Create Your Variable Really Quick or just change the value of existing Variable
 * @param Varname variable Name
 * @param data data related to variable
 */
void CreateVariable(String Varname, String data){

    if ( data == NULL ) return;

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
        return;
    }

    variables* existing_var = IsVarCreated(Varname, vars);
    // printf("done checking existing var\n");
    if (  existing_var != NULL ) // cheacking if the Variable Already Created
    {
        // printf("Found Existing Variable\n");
        switch ( WhichTypeOfVar(data) )
        {
        case 's':
            ((string_data*)existing_var->data)->data = StringCopy(data+1, ((string_data*)existing_var->data)->data, stringLenth(data)-1);
            break;
        case 'i':
            ((int_data*)existing_var->data)->data = StringToInt(data);
            break;
        case 'f':
            // printf("float var\n");
            ((float_data*)existing_var->data)->data = StringToFloat(data);
            break;
        default:
            TransferData(data, "0", existing_var);
            // printf("done Transfering\n");
            break;
        }
        
        return;
    }
    else {
        
        // printf("crating var : %s, %s\n", Varname, data);
        char type = WhichTypeOfVar(data);
        // printf("%c\n", type);
        switch (type)
        {
        case 's':
            last_node->next = CreateStringVariable(Varname, data);
            break;
        case 'i':
            last_node->next = CreateIntVariable(Varname, data);
            break;
        case 'f':
            // printf("float var\n");
            last_node->next = CreateFloatVariable(Varname, data);
            break;
        default:
            TransferData(data, Varname, last_node->next);
            break;
        }   
        
        last_node = last_node->next;
    }
}