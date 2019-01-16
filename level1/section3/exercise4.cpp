/* author: Jianqiu Wang
Given varible married a bunch of values, test how it is treated as boolean type
*/
#include <stdio.h>

int main()
{
    int married;
    for (married=-1; married < 2; married++)
    {
        printf("variable married is %d\n", married);
        printf("and it is %s", married ? "Married\n" : "Not married\n");
    };

    return 0;
}