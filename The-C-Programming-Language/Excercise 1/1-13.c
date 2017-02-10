#include <stdio.h>

#define MAX 15 //maximum length of a word(assumed).

int main(void)
{
    int c, i, wordLength = 0, j;
    int numberOfWords[MAX], longest, temp;

    for(i = 0; i <= MAX; i++)
        numberOfWords[i] = 0;

    while((c = getchar()) != EOF)
    {
        while(c != ' ' && c != '\t' && c != '\n' && c != ',' && c!= ';' && c != '!' && c != '.') // to calculate the length of a word
        {
            wordLength++;
            c = getchar();
        }
        numberOfWords[wordLength]++;
        wordLength = 0;
    }

    // making use of two for loops
    for(i= 1; i <= MAX; i++)   // to print the word length
    {
        printf("\n%3d|", i);

        for(j = 0; j < numberOfWords[i]; j++) // to print the frequency for a given word length
            printf(" *");

        //printf("  [%d]", numberOfWords[i]); uncomment this line to get the numeric value as well
    }

    printf("\n\n");
    /*Vertical Histogram*/

    /* To find the biggest count */
    longest = numberOfWords[0];
    for (i = 0; i < MAX; ++i)
      if(numberOfWords[i] > longest)
        longest = numberOfWords[i];
    temp = longest;
    printf("\n\n");

    /* To get Vertical Histogram */
    for (i = 0; i < longest; i++) {
      printf("\n%3d|", longest - i);
       for (j = 1; j < MAX; j++)
         if (numberOfWords[j] < temp)
       printf("   ");
         else {
       printf("  *");
       --numberOfWords[j];
         }
       --temp;
    }

   /* printing the x-axis */
    printf("\n    ");

    for (i = 1; i <= MAX; ++i)
        printf("  -");

    printf("\n    ");

    for (i = 1; i <= MAX; ++i)
        printf("%3d", i);

    printf("\n");

    return 0;
  }
