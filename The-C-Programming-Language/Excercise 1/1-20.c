#include <stdio.h>

#define TABSTOP 4

int main(void)
{
    int c;
    int nc = 0;
    int i = 0;

    while((c = getchar()) != EOF)
    {
        nc++;                           //keeps track of the cursor from the next tabstop
        if(nc == TABSTOP) nc = 0;       // resets back to zero if the cursor is at a tabstop

        if(c == '\t')
        {
            while(i != (TABSTOP - nc)) //printf " " for distance between tabstop and the cursor.
            {
                printf(" ");
                i++;
            }
            i = 0;
        }

        else
            putchar(c);
    }
}
