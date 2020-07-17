#include "pre_defined_functions.h"

void RemoveStringSpaces(char content[],int index)
{    
    while ( content[index] == ' ') // removing spaces after the function
        index++;    

    int sizeOfData = strlen(content)-index;
    char data[512] = "";

    for (int i = 0; i < sizeOfData; i++)
    {
        data[i] = content[index];
        index++;
    }

	strcpy(content, data);
}

void ConsolePrintFunc(char content[], int index)
{
    // printf("in print");
    RemoveStringSpaces(content, index);
    int sizeOFData = strlen(content);
   
    if (content[0] != '"')
        printf ("Invalid Syntax");
    else if (content[0] == '"' && content[1] == '"')
        printf("");
    else
    {
        for (int i = 1; i < sizeOFData-1; i++)
        {
            if (content[i] == '"')
                break;
            else if (content[i] == '/' && content[i+1] == 'n')
            {
                i += 2;
                printf("\n");
                continue;
            }
            else if (content[i] == '/' && content[i+1] == 't')
            {
                i += 2;
                printf("\t");
                continue;
            }
            printf("%c", content[i]);
        }
    }
}
