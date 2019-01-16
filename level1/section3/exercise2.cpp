/* author: Jianqiu Wang
Calcuate surface of a triangle with one 90 degree angle
Input: base, height
*/
#include <stdio.h>

int main()
{
    double base, height, surface;
    
    // use scanf to read base and height 
    printf("Enter base and heigh for the triangle (split by space): ");
    scanf("%lf %lf", &base, &height);
    
    surface = 0.5 * base * height;
    printf("The surface of triangle is: %lf\n", surface);

    return 0;
}
