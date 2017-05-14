#include "sorting.h"

void selection_sort(std::vector<int> &arr)
{
    for(std::size_t i = 0; i < arr.size(); ++i)
    {
        int i_min = i;
        for(std::size_t j = i + 1; j < arr.size(); ++j)
        {
            if(arr[j] < arr[i_min])
                i_min = j;
        }

        int temp = arr[i];
        arr[i] = arr[i_min];
        arr[i_min] = temp;
    }
}