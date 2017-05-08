#include "sorting.h"
#include <random>
#include <cstdio>

std::random_device rd;
std::mt19937 mt(rd());

static inline void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

static int partition_l(int *arr, int l, int h)
{
    int pivot = arr[l];
    int p_index = l;

    for (int i = l + 1; i <= h; ++i)
    {
        if (arr[i] <= pivot)
        {
            ++p_index;
            swap(arr[i], arr[p_index]);
        }
    }
    swap(arr[l], arr[p_index]);

    return p_index;
}

static int partition_h(int *arr, int l, int h)
{
    int pivot = arr[h];
    int p_index = l;

    for (int i = l; i <= h - 1; ++i)
    {
        if (arr[i] <= pivot)
        {
            swap(arr[i], arr[p_index]);
            ++p_index;
        }
    }
    swap(arr[h], arr[p_index]);

    return p_index;
}

static int partition_r(int *arr, int l, int h)
{
    std::uniform_int_distribution<int> dist(l, h);
    int p_index = dist(mt);
    int pivot = arr[p_index];

    swap(arr[l], arr[p_index]);
    p_index = l;

    for(int i = l + 1; i <= h; ++i)
    {
        if(arr[i] <= pivot)
        {
            ++p_index;
            swap(arr[i], arr[p_index]);
        }
    }
    swap(arr[l], arr[p_index]);

    return p_index;
}

void quick_sort(int *arr, int l, int h, int op)
{
    if (l >= h)
        return;

    int p_index;

    switch (op)
    {
    case 1:
        p_index = partition_l(arr, l, h);
        break;

    case 2:
        p_index = partition_h(arr, l, h);
        break;

    case 3:
        p_index = partition_r(arr, l, h);
    }

    quick_sort(arr, l, p_index - 1, op);
    quick_sort(arr, p_index + 1, h, op);
}
