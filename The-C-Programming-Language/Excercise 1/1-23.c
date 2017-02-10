#include <stdio.h>

#define MAXLINE 100

int getLine(char *);
void noComment(char *, char *);

int main(void)
{
    char line[MAXLINE];
    char newLine[MAXLINE];
    int len;

    while((len = getLine(line)) > 0)
    {
        noComment(line, newLine);
        printf("%s", newLine);
    }
}

int getLine(char line[])
{
    int c, nc = 0;

    while(((c = getchar()) != EOF) && c != '\n')
    {
        line[nc] = c;
        nc++;
    }

    if(c == '\n')
    {
        line[nc] = '\n';
        nc++;
    }

    line[nc] = '\0';

    return nc;
}

void noComment(char line[], char newLine[])
{
    int i, j;
    int lastLetter;
    int nextLetter;

    for(i = 0; line[i] != '\0'; i++)
    {
        newLine[i] = 0;
        if(line[i] == '/' && line[i+1] == '/')
        {
            lastLetter = i - 1;
        }

        if(line[i] == '\n' || line[i] == '\0')
        {
            nextLetter = i;
        }
    }

    for(i = 0; line[i] != '\0'; i++)
    {
        newLine[i] = 0;
        if(line[i] == '/' && line[i+1] == '*')
        {
            lastLetter = i - 1;
        }

        else if(line[i] == '*' && line[i+1] == '/')
        {
            nextLetter = i+2;
        }
    }

    for(i = 0; i <= lastLetter; i++)
    {
        newLine[i] = line[i];
    }

    j = i;

    for(i = nextLetter, j;  i >= nextLetter && line[i] != '\0'; i++, j++)
    {
        newLine[j] = line[i];
    }

    newLine[i] = '\0';
}
