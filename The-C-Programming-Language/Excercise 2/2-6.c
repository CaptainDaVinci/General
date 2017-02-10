#include <stdio.h>

int convert(int decimal);
int getbits(int x, int p, int n);

int main(void)
{
    int x, n, p;

    printf("Enter the number: ");
    scanf("%d", &x);
    printf("Enter the value of p, n: ");
    scanf("%d%d", &p, &n);

    printf("binary - %d\n", convert(x));

    printf("bits - %d\n", convert(getbits(x, p, n)));
}

int convert(int x)
{
    int bin = 0;
    int rem = 0;
    int i = 1;

    while(x != 0)
    {
        rem = x % 2;
        x /= 2;
        bin = bin + rem * i;
        i *= 10;
    }

    return bin;
}

int getbits(int x, int p, int n)
{
    return ((x >> (p - n + 1)) & ~ ( ~ 0 << n));
}
