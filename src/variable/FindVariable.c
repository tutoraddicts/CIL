#include "FindVariable.h"


String FindVar(String data, int* index){
    String VarName = New_String(strlen(data));
    int i = 0;
    
    while ( *(data+*index) != ' ' && *(data+*index) != '+' && *(data+*index) != '\0')
    {
        *(VarName+i) = *(data+*index);
        *index += 1;
        i++;
    }

    variables* tempVar = vars;

    while ( tempVar )
    {
        if ( !strcmp(tempVar->name, VarName) ){
            return tempVar->data;
        }
        else if (tempVar->next)
            tempVar = (variables*)tempVar->next;
        else break; 
    }
    
    return "Error : No Variable Found With Such name";
}