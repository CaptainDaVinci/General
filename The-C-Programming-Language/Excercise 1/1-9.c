#include <stdio.h>

int main(void)
{
    int c;
    while((c = getchar()) != EOF)
    {
        while(c == ' ')   //replaces two or more spaces by a single space
        {
            c = getchar();
            if(c != 32)
                printf(" ");
        }
        putchar(c);
    }

    return 0;
}
