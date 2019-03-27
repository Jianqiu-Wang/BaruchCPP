/* author: Jianqiu Wang
 * Function: Swap(), exchange value of two varibales by using pointers
 */

#include <stdio.h>

void Swap(float* a, float* b)
{
    float* temp = a; // copy pointer a to temp variable
    a = b;           // assign pointer b to pointer a 
    b = temp;
}

int main()
{
    float a = 2.1; 
    float b = 1.2;
    printf("a is %f, b is %f\n", a, b);
    Swap(&a, &b);
    printf("Swap a,b, a is %f, b is %f\n", a, b);
   
    return 0;
}

