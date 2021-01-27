#include "do_run.h"

DO_RUN_H void do_run(String data){

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
        case exit_ec_function:
            exit(0);
	}

}