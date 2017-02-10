#include <stdio.h>

int main(void)
{
    int brackets = 0, squotes = 0, dquotes = 0;
    int c;

    while((c = getchar()) != EOF)
    {
        if(c == '[') brackets++;
        else if(c == ']') brackets--;

        if(c == '(') brackets++;
        else if(c == ')') brackets--;

        if(c == '{') brackets++;
        else if(c == '}') brackets--;

        if(c == 39) squotes++;

        if(c == '"') dquotes++;
    }

    if(brackets != 0) printf("SYNTAX ERROR! expected ')', '}' or ']' \n");
    if(squotes % 2 != 0) printf("SYNTAX ERROR! expected \' \n");
    if(dquotes % 2 != 0) printf("SYNTAX ERROR! expected \" \n");

    return 0;
}
