#include "live_enviornment.h"

LIVE_ENVIORNMENT_H int LiveEnviornment(){
    const char* Massage= "THis is a live Enviornment for EC so use it wisely and remember my last name.\nAnd also remember exit to exit the CLI\n";
    printf(Massage);
    String data = (String)malloc(sizeof(char)*512);

    while (1){
        printf(">>");
        fgets(data, 512, stdin);
        do_run(data);
        printf("\n");
    }
    
    return -1;
}