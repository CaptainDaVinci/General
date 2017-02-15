#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int arr[], int n);

int main(void)
{
    clock_t start, end;
    start = clock();

    int i, j, n, temp;

    printf("Enter the size of the array : ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n*sizeof(int));

    printf("Enter the elements of the unsorted array : ");

    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    bubbleSort(arr, n);

    printf("The sorted array is : ");

    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");
    free(arr);

    end = clock();

    printf("Sorted in %.10lf seconds!\n", (double)(end - start) / CLOCKS_PER_SEC);
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    int temp;

    for(i = 0; i < n - i + 1; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
