// Author: Jianqiu Wang
// Prints the day of a given-day number by using array of strings
#include <stdio.h>
#include <string.h>
#define MAXLEN 11 // max length of a day name

// initialize a 2D array, a global variable
char day_name[7][MAXLEN]= {"Monday\0", "Tuesday\0", "Wednesday\0", 
							"Thursday\0", "Friday\0", "Saturday\0", "Sunday\0"};
	
// Prints name of each day in a week
void DayName(int day_num)
{
	printf("%d gives: Day %d is a %s\n", day_num, day_num, day_name[day_num-1]);
}

// Another implementation by using pointer
void DayName2(int day_num)
{
	printf("%d gives: Day %d is a ", day_num, day_num);
	char* p = day_name[day_num-1]; // get address of array (2nd order) 
	int i = 0;
	// print charactor by moving pointer by 1 byte
	while (*(p+i)!='\0')
	{
		printf("%c", *(p+i));
		i++;
	}
	printf("\n");
}


int main()
{
	int day_num = 2;
	DayName(day_num);
	DayName2(day_num);
	day_num = 1;
	DayName(day_num);
	DayName2(day_num);
	return 0;
}
