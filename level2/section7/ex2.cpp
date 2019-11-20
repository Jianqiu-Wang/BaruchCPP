// Calculate the length of a string 
#include <stdio.h> 
#define MAXLINE 30 
// String length declaration
int Length(char str[]);

int main()
{ 
	char string[MAXLINE+1]; // Line of maxium 30 chars + \0 
	int c;                  // The input character 
	int i=0;                // The counter

	// Print intro text 
	printf("Type up to %d chars. Exit with ^Z\n", MAXLINE); 

	// Get the characters
	while ((c=getchar())!=EOF && i<MAXLINE) 
	{
		// Append entered character to string 
		string[i++] = (char)c; 
	} 
	string[i]='\0'; // String must be closed with \0 
	printf("String length is %d\n", Length(string));
	return 0; 
} 

/* Implement the Length() function */
int Length(char str[])
{
	int length = 0;
	while (*(str+length) != '\0') // move by length's bytes in memory
	{
		length++;
	}
	return length;
}
