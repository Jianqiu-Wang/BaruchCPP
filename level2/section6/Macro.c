/*author: Jianqiu Wang
 * Use predefined Macros: printf and max
 */
#include "Defs.h"

int main()
{
    int a = 1;
    int b = 2;
    PRINT1(a);
    PRINT2(a,b);
    
    int x = 1;
    int y = 2;
    int z = 3;
    printf("Max of %d and %d is: %d\n", x, y, MAX2(x,y));
    printf("Max of %d, %d and %d is: %d\n", x, y, z,  MAX3(x,y,z));

    return 0;
} 
