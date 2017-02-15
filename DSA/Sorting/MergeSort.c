#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int l, int m, int h);
void mergeSort(int arr[], int l, int h);

int main(void)
{
    clock_t start, end;
    start = clock();

    int n;

    printf("Enter the size of the array : ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n*sizeof(int));

    printf("Enter the elements of the array : ");

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    mergeSort(arr, 0, n - 1);

    printf("The sorted array is : ");

    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    free(arr);
    end = clock();

    printf("\nSorted in %.10lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
}

void mergeSort(int arr[], int l, int h)
{
    if(l < h)
    {
        int m;
        m = l + (h - l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, h);
        merge(arr, l, m, h);
    }
}

void merge(int arr[], int l, int m, int h)
{
    int n1, n2;
    int i, j, k = l;

    n1 = m - l + 1;
    n2 = h - m;

    int L[n1], R[n2];

    for(i = 0; i < n1; i++)
        L[i] = arr[i + l];

    for(j = 0; j < n2; j++)
        R[j] = arr[j + m + 1];

    i = 0;
    j = 0;

    while(i < n1 && j < n2)
    {
        if(L[i] < R[j])
            arr[k] = L[i++];

        else
            arr[k] = R[j++];

        k++;
    }

    while(i < n1)
        arr[k++] = L[i++];

    while(j < n2)
        arr[k++] = R[j++];

}
