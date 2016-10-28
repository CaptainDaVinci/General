#include <stdio.h>

void swap(int *a, int *b);
int main (void)
{
    int a, b;
    printf("Enter the numbers : ");
    scanf("%d%d", &a, &b);
    swap(&a, &b);
    printf("The numbers are swaped as a = %d and b = %d", a, b);
    return 0;
}

void swap (int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
