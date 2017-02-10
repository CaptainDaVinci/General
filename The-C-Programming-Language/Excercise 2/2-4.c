#include <stdio.h>
#include <string.h>

void squeeze(char *string1, char *string2);

    int main(void)
{
    char str1[20], str2[20];

    printf("Enter the string: ");
    scanf("%s", str1);
    printf("Enter the string: ");
    scanf("%s", str2);

    squeeze(str1, str2);

    printf("%s\n", str1);
}

void squeeze(char *str1, char *str2)
{
    int i, j;
    int k = 0;

    for(i = 0; str2[i] != '\0'; i++)
    {
        for(j = 0; str1[j] != '\0'; j++)
        {
            if(str1[j] == str2[i])
                str1[j] = '@';
        }
    }

    for(i = 0; str1[i] != '\0'; i++)
    {
        if(str1[i] != '@')
            str1[k++] = str1[i];
    }

    str1[k] = '\0';
}
