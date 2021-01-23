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
 * @brief Return the pointer of the data if it is a var
 * if not then return NULL;
 * @param data is the string of the code the user write
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

/**
 * @brief Will return the variable pointer if it finds a variable with same name
 * if not then will return new Var to store data;
 * @param Varname name of the variable
 * @param _var the pointer to the variable
 */
static variables* IsVarCreated(String Varname, variables* __var){
    if (__var == NULL) return NULL;
 
    if ( !strcmp(__var->name, Varname ) )
        return __var;
    else 
        return IsVarCreated(Varname, __var->next);
}

/**
 * @brief Create a String Variable object
 * @param Varname 
 * @param data 
 * @return variables* 
 */
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
    // printf("(%s) : (%d)\n",_temp_var->name, ((int_data*)_temp_var->data)->data);
    _temp_var->type = Var_Type_Int;

    return _temp_var;
}

/**
 * @brief in this function we are transfering data from one variable to another variable
 * @param data 
 * @param VarName 
 * @param existingVar 
 */
static void TransferData(String data, String VarName, variables* existingVar){

    int i = 0;
    variables* _temp = FindVar(data, &i);
    if (!_temp) return;
    
    if (existingVar == NULL){
        switch (_temp->type)
        {
        case 's':
            existingVar = CreateStringVariable(VarName, "s ");
            ((string_data*)existingVar->data)->data = StringCopy(((string_data*)_temp->data)->data, ((string_data*)existingVar->data)->data, stringLenth(((string_data*)_temp->data)->data)-1);
            break;
        case 'i':
            existingVar = CreateIntVariable(VarName, "0 ");
            if(existingVar->type == 'f')
                ((float_data*)existingVar->data)->data = ((int_data*)_temp->data)->data;
            else
                ((int_data*)existingVar->data)->data = ((int_data*)_temp->data)->data; 
            break;
        case 'f':
            existingVar = CreateFloatVariable(VarName, "0 ");
            if(existingVar->type == 'i')
                ((int_data*)existingVar->data)->data = ((float_data*)_temp->data)->data;
            else 
                ((float_data*)existingVar->data)->data = ((float_data*)_temp->data)->data;
            break;
        }

        last_node->next = existingVar;
        // printf("Creating : %s\n", last_node->next->name);
    }
    else if (_temp->type != existingVar->type)
    {
        Warning("\nWarning : Wrong Type Conversion\n");
        switch (_temp->type)
        {
        case 's':
            ((string_data*)existingVar->data)->data = StringCopy(((string_data*)_temp->data)->data, ((string_data*)existingVar->data)->data, stringLenth(((string_data*)_temp->data)->data)-1);
            break;
        case 'i':
            if(existingVar->type == 'f')
                ((float_data*)existingVar->data)->data = ((int_data*)_temp->data)->data;
            else
                ((int_data*)existingVar->data)->data = ((int_data*)_temp->data)->data; 
            break;
        case 'f':
            if(existingVar->type == 'i')
                ((int_data*)existingVar->data)->data = ((float_data*)_temp->data)->data;
            else 
                ((float_data*)existingVar->data)->data = ((float_data*)_temp->data)->data;
            break;
        default:
            break;
        }

    }else {
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
    
    // printf("transferring 3");
}

/**
 * @brief THis Function Will return Which Type of variable user wants
 * @param data 
 * @return Vartype 
 */
static Vartype WhichTypeOfVar(String data){
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
    
    data = IsThisAVar(data); // Cheacking if the instruction actually for Variable or not
    if ( data == NULL ) return;

    if (last_node == NULL){

        printf("Creating Fist Variable \n");
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
    if (  existing_var != NULL) // cheacking if the Variable Allready Created
    {
        
        switch ( WhichTypeOfVar(data) )
        {
        case 's':
            ((string_data*)existing_var->data)->data = StringCopy(data+1, ((string_data*)existing_var->data)->data, stringLenth(data)-1);
            break;
        case 'i':
            if(existing_var->type == 'f')
                ((float_data*)existing_var->data)->data = StringToInt(data);
            else
                ((int_data*)existing_var->data)->data = StringToInt(data);
            break;
        case 'f':
            if(existing_var->type == 'f')
                ((float_data*)existing_var->data)->data = StringToFloat(data);
            else
                ((int_data*)existing_var->data)->data = StringToFloat(data);
            break;
        default:
            TransferData(data, "0", existing_var);
            break;
        }
        
        return;
    }
    else {
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
            TransferData(data, Varname, last_node->next);
            break;
        }   
            last_node = last_node->next;
    }
}