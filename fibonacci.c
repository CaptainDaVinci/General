#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
    unsigned long long int f1 = 1, f2 = 1, f = 0;
    int N;
    printf("Enter the number : ");
    scanf("%d", &N);

    printf("1\n1\n");
    for(int i = 2; i < N; i++)
    {
        f = f1 + f2;
        printf("%lld\n", f);
        f1 = f2;
        f2 = f;
    }

    return 0;
}
