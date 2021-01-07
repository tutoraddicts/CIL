#include "FindVariable.h"


variables* FindVar(String data, int* index){
    // printf("Transferring\n");
    int length = strlen(data);
    String VarName = New_String(length);
    int i = 0;
    // printf("Transferring 2\n");
    while ( *(data+*index) != ' ' && *(data+*index) != '+' && *(data+*index) != '\0' && *(data+*index) != '\n')
    {
        *(VarName+i) = *(data+*index);
        *index += 1;
        i++;
    }
    *(VarName+i) = '\0';

    // printf("\nvarName : (%s):(%d) : (%s)", VarName,strlen(VarName), vars->name);
    variables* tempVar = vars;

    while ( tempVar )
    {
        if ( !strcmp(tempVar->name, VarName) ){
            return tempVar;
        }
        else if (tempVar->next)
            tempVar = (variables*)tempVar->next;
        else break; 
    }
    
    Error("\nError : No Variable Found With Such name\n");
    Warning("Tip :: Make Sure You have a Line Break at the end if this occurs at the last line of the code\n");
    return NULL;
}