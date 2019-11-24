// Author: Jianqiu Wang
// Read characters from keyboard and write to file
#include <stdio.h>
#include <stdlib.h>
#define MAXINPUT 80   // assume no more than 80 chars per line

int main()
{
	printf("Type filename:");
	char filename[255];
	scanf("%s\n", filename); // read file name 

	// create a file handler
	FILE* fp;
	fp = fopen(filename, "w+");
	if (fp == NULL)
	{
		printf("Create file error!");
		exit(1);
	}

	int c; // char input
	while ((c=getchar()) !=1)
	{
		fprintf(fp, "%c", c); // write char to file including normal and \n
	}
	printf("CTRL + A is a correct ending.\n");
	fclose(fp); // close file handler
	
	return 0;
}
