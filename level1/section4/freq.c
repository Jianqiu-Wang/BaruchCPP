/* author: Jianqiu Wang
 Count how many times each of the numbers 0-4 have beentyped.*/

#include <stdio.h>

int main()
{
    int next_ch; // next charcter from input
    
    int num_zero = 0; // number of 0's
    int num_one = 0; // number of 1's
    int num_two = 0; // number of 2's
    int num_three = 0;// number of 3's
    int num_four = 0;// number of 4's
    int num_other = 0;// number of other characters

    while ((next_ch=getchar()) != EOF)
    {
        switch (next_ch)
        {
            case '0': num_zero = num_zero + 1;       

            case '1': num_one = num_one + 1;       

            case '2': num_two = num_two + 1;

            case '3': num_three = num_three + 1;       
            case '4': num_four = num_four + 1;       

            default: num_other = num_other + 1;
        }
    }

    printf("Number of 0's: %di\n", num_zero);
    printf("Number of 1's: %d\n", num_one);
    printf("Number of 2's: %d\n", num_two);
    printf("Number of 3's: %d\n", num_three);
    printf("Number of 4's: %d\n", num_four);
    printf("Number of others: %d\n", num_other);
}