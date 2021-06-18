#include "Calculations.h"
#include "../definations.h"
#include "../Util/Util.h"

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


void* Do_Calculation(String data){

    data = RemoveSpaces(data);

    if (*data != '(') //OP
        return 0;

    int length = stringLenth(data);
    String Instruction = (String)malloc(sizeof(char)*length);

    int i = 1;  
    while (*(data+i) != ')')
    {
        *(Instruction+i-1) = *(data+i);
        i++;
    }
    *(Instruction+i) = '\0';
    Instruction = RemoveSpaces(Instruction);
    i = stringLenth(Instruction);
    String vardata = (String)malloc(sizeof(char)*50);
    for (int j = 0; j < i ; j++){
        if (Instruction[j] == ADDITION );
        else if ( Instruction[j] == SUBTRACTION );
        else if ( Instruction[j] == DIVISION );
        else if ( Instruction[j] == MULTIPLICATION );
        else {
            vardata[i];
        }
        
    }


}