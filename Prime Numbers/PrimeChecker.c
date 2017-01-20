#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool prime(int N)
{
    int i;
    if(N == 1) return false;

    for(i = 2; i*i <= N; i++)
        if(N % i == 0)
            return false;

    return true;
}

int main(void)
{
    int N;
    printf("Enter the number : ");
    scanf("%d", &N);

    if(prime(N))
        printf("Prime\n");

    else
        printf("Not Prime\n");

    return 0;
}
