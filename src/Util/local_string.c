#include "local_string.h"

int StringLen(char content[]){
    int size = 0;
    while ( content[size] != '\0')
        size++;
    
    return (size+1);
}