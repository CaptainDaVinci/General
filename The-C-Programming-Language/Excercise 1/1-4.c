#include <stdio.h>

int main(void)
{
    float fahr, celsius;
    int low, high, step;
    low = 0;
    high = 300;
    step = 20;
    celsius = low;
    while(celsius <= high)
    {
        fahr = celsius*9.0/5.0 + 32.0;
        printf("%3.0f\t%6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
    return 0;
}
