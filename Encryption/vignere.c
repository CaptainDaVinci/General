#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        int i, n, m, option, j = 0;
        char text[200], key[50];
        printf("Enter the text : ");
        scanf("%[^\n]s", text);
        strcpy(key, argv[1]);
        n = strlen(text);
        m = strlen(key);
        for (i = 0, j = 0; i < n; i++, j++)
        {
            if ( j >= m)
            {
                j = 0;
            }
            if (isupper(key[j]))
            {
                key[j] = key [j] - 65;
            }
            else if (islower(key[j]))
            {
                key[j] = key [j] - 97;
            }
            if (isupper(text[i]))
            {
                text[i] = (text[i] - 65 + key[j]) % 26;
                text[i] = text[i] + 65;
            }
            else if (islower(text[i]))
            {
                text[i] = (text[i] - 97 + key[j]) % 26;
                text[i] = text[i] + 97;
            }
            else
            {
                text[i] = text [i];
                j--;
            }
        }
        printf("Ciphered text is : %s\n", text);
    }
    else
    {
        printf("Usage : %s key\n", argv[0]);
        return 1;
    }
    return 0;
}
