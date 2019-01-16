/* author: Jianqiu Wang
Shift an int number two places to the right
*/
#include <stdio.h>

int main()
{
    int i;
    printf("Reading int number from input: ");
    scanf("%d", &i);
    printf("%d shift by 2 bits: %d\n", i, i >> 2);
    
    // determine arithmetic or logical shift by signs of input and output
    if ((i < 0) & ((i >> 2) < 0))
    {
        printf("arithmetic shift\n");
    } 
    else
    {
        printf("logical shift\n");
    }

    return 0;
}
