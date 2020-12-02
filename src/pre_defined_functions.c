#include "pre_defined_functions.h"

void ConsolePrintFunc(char *content, int index)
{
    // printf("in print");
    content = RemoveSpaces(content, index);
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

void CreateVariabel(char* varName, char* value){
    
}

void setup_predef_functions(PreDefinedFunctions* _preDefF){

    _preDefF->console_print_function = (char*)malloc(6*sizeof(char));
    _preDefF->console_print_function = "print";
}