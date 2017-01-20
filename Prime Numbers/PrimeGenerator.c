/*
 *
 * Following is an impementation of Sieve of Eratosthenes
 *
 *
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

typedef unsigned long long int ulld;
void primeGenerator(bool *, ulld);

int main(void)
{
    ulld N, k, i;
    printf("Enter the number : ");
    scanf("%lld", &N);

    if(N == 2)
    {
        printf("2\n");
        return 0;
    }

    bool *primeNums = malloc(N + 1);

    for(i = 2; i <= N; i++)
        primeNums[i] = true;

    primeGenerator(primeNums, N);

    free(primeNums);
    return 0;
}

void primeGenerator(bool *primeNums, ulld N)
{
    ulld i = 2, j, counter;

    for(i = 2; i*i <= N; i++)
    {
        counter = 0;
        if(primeNums[i])
        for(j = i*i; j <= N; j = i*i + counter * i)
        {
                primeNums[j] = false;
                counter++;
        }
    }

    for(i = 2; i <= N; i++)
    {
        if(primeNums[i])
            printf("%lld, ", i);
    }

    printf("\n");
}
