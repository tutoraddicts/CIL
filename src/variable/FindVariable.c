#include "FindVariable.h"


variables* FindVar(const String data, int* index)
{

    // printf("Finding var > %s <\n", data+*index);
    // if ( IsStringEmpty(data+*index) ) return;

    int length = strlen(data);
    String VarName = New_String(20);
    int i = 0;
    
    while ( *(data+*index) != ' ' && *(data+*index) != '+' && *(data+*index) != '\0' && *(data+*index) != '\n')
    {
        *(VarName+i) = *(data+*index);
        *index += 1;
        i++;
    }

    *(VarName+i) = '\0';

    // printf("\nvarName : (%s):(%d) : (%s)\n", VarName,strlen(VarName), vars->name);

    variables* tempVar = vars;

    while ( tempVar )
    {
        // printf("Finding > %s, %s\n", tempVar->name, VarName);
        if ( Stringcomp(tempVar->name, VarName) ){
            // printf("Found");
            return tempVar;
        }
        else if (tempVar->next)
            tempVar = (variables*)tempVar->next;
        else break; 
    }
    
    Error(no_variable, 0);
    Warning(tip, 0);
    return NULL;
}