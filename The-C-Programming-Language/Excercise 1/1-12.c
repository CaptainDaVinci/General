#include <stdio.h>

int main(void)
{
    int c;
    while((c = getchar()) != EOF)
    {
        if(c == ' ' || c == '\t' || c == '\n')
        {
            while(c == ' ' || c == '\t')
            {
                c = getchar();
                if (c != ' ' && c != '\t')
                    printf("\n");
            }
                putchar(c);
        }
        else
            putchar(c);
    }

    return 0;
}
