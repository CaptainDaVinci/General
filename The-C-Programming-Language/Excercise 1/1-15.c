#include <stdio.h>

#define UPPER 200
#define LOWER 0
#define STEP 20

float celsius(float);

int main(void)
{
    float i;

    printf("\t\tFAHRENHEIT    CELSIUS\n");
    printf("\t\t-----------------------\n");

    for(i = LOWER; i <= UPPER; i += STEP)
    {
        printf("\t\t| %3.0f      |  %6.1f   |\n", i, celsius(i));
    }

    printf("\t\t-----------------------\n");
    return 0;
}

float celsius(float i)
{
    return 5.0 * (i - 32) / 9.0;
}
