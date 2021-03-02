#include "live_enviornment.h"

static int store_code(char* line){

    static const u_int16_t line_max_size = 512;

    if (!main_code){
        main_code = (code_mem*)malloc(sizeof(code_mem)); 
    }


    // line = RemoveSpaces(line);
    int size_line = strlen(line);

    main_code->code = (char**)realloc(main_code->code, sizeof(char*)*main_code->no_of_line+1);
    main_code->code[main_code->no_of_line] = (char*)malloc(sizeof(char)*size_line);
    
    if ( !IsStringEmpty(line) ){
        main_code->code[main_code->no_of_line] = StringCopy(line, main_code->code[main_code->no_of_line], size_line);
    }else {
        main_code->code[main_code->no_of_line] = "\0";
    }
    


    main_code->no_of_line++;
}


LIVE_ENVIORNMENT_H int LiveEnviornment(){
    static const char* Massage= "This is a live Enviornment for EC so use"
                            "it wisely and remember my last name.And "
                            "also remember exit to exit the CLI\n";
    printf("%s", Massage);
    String data = (String)malloc(sizeof(char)*512);

    while (1){
        printf(">> ");
        fgets(data, 512, stdin);
        store_code(data);
        do_run(main_code->code[main_code->program_counter++]);
        // do_run(data);
    }
    
    return -1;
}