/* author: Jianqiu Wang
printnumber() function: print interger digit by digit using the putchar() function */

#include <stdio.h>

void printnumber(int i)
{
    if (i < 0)
    {
        putchar('-');
        printnumber(-i);
    }
    else
    {
        if (i/10 !=0) // greater than 10
        {
            printnumber(i/10);
        }
        putchar(i%10+'0');
    }
}

int main()
{
    printnumber(-123456);
    printnumber(0);
    printnumber(-1);
    printnumber(999);
    return 0;
}