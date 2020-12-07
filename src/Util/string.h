#pragma once

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define New New_
typedef char* CString;
typedef CString String;

/* 
    allocate memory according to the size you send
 */
String New_String(size_t size);
/* 
    Remove Spaces From Front of the sring if any useful insome Cases 
 */
String RemoveSpaces(String ,int); // function to remove spaces in the string
/* 
    Return String Lenth 
 */
int stringLenth( const String);
/*
    __src > Source String
    __dst > Destination String
    __size > size of the src
 */
String StringCopy(String __src,String __dst, int __size);

/*
 Return 1 if empty 
 Return 0 if NotEmpty
 */
short IsStringEmpty(String __string);