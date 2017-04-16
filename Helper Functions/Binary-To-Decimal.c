#include <stdio.h>
#include <math.h>

int convert(int );

int main(void)
{
    int n;
    printf("Enter the binary number: ");
    scanf("%d", &n);

    printf("%d\n", convert(n));
}

int convert(int n)
{
    int rem;
    int dec = 0;
    int i = 0;

    while(n != 0)
    {
        rem = n % 10;
        n /= 10;
        dec = dec + rem * pow(2, i);
        i++;
    }

    return dec;
}
