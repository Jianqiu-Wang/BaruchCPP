/* author: Jianqiu Wang
Print 2 columns of Fahrenheit and Celsius degrees */

#include <stdio.h>

int main()
{
    int start_temperature = 0; // start temperature in degrees Celsius
    int end_temperature = 19;   // end temperature in degrees Celsius
    unsigned int step_size = 1; // step size, increment of temperature

    printf("T(C)    T(F)\n"); // header lines
    printf("------------\n");
    
    double t_f; // temperature in degrees Frehrenheit
    for (int t_c=start_temperature; t_c<=end_temperature; t_c+=step_size) 
    {
        t_f = t_c * 9. / 5 + 32;
        printf("%d,%10.1f\n", t_c, t_f);
    }
    return 0;
}