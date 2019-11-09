#include<stdio.h>

int main () {

	FILE *pToFIle = fopen("net", "r");

	int line = 0;

	char input[512];

	while ( fgets( input, 512, pToFIle)) {
		line ++;
		printf("Line:%d -> %s", line, input);
	}

	fclose(pToFIle);
	return 0;
}
