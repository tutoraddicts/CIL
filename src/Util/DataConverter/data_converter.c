#include"data_converter.h"
#define MulFactor 10

#include<string.h>

static int float_starting = 0;
static int String_Length = 0;

int StringToInt(const String Data){
    if (!Data){
        printf("Error Wrong Data\n");
        return 0;
    }
        
    int res = 0;
    int sign = 1;
    int i = 0;

    if (Data[i] == '-'){
        sign = -1;
        i++;
    }
    if (Data[i] < '0' && Data[i] > '9'){
        printf("Error\n");
        return 0; // error Data Is wrong    
    }

    res = (Data[i]-48);

    int String_Length = stringLenth(Data)+1;

    for (i += 1; i < String_Length; i++){
        if ( Data[i] < '0' && Data[i] > '9' ){
            printf("Warning : This is not a number\n");
            break;
        }else if ( Data[i] == '.'){
            float_starting = i+1;
            break;
        }
            
        
        res *= MulFactor;
        res += ((int)Data[i])-48; 
    }

    // printf("%d\n", res);

    return res*sign;
}

float StringToFloat(String Data){
    float res = StringToInt(Data);


    float _res = (Data[float_starting]-'0');

    // printf ("%f\n", _res);

    for (int i = float_starting+1; i < String_Length; i++){
        if ( Data[i] < '0' && Data[i] > '9' ){
            printf("Warning : This is not a number\n");
            break;
        }
            
        _res *= MulFactor;
        _res += ((int)Data[i])-48; 
    }

    // printf ("%f\n", _res);

    res += _res/10;
    return res;
}