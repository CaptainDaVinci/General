#include <stdio.h>
/** NOT CLEAR WITH THE QUESTION**/
#define TABSTOP 4

int main(void)
{
    int c;
    int nc;
    int i = 0;
    int j = 0;
    int k = 0;

    while((c = getchar()) != EOF)
    {
        nc++;
        if(nc == TABSTOP || nc == '\n') nc = 0;

        if(c == ' ')
        {
            i = 0;
            k = 0;
            while(c == ' ')
            {
                c = getchar();
                i++;
            }

            if(i >= 3)
            {
                for(j = 0; j < i/3 && j < (TABSTOP - nc); j += 3)
                    {
                        printf("\t");
                        k += 3;
                    }

            }

            for(j = 0; j < i - k; j++)
                printf("-");

            putchar(c);
        }

        else putchar(c);
    }
}
