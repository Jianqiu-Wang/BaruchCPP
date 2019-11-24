//Author: Jianqiu Wang
//Read characters from keyboard and show on screen
#include <stdio.h>
#include <stdlib.h>
#define MAXINPUT 80
int main()
{
	int next_char; // charactor to read
	int count = 0;
	char line[MAXINPUT]; // number of chars used in one line
	while ((next_char=getchar()) != 1)
	{
		if (next_char != '\n') 
		{
			line[count] = next_char;
			count++;
		}
		else // line ends
		{   
			// print this line, reallocate meory, and reset counter
			printf("%s\n", line);
			char line[MAXINPUT];
			count = 0;
		}
	}
	printf("CTRL + A is a correct ending.\n");
	return 0;
}
