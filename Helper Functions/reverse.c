#include <stdio.h>

int reverse(int a)
{
    int n, rev = 0;

    while(a != 0 )
    {
        n = a % 10;
        a = a / 10;
        rev = rev * 10 + n;
    }
    return rev;
}

int main(void)
{
    int n;

    printf("Enter the number : ");
    scanf("%d", &n);

    printf("revere = %d\n", reverse(n));

    return 0;
}
