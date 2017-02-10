#include <stdio.h>

#define MAXLINE 100

void reverse(char *);
int getLine(char *);

int main()
{
    char line[MAXLINE];
    int len;
    int i = 0;
    int c;

    while((len = getLine(line)) > 0)
    {
        reverse(line);
        printf("%s\n", line);
    }
    return 0;
}

int getLine(char line[])
{
    int i = 0;
    int c;

    while((((c = getchar()) != EOF)) && (c != '\n'))
    {
        line[i] = c;
        i++;
    }

    line[i] = '\0';
    return i;
}
void reverse(char string[])
{
    int i;
    char temp;
    int length;

    for(i = 0; string[i] != '\0'; i++)   // calculates the length of the string.
            ;                           // equivalent to strlen(string), which is defined in string.h file.

    length = i;

    for(i = 0; i < length/2; i++)   // iterate only halfway through the string
    {
        temp = string[i];                   // swapping of characters
        string[i] = string[length - i- 1];
        string[length - i -1] = temp;
    }
    string[length] = '\0';
}
