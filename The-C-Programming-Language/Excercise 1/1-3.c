#include <stdio.h>

int main(void)
{
    printf("Fahrenheit to Celsius conversion.\n");
    float fahr, celsius;
    int low, high, step;
    low = 0;
    high = 300;
    step = 20;
    fahr = low;
    while(fahr <= high)
    {
        celsius = (5.0/9.0)*(fahr - 32.0);
        printf("%3.0f\t%6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
    return 0;
}
