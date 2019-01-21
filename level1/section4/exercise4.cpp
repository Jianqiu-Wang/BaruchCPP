/* author: Jianqiu Wang
Print 2 columns of Fahrenheit and Celsius degrees */

#include <stdio.h>

int main()
{
    int start_temperature = 0; // start temperature in degrees Fahrenheit
    int end_temperature = 300;   // end temperature in degrees Fahrenheit
    unsigned int step_size = 20; // step size, increment of temperature

    printf("T(F)      T(C)\n"); // header lines
    printf("--------------\n");
    
    double t_Celsius; // temperature in degrees Celsius
    int t_f = start_temperature; // temperature in degrees Fahrenheit
    while (t_f <= end_temperature)
    {
        t_Celsius = (5./9) * (t_f - 32);
        printf("%d,%10.1f\n", t_f, t_Celsius);
        t_f = t_f + step_size;
    }
    return 0;
}