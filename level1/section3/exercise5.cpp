/* author: Jianqiu Wang
Show difference between ++i and i++
*/
#include <stdio.h>

int main()
{
    int i; 
    int j; // value returned by ++i or i++ 
    i = 0;
    printf("initial value i = %d\n", i);
    j = i++; // return i, then increment i
    printf("Post increment j = i++: j = %d, i = %d\n", j, i);
    
    i = 0;
    j = ++i; // increment i, then return i
    printf("Pre increment j = ++i: j = %d, i = %d\n", j, i);

    return 0;
}
