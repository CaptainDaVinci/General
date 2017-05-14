#include <algorithm>
#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include "sorting.h"

inline void reset_arr(std::vector<int> &arr, const std::vector<int> &temp_arr)
{
    for (int i = 0; i < arr.size(); ++i)
        arr[i] = temp_arr[i];
}

int main()
{
    int n;
    printf("Size: ");
    scanf("%d", &n);

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(-1000, 100);

    std::vector<int> arr(n);
    std::vector<int> temp_arr(n);

    for (int i = 0; i < n; ++i)
    {
        int num = dist(mt);

        arr[i] = num;
        temp_arr[i] = num;
    }

    clock_t start, end;

    /*BUBBLE SORT*/
    {
        reset_arr(arr, temp_arr);

        start = clock();
        bubble_sort(arr);
        end = clock();

        if (!std::is_sorted(arr.begin(), arr.end()))
        {
            printf("Not sorted!\n");
            return 1;
        }

        printf("\n>> Bubble Sort O(n^2)\n");
        printf("Time Taken: %.7lf\n\n", (double)(end - start) / CLOCKS_PER_SEC);
    }

    /*INSERTION SORT*/
    {
        reset_arr(arr, temp_arr);

        start = clock();
        insertion_sort(arr);
        end = clock();

        if (!std::is_sorted(arr.begin(), arr.end()))
        {
            printf("Not sorted!\n");
            return 1;
        }

        printf(">> Insertion Sort O(n^2)\n");
        printf("Time Taken: %.7lf\n\n", (double)(end - start) / CLOCKS_PER_SEC);
    }

    /*SELECTION SORT*/
    {
        reset_arr(arr, temp_arr);

        start = clock();
        selection_sort(arr);
        end = clock();

        if (!std::is_sorted(arr.begin(), arr.end()))
        {
            printf("Not sorted!\n");
            return 1;
        }

        printf(">> Selection Sort O(n^2)\n");
        printf("Time Taken: %.7lf\n\n", (double)(end - start) / CLOCKS_PER_SEC);
    }

     /*Standard Sorting algorithm*/
    {
        reset_arr(arr, temp_arr);

        start = clock();
        std::sort(arr.begin(), arr.end());
        end = clock();

        if (!std::is_sorted(arr.begin(), arr.end()))
        {
            printf("Not sorted!\n");
            return 1;
        }

        printf(">> Introsort\n");
        printf("Time Taken: %.7lf\n\n", (double)(end - start) / CLOCKS_PER_SEC);
    }

    /*MERGE SORT*/
    {
        reset_arr(arr, temp_arr);

        start = clock();
        merge_sort(arr, 0, n - 1);
        end = clock();

        if (!std::is_sorted(arr.begin(), arr.end()))
        {
            printf("Not sorted!\n");
            return 1;
        }

        printf("\n>> Merge Sort O(nlogn)\n");
        printf("Time Taken: %.7lf\n\n", (double)(end - start) / CLOCKS_PER_SEC);
    }

    /*QUICK SORT*/
    {
        /*First element as pivot*/
        {
            reset_arr(arr, temp_arr);

            start = clock();
            quick_sort(arr, 0, n - 1, 1);
            end = clock();

            if (!std::is_sorted(arr.begin(), arr.end()))
            {
                printf("Not sorted!\n");
                return 1;
            }

            printf(">> Quick Sort average case O(nlogn)\n\n");
            printf("First element as the pivot\n");
            printf("\tTime Taken: %.7lf\n", (double)(end - start) / CLOCKS_PER_SEC);
        }

        /*Last element as pivot*/
        {
            reset_arr(arr, temp_arr);

            start = clock();
            quick_sort(arr, 0, n - 1, 2);
            end = clock();

            if (!std::is_sorted(arr.begin(), arr.end()))
            {
                printf("Not sorted!\n");
                return 1;
            }

            printf("Last element as the pivot\n");
            printf("\tTime Taken: %.7lf\n", (double)(end - start) / CLOCKS_PER_SEC);
        }

        /*Random Pivot*/
        {
            reset_arr(arr, temp_arr);

            start = clock();
            quick_sort(arr, 0, n - 1, 3);
            end = clock();

            if (!std::is_sorted(arr.begin(), arr.end()))
            {
                printf("Not sorted!\n");
                return 1;
            }

            printf("Random pivot\n");
            printf("\tTime Taken: %.7lf\n", (double)(end - start) / CLOCKS_PER_SEC);
        }
    }
}