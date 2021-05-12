#include <stdio.h>
#include "definations.h"
#include "identify_instruction/identify_instruction.h"
#include "predefined_functions/predefined_functions.h"
#include "Util/Util.h"
#include "variable/CreateVariable.h"
#include "live_enviornment/live_enviornment.h"
#include "do_run.h"

code_mem* main_code;

// Cheking if the extension of our file is correct
static int is_extension_correct(String file_name);
// Storing the instructions in the stack easier to work with
static int store_code(char* line);

/**
 * @brief Main function where our programing starting ezz :P
 * @param args 
 * @param file_name 
 * @return int 
 */
int main(int args, String *arguments) {

    if (args < 2){
        Error(no_args, -1) 
        return LiveEnviornment() ;
    } 

    for (int i = 1; i < args; i++){
        switch (i)
        {
        case 1:
            if ( !is_extension_correct(arguments[1]) ){
                return Error(wrong_extension, -1);
            }
            break;
        case 2:
            if ( !strcmp(arguments[2], "-g") ) printf("Generating C programe");
            break;
        default:
            break;
        }
    }

    FILE *pToFile = fopen(arguments[1], "r");

    if (!pToFile) return printf(no_such_file);

    const String data = (String)malloc(sizeof(char)*512);

    while ( fgets( data, 512, pToFile) ) // Get input from the file line by line
	{
        store_code(data); // storing the code will be usefull in future version
        // DO_RUN_H do_run(data);
    }

    fclose(pToFile);
    free(data);

    // // fix last line issue
    // {
    //     printf(main_code->code[main_code->no_of_line-1]);
    //     // free(main_code->code[main_code->no_of_line]);
    //     // char* temp = main_code->code[main_code->no_of_line];
    //     // printf(temp);
    //     // temp[strlen(temp)-1] = '\0';
    // }
    
    printf("\n-------------------------------------------------------------\n");
    for ( main_code->program_counter = 0; main_code->program_counter < main_code->no_of_line; main_code->program_counter++){
        if ( !IsStringEmpty(main_code->code[main_code->program_counter]) ){
            do_run(main_code->code[main_code->program_counter]);
            free(main_code->code[main_code->program_counter]);
        }
            
    }
    printf("\n-------------------------------------------------------------\n");
    free(main_code);
    

    return 0;
}

/**
 * @brief Storing the instructions in the stack easier to work with
 * 
 * @param line 
 * @return int 
 */
static int store_code(char* line){

    static const u_int16_t line_max_size = 512;

    if (!main_code){
        main_code = (code_mem*)malloc(sizeof(code_mem)); 
    }


    // line = RemoveSpaces(line);
    int size_line = strlen(line);

    

    main_code->code = (char**)realloc(main_code->code, sizeof(char*)*main_code->no_of_line+1);
    main_code->code[main_code->no_of_line] = (char*)malloc(sizeof(char)*size_line);
    
    if (size_line < 2) {
        main_code->code[main_code->no_of_line] = "\n";
        main_code->no_of_line++;
        return;
        
    }
    // printf("%s : %d\n",line, strlen(line));
    if ( !IsStringEmpty(line) ){
        main_code->code[main_code->no_of_line] = StringCopyExcept(line, main_code->code[main_code->no_of_line], size_line, '#');
    }else {
        main_code->code[main_code->no_of_line] = "\0";
    }
    


    main_code->no_of_line++;
}

/**
 * @brief Cheking if the extension of our file is correct
 * 
 * @param file_name 
 * @return int 
 */
static int is_extension_correct(const String file_name){
    // printf(file_name);
    // printf(file_name+strlen(file_name)-3);
    if ( Stringcomp(file_name+strlen(file_name)-3, extension_name) ) return 1;
    else return 0;
}