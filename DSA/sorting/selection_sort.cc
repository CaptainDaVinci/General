#include "sorting.h"

void selection_sort(int *arr, int n)
{
    for(int i = 0; i < n; ++i)
    {
        int i_min = i;
        for(int j = i + 1; j < n; ++j)
        {
            if(arr[j] < arr[i_min])
                i_min = j;
        }

        int temp = arr[i];
        arr[i] = arr[i_min];
        arr[i_min] = temp;
    }
}