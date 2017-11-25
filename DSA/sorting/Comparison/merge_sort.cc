#include "sorting.h"

static void merge(std::vector<int> &arr, int l, int m, int h)
{
    int n1 = m - l + 1;
    int n2 = h - m;
    int left[n1], right[n2];

    for(int i = 0; i < n1; ++i)
        left[i] = arr[l + i];
    
    for(int i = 0; i < n2; ++i)
        right[i] = arr[m + 1 + i];
    
    int i = 0, j = 0, k = l;

    while(i < n1 && j < n2)
        arr[k++] = (left[i] < right[j]) ? left[i++] : right[j++];
    
    while(i < n1)
        arr[k++] = left[i++];
    
    while(j < n2)
        arr[k++] = right[j++];
}

void merge_sort(std::vector<int> &arr, int l, int h)
{
    if(l >= h)
        return ;
    
    int m = (l + h) / 2;
    merge_sort(arr, l, m);
    merge_sort(arr, m + 1, h);
    merge(arr, l, m, h);
}