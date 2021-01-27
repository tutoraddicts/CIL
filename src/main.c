#include <stdio.h>
#include "definations.h"
#include "identify_instruction/identify_instruction.h"
#include "predefined_functions/predefined_functions.h"
#include "Util/Util.h"
#include "variable/CreateVariable.h"
#include "live_enviornment/live_enviornment.h"
#include "do_run.h"

code_mem* main_code;

/**
 * @brief Cheking if the extension of our file is correct
 * 
 * @param file_name 
 * @return int 
 */
static int is_extension_correct(String file_name){
    if ( !strcmp(file_name+stringLenth(file_name)-2, extension_name) ) return 1;
    else return 0;
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

    int size_line = stringLenth(line);

    main_code->code = (char**)realloc(main_code->code, sizeof(char*)*main_code->no_of_line+1);
    main_code->code[main_code->no_of_line] = (char*)malloc(sizeof(char)*size_line);
    main_code->code[main_code->no_of_line] = StringCopy(line, main_code->code[main_code->no_of_line], size_line);


    main_code->no_of_line++;
}

/**
 * @brief Main function where our programing starting ezz :P
 * @param args 
 * @param file_name 
 * @return int 
 */
int main(int args, String *file_name) {

    if (args < 2) return  Error(no_args) & LiveEnviornment() ;
    if ( !is_extension_correct(file_name[1]) ) return Error(wrong_extension);

    FILE *pToFile = fopen(file_name[1], "r");

    if (!pToFile) return printf(no_such_file);

    const String data = (String)malloc(sizeof(char)*512);

    while ( fgets( data, 512, pToFile) ) // Get input from the file line by line
	{
        store_code(data); // storing the code will be usefull in future version
        do_run(data);
    }

    fclose(pToFile);
    free(data);

    return 0;
}
