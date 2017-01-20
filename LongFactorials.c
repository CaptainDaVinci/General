#include <stdio.h>

int main(void)
{
    int N;
    int a[300], i, j;
    int x, temp = 0, m = 1;

    for(i = 0; i < 300; i++)
        a[i] = 1;

    printf("Enter the number : ");
    scanf("%d", &N);

    for(i = 1; i <= N; i++)
    {
        for(j = 0; j < m; j++)
        {
            x = a[j] * i + temp;
            a[j] = x % 10;
            temp = x / 10;
        }

        while(temp > 0)
        {
            a[m] = temp % 10;
            temp = temp / 10;
            m++;
        }
    }

    printf("The factorial is : ");

    for(i = m - 1; i >= 0; i--)
    {
        printf("%d", a[i]);
    }

    printf("\n");

    return 0;
}
