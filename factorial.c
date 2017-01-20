#include <stdio.h>

long long int fact(int n)
{
    if(n <= 1)
        return 1;

    return n * fact(n - 1);
}

int main(void)
{
    int n;
    printf("Enter the number : ");
    scanf("%d", &n);
    printf("%lld", fact(n));
}
