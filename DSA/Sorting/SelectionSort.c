#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, i, imin, temp, j;

    printf("Enter the size of the array : ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n*sizeof(int));

    printf("Enter the elements of the unsorted array : ");

    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Selection Sort implementation.
    for (i = 0; i < n; i++)
    {
        imin = i;
        for (j = i +1; j < n; j++)
        {
            if (arr[j] < arr[imin])
                imin = j;
        }

        temp = arr[i];
        arr[i] = arr[imin];
        arr[imin] = temp;
    }

    printf("\nThe sorted array is : ");

    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    free(arr);
}
