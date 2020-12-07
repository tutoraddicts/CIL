#include "CreateVariable.h"

void CreateVariable(String Varname, String data, int index){

    StringVars* tempVar = stringVars;
    while ( !IsStringEmpty( tempVar->name ) )
    {
        if ( tempVar->next != NULL )
            tempVar = tempVar->next;
        else
        {
            tempVar->next = CreateStringVars();
            tempVar = tempVar->next;
            break;
        }
        
    }
    
    if ( IsStringEmpty( tempVar->name ) ){
        tempVar->name = StringCopy(Varname, tempVar->name, stringLenth(Varname));
        while (data[index] != '=') ++index;
        ++index;
        while (data[index] == ' ') ++index;

        data = data+index;
        
        tempVar->val = StringCopy(data, tempVar->val, stringLenth(data)-1);
    }  
}

StringVars* CreateStringVars(){
    StringVars* tmpVar = (StringVars*)malloc(sizeof(StringVars));

	tmpVar->name = (String)malloc(sizeof(String));
	tmpVar->val = (String)malloc(sizeof(String));

    return tmpVar;
}