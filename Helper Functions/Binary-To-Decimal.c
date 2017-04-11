#include <stdio.h>
#include <string.h>

int convert(char *bin);

int main(void)
{
    char bin[64];
    printf("Enter the binary number: ");
    scanf("%s", bin);

    printf("%d\n", convert(bin));
}

int convert(char *bin)
{
    int dec = 0;
    int n = strlen(bin);
   
    for(int i = 1; i <= n; i++)
        if(bin[i - 1] == '1')
            dec += 1 << (n - i);

    return dec;
}
