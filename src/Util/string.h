#pragma once

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define New New_
typedef char* String;

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
int stringLenth(String);
/*
    __src > Source String
    __dst > Destination String
    __size > size of the src
 */
void StringCopy(String __src, String __dst);