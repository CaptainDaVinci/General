#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if ( argc == 2)
    {
        int key, i, n, option;
        char text[200];
        printf("Enter the text : ");
        scanf("%[^\n]s", text);
        key = atoi(argv[1]);
        // Iterate over string
        for(i = 0, n = strlen(text); i < n; i++)
        {
            // Cipher for Uppercase letters
            if (isupper(text[i]))
            {
                text[i] = (text[i] - 65 + key) % 26;
                text[i] = text[i] + 65;
            }
            // Cipher for lowercase letters
            else if (islower(text[i]))
            {
                text[i] = (text[i] - 97 + key) % 26;
                text[i] = text[i] + 97;
            }
            // No change for punctuations
            else
            {
                text[i] = text [i];
            }
        }
        printf("Ciphered text is : %s\n", text);
        return 0;
    }
    else
    {
        printf("missing command-line arguement\n");
        return 1;
    }
    return 0;
}
