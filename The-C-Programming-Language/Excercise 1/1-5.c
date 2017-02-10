#include <stdio.h>

int main(void)
{
    float fahr, celsius;
    printf("Fahrenheit to Celsius convertor.\n");
    for (fahr = 300; fahr >= 0; fahr = fahr - 20)
    {
        printf("%-3.0f\t%6.1f\n", fahr, 5.0/9.0*(fahr - 32.0));
    }
    return 0;
}
