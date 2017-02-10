#include <stdio.h>
#include <stdlib.h>
#include "MergeSort.c"

void merge(int arr[], int l, int m, int h);
void mergeSort(int arr[], int l, int h);

int main(void)
{
    int n, i, key;
    int low, mid, high;
    printf("Enter the size of the array : ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n*sizeof(int));
    printf("Enter the elements : ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    mergeSort(arr, 0, n - 1);
    printf("On sorting : ");
    for(i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\nEnter the elements to be searched : ");
    scanf("%d", &key);
    low = 0;
    high = n - 1;
    while(low <= high)
    {
        mid = (low + high)/2;
        if(arr[mid] == key)
        {
            printf("The element is found at %dth index", mid);
            return 0;
        }
        if(arr[mid] > key)
        {
            high = mid - 1;
        }
        else low = mid + 1;
    }
    printf("Element was not found");
    free(arr);
    return 0;
}
