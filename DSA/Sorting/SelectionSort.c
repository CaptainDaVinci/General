#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int arr[], int n);

int main(void)
{
    clock_t start, end;
    start = clock();

    int n, i, imin, temp, j;

    printf("Enter the size of the array : ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n*sizeof(int));

    printf("Enter the elements of the unsorted array: ");

    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    selectionSort(arr, n);
    printf("\nThe sorted array is: ");

    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");
    free(arr);

    end = clock();
    printf("Sorted in %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
}

void selectionSort(int arr[], int n)
{
    int imin, i, j, temp;

    for(i = 0; i < n; i++)
    {
        imin = i;
        for(j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[imin])
                imin = j;
        }

        temp = arr[i];
        arr[i] = arr[imin];
        arr[imin] = temp;
    }
}
