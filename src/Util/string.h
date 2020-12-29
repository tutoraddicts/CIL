#pragma once
#ifndef STRING_STD_C
#define STRING_STD_C

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef char* CString;
typedef CString String;

/* 
    allocate memory according to the size you send
 */
STRING_STD_C String New_String(size_t size);
/* 
    Remove Spaces From Front of the sring if any useful insome Cases 
 */
STRING_STD_C String RemoveSpaces(String); // function to remove spaces in the string
/* 
    Return String Lenth 
 */
STRING_STD_C size_t stringLenth( const String);
/*
    __src > Source String
    __dst > Destination String
    __size > size of the src
 */
STRING_STD_C String StringCopy(String __src,String __dst, int __size);

/*
 Return 1 if empty 
 Return 0 if NotEmpty
 */
STRING_STD_C short IsStringEmpty(String __string);

#endif