#include "sorting.h"

static inline void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void bubble_sort(int *arr, int n)
{
    bool swapped = true;

    for (int i = 0; i < n - 1 && swapped; ++i)
    {
        swapped = false;
        for (int j = 0; j < n - 1 - i; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j + 1], arr[j]);
                swapped = true;
            }
        }
    }
}