#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 100 // maximum length of a line

int getLine(char *);

int main(void)
{
    char line[MAXLINE];
    int len;

    while((len = getLine(line)) > 0)
    {
        printf("%s\n", line);
    }

    return 0;
}

int getLine(char line[])
{
    int c, i = 0, lastLetter = 0;

    while((c = getchar()) != EOF && c != '\n' && i < MAXLINE)
    {
        line[i] = c;

        if(c != ' ' && c != '\t')   //keeps track of the last letter
        {
            lastLetter = i;
        }

        i++;
    }

    line[lastLetter + 1] = '\0';
    return lastLetter + 1;
}
