#include "string.h"

STRING_STD_C String New_String(size_t size){
    return (String)malloc(sizeof(char)*size);
}

STRING_STD_C String RemoveSpaces(String string)
{   
    if (*string != ' ') return; // lively improvement :)

    int index = 0;
    int size = 0;
    while ( *(string+(index)) == ' ') index++; // removing spaces from front

    while ( *(string+index) )
    {
        *(string+size) = *(string+index);
        index++;
        size++;
    }

    *(string+size) = '\0';
    return string;
}

STRING_STD_C size_t stringLenth(const String CString){
    if(IsStringEmpty(CString)) return -1;
    else return 1 + stringLenth(CString+1);
}

STRING_STD_C String StringCopy(String __src, String __dst, int __size){
    __dst = (String)malloc(__size);
    for (int i = 0; i < __size; i++) *(__dst+i) = *(__src+i); 
    return __dst;
}

STRING_STD_C short IsStringEmpty(String __string){
    return (*__string == '\0');
}