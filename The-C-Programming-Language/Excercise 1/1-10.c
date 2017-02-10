#include <stdio.h>

int main(void)
{
    int c;
    while((c = getchar()) != EOF)
    {
        if(c == '\\')
            printf("\\\\");

        else if(c == '\t')
            printf("\\t");

        else if(c == '\b')
            printf("\\b");
            
        else putchar(c);
    }

    return 0;
}
