#include <stdio.h>
#include <stdlib.h>
int SumOfDigits(int n)
{
    int sum = 0, a;

    if(n/10 == 0)
    {
        return n;
    }
    while(n != 0)
    {
        a = n%10;
        n = n/10;
        sum = sum + a;
    }
    SumOfDigits(sum);
}

int main(void)
{
    int n, a, sum = 0, sum2 = 0;
    printf("Enter the number : ");
    scanf("%d", &n);
    sum = SumOfDigits(n);
    printf("Sum = %d\n", sum);
    return 0;
}
