#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    int num = 0;
    int i, j;
    int len;
    int key;
    char str[10], c;

    printf("Enter the hexadecimal number: ");
    scanf("%s", str);
    len = strlen(str);

    for(i = len - 1, j = 0; i >= 0; i--, j++)
    {
        if(isdigit(str[i]))
            key = str[i] - '0';

        c = toupper(str[i]);

        if(c >= 'A' && c <= 'F')
            key = c - 'A' + 10;

        num = num + key * pow(16, j);
    }

    printf("Integer = %d\n", num);
}
