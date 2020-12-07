#include "FindVariable.h"
#include "../Definations.h"

String FindVar(String data, int* index){

    String VarName = (String)malloc(sizeof(char)*30);
    int i = 0;
    while ( *(data+*index) != ' ')
    {
        *(VarName+i) = *(data+*index);
        *index += 1;
        i++;
    }

    StringVars* tempVar = stringVars;

    while ( !IsStringEmpty(tempVar->name) )
    {
        if ( !strcmp(tempVar->name, VarName) ){
            // free(VarName);
            return tempVar->val;
        }
        else if (tempVar->next)
            tempVar = (StringVars*)tempVar->next;
        else break; 
    }
    
    // free(VarName);
    return NULL;
}