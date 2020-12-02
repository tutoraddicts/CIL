#include "string.h"

String New_String(size_t size){
    return (String)malloc(sizeof(char)*size);
}

String RemoveSpaces(String string, int index)
{    
    while ( *(string+(index++)) == ' '); // removing spaces from front      
    string = string + index - 1;
    return string;
}

int stringLenth(String CString){
    if (*CString) return 1 + stringLenth(CString+1);
    else return 0;
}

void StringCopy(String __src, String __dst){
    size_t __size = stringLenth(__src);
    __dst = (String)malloc(__size);
    memcpy(__dst, __src, __size);
}