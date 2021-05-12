#include "string.h"

STRING_STD_C String New_String(size_t size)
{
    return (String)malloc(sizeof(char)*size);
}

STRING_STD_C String RemoveSpaces(String string)
{   
    if (*string != ' ') return string; // lively improvement :)

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

STRING_STD_C size_t stringLenth(const String CString)
{
    if(IsStringEmpty(CString)) return -1;
    else return 1 + stringLenth(CString+1);
}

STRING_STD_C String StringCopy(String __src, String __dst, int __size)
{
    __dst = (String)malloc(__size);
    for (int i = 0; i < __size; i++) *(__dst+i) = *(__src+i); 
    return __dst;
}

STRING_STD_C String StringCopyExcept(String __src,String __dst, int __size,char __exceptChar){
     __dst = (String)malloc(__size);
    for (int i = 0; i < __size; i++) {
        if (*(__src+i) == __exceptChar){
            *(__dst+i) = '\0';
            return __dst;
        }
        else
            *(__dst+i) = *(__src+i); 
    }
    return __dst;
}

STRING_STD_C short IsStringEmpty(String __string)
{
    return ( !*__string || *__string == '\0' || *__string == '\n');
}

STRING_STD_C short Stringcomp(const String __str1,const String __str2)
{
    if ( !*__str1 || !*__str2 ) return 1;
    
    if ( *__str1 == *__str2){
        if ( *(__str1+1) && *(__str2+1) ){
            return 1 * Stringcomp(__str1+1, __str2+1);
        }
        else {
            return 1;
        }
    }else {
        return 0;
    }
}

