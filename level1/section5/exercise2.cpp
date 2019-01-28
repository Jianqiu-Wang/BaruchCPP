/* author: Jianqiu Wang
Use recursion to calculate factorial */

#include <stdio.h>

unsigned int factorial(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    else
    {
        return n * factorial(n-1);
    }
}

int main() 
{
    printf("factorial of 6 is %d\n", factorial(6));
    return 0;
}