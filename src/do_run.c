#include "do_run.h"

DO_RUN_H void do_run(String data){

    // printf(data);
    if (IsStringEmpty(data))    return;

    // printf("starting do run\n");
    String instruction_name;
    instruction_name = (String)malloc(sizeof(char)*100);
    String instruction;
    instruction = (String)malloc(sizeof(char)*512);

    int data_length = strlen(data);

    for (int count = 0; count < data_length; count++)
    {
        if ( *(data+count) != ' '  && *(data+count) != '(' && *(data+count) != '='){
            *(instruction_name+count) = *(data+count);
        }else {
            *(instruction_name+count) = '\0';
            int size = 0;
            while ( count < data_length )
            {
                *(instruction+size) = *(data+count);
                count++;
                size++;
            }
            instruction = RemoveSpaces(instruction);
            *(instruction+size-1) = '\0';
            break;
        }
    }

    switch ( IDENTIFY_INSTRUCTION_H identify_instruction(instruction_name) )
	{
		case INVALID_FUNCTION:
            // printf("going to create variable\n");
            CreateVariable(instruction_name, instruction);
		    break;
		case console_print_function:
			console_print_func(instruction);
		    break;
        case exit_ec_function:
            console_exit_func(instruction);
	}

}