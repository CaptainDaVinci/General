#include <stdio.h>

int convert(int binaryNum);

int main(void)
{
    int n;

    printf("Enter the number: ");
    scanf("%d", &n);

    printf("Binary - %08d\n", convert(n));
}

int convert(int n)
{
    int rem;
    int i = 1;
    int bin = 0;

    while(n != 0)
    {
        rem = n % 2;
        n /= 2;
        bin = bin + rem * i;
        i = i * 10;
    }

    return bin;
}
