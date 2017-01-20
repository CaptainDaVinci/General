#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
  char name [100];
  printf("Enter your full Name : ");
  scanf("%[^\n]s", name);

  printf("Your initials are : ");

  if (name[0] == ' ')
  {
      for (int i = 1, n = strlen(name); i < n; i++)
      {
            if (name[i] != ' ' && name[i-1] == ' ')
            {
                printf("%c.", toupper(name[i]));
            }
      }
  }

  else
  {
      printf("%c.",toupper(name[0]));
      for (int i = 1, n = strlen(name); i<n; i++)
      {
          if (name[i] != ' ' && name[i-1] == ' ')
          {
              printf("%c.",toupper(name[i]));
          }
      }
  }

  return 0;
}
