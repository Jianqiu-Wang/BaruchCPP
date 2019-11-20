//Author: Jianqiu Wang
//Read characters from keyboard and show on screen
#include <stdio.h>
#include <stdlib.h>
#define MAXINPUT 80   // assume no more than 80 chars per line

int main()
{
	char* p;
	p = (char*)malloc(MAXINPUT*sizeof(char)); // allocate memory for one line of input

	int c;         // charactor to read
	int count = 0; // number of chars used in one line
	while (p != NULL)
	{
		c = getchar();
		if (c == 1) // CTRL + A is 1 
		{
			printf("CTRL + A is a correct ending.\n");
			break;
		}
		else if (c != '\n') 
		{
			p[count] = c;
			count++;
		}
		else // line ends
		{   
			// print this line, reallocate meory, and reset counter
			printf("%s\n", p);
			p = (char*)malloc(MAXINPUT*sizeof(char));
			count = 0;
		}
	}

	free(p);
	return 0;
}
