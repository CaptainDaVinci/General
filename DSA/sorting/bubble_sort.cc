#include "sorting.h"

static inline void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void bubble_sort(std::vector<int> &arr)
{
    bool swapped = true;

    for (std::size_t i = 0; i < arr.size() - 1 && swapped; ++i)
    {
        swapped = false;
        for (std::size_t j = 0; j < arr.size() - 1 - i; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j + 1], arr[j]);
                swapped = true;
            }
        }
    }
}