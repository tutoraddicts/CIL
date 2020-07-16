#include "pre_defined_functions.h"

void RemoveStringSpaces(char content[],int index)
{
    int conTentSize = (sizeof(content)/sizeof(char)); // calculating total size of our string
    
    while ( content[index] == ' ') // removing spaces after the function
        index++;    

    int sizeOfData = (sizeof(content)/sizeof(char))-index;
    char data[sizeOfData];
    int i = 0;
    for (i = 0; i < sizeOfData; i++)
        data[i] = content[index++];

    index = i+1;
    content = (char*) malloc(sizeof(data));
	strcpy(content, data);
}

void ConsolePrintFunc(char content[], int index)
{
    RemoveStringSpaces(content, index);
    int sizeOFData = sizeof(content)/sizeof(char);
    if (content[0] != '"')
        printf ("Invalid Syntax");
    else if (content[0] == '"' && content[1] == '"')
        printf("");
    else
    {
        int i = 0;
        for (i = 1; i < sizeOFData; i++)
        {
            if (content[i] == '"')
                break;
            content[i-1] = content[i];
        }
    }
    printf("%s", content);
}
