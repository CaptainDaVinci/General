#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i, j, n, temp;
    printf("Enter the size of the array : ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n*sizeof(int));
    printf("Enter the elements of the unsorted array : ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (j = 0; j < n; j++)
    {
        for (i = 0; i < n - j - 1; i++)
        {
            if (arr[i] > arr[i+1])
            {
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
            else ;
        }
    }
    printf("The sorted array is : ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    free(arr);
    return 0;
}
