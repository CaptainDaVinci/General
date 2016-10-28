#include <stdio.h>

int factorial (int a);
int main(void)
{
    int num, x;
    printf("Enter the number : ");
    scanf("%d", &num);
    x = factorial(num);
    printf("The factorial is %d\n", x);
    return 0;
}

int factorial (int a)
{
    int x;
    if (a == 0) return 1;
    x = a * factorial(a - 1);
    return x;
}
