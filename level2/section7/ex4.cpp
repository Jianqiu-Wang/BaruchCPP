/* author: Jianqiu Wang
 * print the day of a given-day number
 * use array of strings: two-D array
 */
#include <stdio.h>
#include <string.h>
#define MAXLEN 11

void DayName(int day_num)
{
    char day_name[7][MAXLEN]= {"Monday\0", "Tuesday\0", "Wednesday\0", 
                               "Thursday\0", "Friday\0", "Saturday\0", "Sunday\0"};
    printf("%d gives: Day %d is a ", day_num, day_num);
    
    char day_str;
    for(int i=0; i < MAXLEN; i++) 
    { 
        day_str = day_name[day_num-1][i];
        if (day_str!='\0') printf("%c", day_name[day_num-1][i]);
    }
    printf("\n");
}

/* Use pointer to print */
void DayName2(int day_num)
{
    char day_name[7][MAXLEN]= {"Monday\0", "Tuesday\0", "Wednesday\0", 
                               "Thursday\0", "Friday\0", "Saturday\0", "Sunday\0"};
    printf("%d gives: Day %d is a ", day_num, day_num);
   
    char* p = day_name[day_num-1]; // get address of array (2nd order) 
    int i = 0;  
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
}
