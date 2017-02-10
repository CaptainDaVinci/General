#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i, n, key;
    printf("Enter the size of the array : ");
    scanf("%d", &n);
    int *arr = (int*)malloc(n*sizeof(int));
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the number to be searched : ");
    scanf("%d", &key);
    for (i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            printf("The number %d is found at position %d. ", key, i);
            exit(0);
        }

    }
    printf("Number not found.");
    free(arr);
    return 0;
}
