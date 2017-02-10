#include <stdio.h>

int main(void)
{
    long long int line, tabs, blank;
    line = tabs = blank = 0; // Initialising all the variables to zero
    int c;

    while((c = getchar()) != EOF)
    {
        if(c == '\n')
            line++;

        if(c == '\t')
            tabs++;

        if(c == ' ') 
            blank++;
    }
    printf("\nLine = %lld\ntab = %lld\nblank = %lld\n", line, tabs, blank);

    return 0;
}
