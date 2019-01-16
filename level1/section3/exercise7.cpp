/* author: Jianqiu Wang
Fast muliply by 2^n using logical shift
*/
#include <stdio.h>

int main()
{
    int i; // number to be multiplied 
    int n; // power n
    int result;
    printf("Please type int number to be mulitplied: ");
    scanf("%d", &i);
    printf("Type power: ");
    scanf("%d", &n);
    result = i << n; // logical shift to left by n digits
    printf("%d * 2^%d = %d\n", i, n, result);
    printf("%d * 2^%d = %d\n", i, n, result);

    return 0;
}
