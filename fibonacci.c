#include <stdio.h>

int main(void)
{
    int num, i, f[100];
    printf("Enter the number : ");
    scanf("%d", &num);
    f[0] = 0;
    f[1] = 1;
    printf("0\n1\n");
    for (i = 2; i < num; i++)
    {
        f[i] = f[i-1] + f[i-2];
        printf("%d\n", f[i]);
    }
    return 0;

}
