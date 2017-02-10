#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int c;
    int frequency[26];
    int i, j;

    for(i = 0; i < 26; i++)
    {
        frequency[i] = 0;
    }

    while((c = getchar()) != EOF)
    {
        c = toupper(c);         // so that lower and uppercase letters are considered the same.
        if(c <= 'Z' && c >= 'A')
        {
            frequency[c - 65]++;    // corresponds to a value between 0 and 25
        }
    }

    for(i = 0; i < 26; i++)
    {
        printf("\n%c |", i + 65);
        for(j = 0; j < frequency[i]; j++)
        {
            printf(" *");
        }
    }
    printf("\n");

    return 0;
}
