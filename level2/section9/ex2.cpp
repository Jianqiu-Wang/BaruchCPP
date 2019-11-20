// Author: Jianqiu Wang
// Read characters from keyboard and write to file
#include <stdio.h>
#include <stdlib.h>
#define MAXINPUT 80   // assume no more than 80 chars per line

int main()
{
	printf("Type filename:");
	char filename[80];
	scanf("%s\n", filename); // read file name 

	// create a file handler
	FILE* fp;
	fp = fopen(filename, "w+");
	if (fp == NULL)
	{
		printf("Create file error!");
		exit(1);
	}

	char* p; // dynamic array to buffer one line input
	p = (char*)malloc(MAXINPUT*sizeof(char)); // allocate memory for one line of input

	int c;         // char input
	int count = 0; // char counter for one line
	while (p != NULL)
	{
		c = getchar();
		if (c == 1)
		{
			printf("CTRL + A is a correct ending.\n");
			free(p);    // release array pointer
			fclose(fp); // close file handler
			break;
		}
		else // not ctrl+A
		{
			fprintf(fp, "%c", c); // write char to file including normal and \n
			count++;
			if (c == '\n') // line ends
			{   
				// reallocate memory and reset counter
				p = (char*)malloc(MAXINPUT*sizeof(char));
				count = 0;
			}
		}
	}
		
	return 0;
}
