#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool prime(int n)
{
    int i;
    if(n == 1) return false;
    for(i = 2; i <= sqrt(n); i++)
        if(n%i == 0) return false;
    return true;
}
int main(void)
{
    int n;
    printf("Enter the number : ");
    scanf("%d", &n);
    if(prime(n)) printf("Prime\n");
    else printf("Not Prime\n");
    return 0;
}
