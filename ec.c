#include<stdio.h>
#include<string.h>
void known_functions(char[], char[], int);

int main (int args, char *f[]) {
	FILE *pToFIle = fopen(f[1], "r");
	int count, functions_count = 0;

	char input[512], functions[512];
	
	//while (fgets(input, 512, pToFIle)) {printf("%ld\n", strlen(input));}
	
	while ( fgets( input, 512, pToFIle) ) {
		for (count = 0; count < strlen(input); count++) {
			if ( input[count] != '\0') {
				if (input[count] >= 97 && input[count] <= 122) {
					//printf("working");
						functions[functions_count] = input[count];
						functions_count++;
				}
				else if (input[count] == ' ') {
					//printf("working");
						known_functions(functions, input, count);
				}
			}
		}
	}

	fclose(pToFIle);
	return 0;
}

void known_functions(char functions[], char input[], int count) {
	int new_count, temp_count = 0, empty = 0;
	//printf("working");
	//printf("%s\n", functions);
	//printf("%c", input[count]);
	if (strcmp(functions, "print") == 0 && input[count + 1] == '"') {
		new_count = count + 1;
		//printf("working");
		
		if (input[new_count] == '"' && input[new_count + 1] == '"') {
			printf(" ");
		}
		else {
			for (new_count = new_count + 1; new_count < strlen(input); new_count++ ) {
				
				if ( input[new_count] == '"') {
					break;
				}
				else {
					functions[temp_count] = input[new_count];
					temp_count++;
				}
			}
		}
		
			

		printf("%s", functions);

	}
}
