#include <stdio.h>
#include "definations.h"
#include "identify_instruction/identify_instruction.h"
#include "predefined_functions/predefined_functions.h"
#include "Util/Util.h"
#include "variable/CreateVariable.h"


code_mem* main_code;

/*
 do_run is the function where actual work going on so if you want to change anythin look into
 do_run you can skip main function
*/
static void do_run(String data){

    String instruction_name = (String)malloc(sizeof(char)*100);
    String instruction = (String)malloc(sizeof(char)*512);

    int data_length = strlen(data);

    *(data+data_length-1) = '\0';

    for (int count = 0; count < data_length; count++)
    {

        if ( *(data+count) != ' ' ){
            *(instruction_name+count) = *(data+count);
        }else {
            int size = 0;
            while ( count < data_length )
            {
                *(instruction+size) = *(data+count);
                count++;
                size++;
            }
            instruction = RemoveSpaces(instruction);
            break;
        }
    }
    
    switch ( identify_instruction(instruction_name) )
	{
		case INVALID_FUNCTION:
            CreateVariable(instruction_name, instruction);
		    break;
		case console_print_function:
			console_print_func(instruction);
		    break;
	}

}

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
    if (main_code->no_of_line == 0){
        main_code->code = (char**)malloc(sizeof(char*));
    }
    main_code = (code_mem*)malloc(sizeof(code_mem)); 
    main_code->code = (char**)realloc(main_code->code, sizeof(char*)*(main_code->no_of_line+1) );
    *(main_code->code+main_code->no_of_line) = (char*)malloc(sizeof(char)*line_max_size);

    StringCopy(line, *(main_code->code+main_code->no_of_line), stringLenth(line));

    main_code->no_of_line++;
}

/**
 * @brief Main function where our programing starting ezz :P
 * @param args 
 * @param file_name 
 * @return int 
 */
int main(int args, String *file_name) {

    if (args < 2) return printf(no_args);
    if ( !is_extension_correct(file_name[1]) ) return Error(wrong_extension);

    FILE *pToFile = fopen(file_name[1], "r");

    if (!pToFile) return printf(no_such_file);

    const String data = (String)malloc(sizeof(char)*512);

    while ( fgets( data, 512, pToFile) ) // Get input from the file line by line
	{
        store_code(data);
        do_run(data);
    }

    printf("\nTotal number of codes %ld\n", main_code->no_of_line);
    for (int i = 0; i < main_code->no_of_line; i++){
        printf("%s", main_code->code[i]);
    }
    fclose(pToFile);
    free(data);

    return 0;
}
