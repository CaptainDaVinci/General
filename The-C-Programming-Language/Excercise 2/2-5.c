#include <stdio.h>
#include <string.h>

int any(char *string1, char *string2);

int main(void)
{
    int ptr;
    char str1[20], str2[20];

    printf("Enter the string: ");
    scanf("%s", str1);
    printf("Enter the string: ");
    scanf("%s", str2);

    ptr = any(str1, str2);

    printf("%d, %c\n", ptr, str1[ptr]);
}

int any(char *str1, char *str2)
{
    int i, j;
    int k = 0;

    for(i = 0; str1[i] != '\0'; i++)
    {
        for(j = 0; str2[j] != '\0'; j++)
        {
            if(str2[j] == str1[i])
                return i;
        }
    }
}
