/* author: Jianqiu Wang
Call function minuse() to calculate diffrence of two numbers */

#include <stdio.h>

double minus(double x, double y)
{
    return x - y;
}

int main() 
{
    double a;
    double b;

    a = 10.5;
    b = 11.3;
    printf("%f minus %f is %f\n", a, b, minus(a,b));
    return 0;
}