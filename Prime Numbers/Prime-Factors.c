#include <stdio.h>

int main(void)
{
    int n, i;

    printf("Enter the number : ");
    scanf("%d", &n);

    if(n % 2 == 0)
        printf("2 ");

    while(n % 2 == 0)
    {
        n /= 2;
    }

    for(i = 3; i*i <= n; i += 2)
    {
        if(n % i == 0)
            printf("%d ", i);

        while(n % i == 0)
        {
            n /= i;
        }
    }

    if(n > 2)
        printf("%d ", n);

    printf("\n");
}
