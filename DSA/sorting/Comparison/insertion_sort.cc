#include "sorting.h"

void insertion_sort(std::vector<int> &arr)
{
    for(std::size_t i = 1; i < arr.size(); ++i)
    {
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            --j;
        }
        
        arr[j + 1] = key;
    }
}