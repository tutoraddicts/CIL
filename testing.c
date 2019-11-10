#include<stdio.h>
#include<string.h>

void main() {
	int count, functions_count = 0;

	FILE *pToFIle = fopen("net", "r");
	char input[512];	
	while ( fgets( input, 512, pToFIle ) ) {
		printf("scanning\n");
		for (count = 0; count < strlen(input); count++) {
			if( input[count] != '\n') {
				printf("%d : %c\n", count, input[count]);
			}
			else {
				printf("enter here\n");
			}
		}
	}
}