#include <stdio.h>
#include <stdlib.h>
#include "MergeSort.c"

void merge(int arr[], int l, int m, int h);
void mergeSort(int arr[], int l, int h);
int bin_search(int arr[], int n, int key);

int main(void)
{
    int n, i, key;
    int result;

    printf("Enter the size of the array : ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n*sizeof(int));



    printf("Enter the elements : ");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    mergeSort(arr, 0, n - 1);

    printf("On sorting : ");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\nEnter the elements to be searched : ");
    scanf("%d", &key);

    result = bin_search(arr, n, key);

    if(result == -1)
    {
        printf("Element not found!\n");
        return -1;
    }

    printf("Element %d was found at index %d\n", key, result);
    free(arr);
}

int bin_search(int arr[], int n, int key)
{
    int low, high, mid;
    low = 0;
    high = n - 1;

    while(low <= high)
    {
        mid = (low + high) / 2;

        if(arr[mid] == key)
            return mid;

        else if(arr[mid] > key)
            high = mid - 1;

        else
            low = mid + 1;
    }

    return -1;
}
