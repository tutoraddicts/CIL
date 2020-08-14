#include "string.h"

void RemoveStringSpaces(char content[], int index)
{    
    while ( content[index] == ' ') // removing spaces from front
        index++;    

    int sizeOfData = strlen(content)-index;
    char data[512] = "";
    int i = 0;
    while (content[index])
    {
        data[i++] = content[index++];
    }

    sizeOfData = stringLenth(data);
    // content = (char*)malloc(sizeof(char)*sizeOfData);
	strcpy(content, data);

    // sizeOfData = stringLenth(content);
    // content = (char*)realloc(content, sizeOfData*sizeof(char));
    // printf(content);
}

int stringLenth(char* CString){
    int size = 0,
        index = 0;
    while ( *(CString+(index++)) )  size++;
    return size;
}