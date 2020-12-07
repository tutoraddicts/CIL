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

int stringLenth(const String CString){
    if(CString == NULL) return 0;
    if (*CString) return 1 + stringLenth(CString+1);
    else return 0;
}

String StringCopy(String __src,String __dst, int __size){
    __dst = (String)realloc(__dst, __size);
    for (int i = 0; i < __size; i++)
    {
        *(__dst+i) = *(__src+i);
    }
    return __dst;
    // memcpy(__dst, __src, __size);
}

short IsStringEmpty(String __string){
    return (*__string == NULL);
}