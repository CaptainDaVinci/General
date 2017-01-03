#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i, j, count, n;
    printf("Enter the size of the array : ");
    scanf("%d", &n);
    int *freq = malloc(n*sizeof(int));
    int *arr = malloc(n*sizeof(int));
    printf("Enter the elements of the array : ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        freq[i] = -1;
    }
    for(i = 0; i < n; i++)
    {
        count = 1;
        if(freq[i] == -1)
        {
            for(j = i + 1; j < n; j++)
            {
                if(arr[i] == arr[j])
                {
                    freq[j] = 0;
                    count++;
                }
            }
            freq[i] = count;
        }
    }
    printf("ELEMENT\tFREQUENCY\n");
    for(i = 0; i < n; i++)
    {
        if(freq[i] != 0)
        {
            printf("%d\t%d\n", arr[i], freq[i]);
        }
    }
    free(arr);
    free(freq);
    return 0;
}
