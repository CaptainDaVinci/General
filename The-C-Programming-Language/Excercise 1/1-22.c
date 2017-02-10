#include <stdio.h>

#define MAXLINE 100         //maximum length of the input line
#define MAXLEN 20           // length for line folding

#define ANSI_COLOR_GREEN   "\x1b[32m"   //ignore
#define ANSI_COLOR_RESET   "\x1b[0m"    //ignore

int getLine(char *);
void trim(char *);

int main (void)
{
    char line[MAXLINE];
    int len;

    while((len = getLine(line)) > 0)
    {
        printf(ANSI_COLOR_GREEN    "\nLine folding...\n"     ANSI_COLOR_RESET "\n"); // ignore

        if(len > MAXLEN)
        {
            trim(line);
        }
        printf("%s", line);
        if(len < MAXLEN) printf("\n");
    }
}

int getLine(char line[])
{
    int nc = 0;
    int c;

    while((((c = getchar()) != EOF)) && c != '\n')
    {
        line[nc] = c;
        nc++;
    }

    line[nc] = '\0';

    return nc;
}

void trim(char line[])
{
    int i = 0;
    int lastBlank = 0;
    int j = 1;

    for(i = 0; line[i] != '\0'; i++)
    {
        if(line[i] == ' ' || line[i] == '\t')
        {
            lastBlank = i;
        }

        if(i == MAXLEN * j)             //prints a new line at every MAXLEN interval
        {
            line[lastBlank] = '\n';
            j++;
        }
    }

    line[i] = '\n';
    line[i + 1] = '\0';
}
