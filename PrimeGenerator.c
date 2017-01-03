#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int PrimeGenerator(int prime[], int n, int m)
{
    int i, k = 0, flag;
    if(n == 1) n = 2;
    while(n <= m)
    {
        flag = 0;
        for(i = 2; i <= sqrt(n); i++)
        {
            if(n%i == 0) goto end;
        }
        prime[k] = n;
        k++;
        end:
        n++;
    }
    return k;
}
int main(void)
{
    int n, m, k, i;
    printf("Enter the Range : ");
    scanf("%d%d", &n, &m);
    int *prime = malloc(m*sizeof(int));
    k = PrimeGenerator(prime, n, m);
    for(i = 0; i < k; i++)
    {
        printf("%d ", prime[i]);
    }
    printf("\nTotal number of prime numbers = %d\n", k);
    free(prime);
    return 0;
}
