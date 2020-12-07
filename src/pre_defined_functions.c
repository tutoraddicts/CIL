#include "pre_defined_functions.h"
#include "Variable/FindVariable.h"

static int print(String, int);

void ConsolePrintFunc(String content, int index)
{
    String tmp;
    content = RemoveSpaces(content, index);
    int sizeOFData = strlen(content)-1;

    for (int i = 0; i < sizeOFData; i++)
    {
        switch (content[i])
        {
            case '"':
                ++i;
                while (content[i] != '"')
                {
                    i = print(content, i);
                    ++i;
                }
                if (content[i+1] == ' '){
                    ++i;
                    while (content[i+1] != '+' && i < sizeOFData) ++i;
                }
        
            break;
            
            case '+':
                while (content[i+1] == ' ') ++i;
                
            break;

            case ' ':
                break;
            default :
                tmp = FindVar(content, &i);
                if ( !IsStringEmpty(tmp) ){
                    printf("%s", tmp);
                } 
            break;
        }
    }
}

static int print(String data, int index){
    switch (data[index])
    {
        case '/':
                
            if (data[index+1] == 'n'){
                ++index;
                printf("\n");
            }
            else if (data[index+1] == 't'){
                ++index;
                printf("\t");
            }
            else 
                printf("%c", data[index]);

        break;
    
        default:

            printf("%c", data[index]);

        break;
    }

    return index;
}