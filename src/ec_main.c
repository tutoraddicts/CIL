#include "ec_main.h"

StringVars* stringVars;

static void run(char*, char*, int);

int main (int args, char **filename) 
{
	if (args < 2) return printf(NoArg); // this means user did not pass any file

	FILE *pToFIle = fopen(filename[1], "r"); // Just like others we are getting the file name which one we want to execute and reading that :P
	
	// printf(" started ");
	char *input = (char*)malloc(sizeof(char)*512);
	char *functions = (char*)malloc(sizeof(char)*512);
	
	stringVars = CreateStringVars();

	char* BackupInputPtr = input;
	char* BackupFunctionsPtr = functions;

	
	while ( fgets( input, 512, pToFIle) ) // Get input from the file line by line
	{ 
		// printf("input \n");
		int count = 0;
		int inputLenth = stringLenth(input); 

		input = RemoveSpaces(input, 0);
	
		inputLenth = stringLenth(input);
		
		//Loop will continue to check for any kind of space between if spave we know that we found our function
		for (count = 0; count < inputLenth; count++) 
		{
			if (input[count] != ' ') 
				functions[count] = input[count];
			else {
				run(functions, input, count);
				break;
			}
		}
	}

	fclose(pToFIle);

	free(BackupInputPtr);
	free(BackupFunctionsPtr);

	return 0;
}

static void run(char *functions, char *input, int count) {
	int new_count;
	int temp_count = 0;
	int empty = 0;

	switch ( IdentifyFunction(functions) )
	{
		case INVALID_FUNCTION:
			CreateVariable(functions, input, count);
			break;
		case console_print_function:
			ConsolePrintFunc(input, count);
			break;
		default:
			break;
	}
}
