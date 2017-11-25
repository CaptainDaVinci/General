#ifndef SORTING_H
#define SORTING_H

#include <vector>

void merge_sort(std::vector<int> &arr, int l, int h);
void insertion_sort(std::vector<int> &arr);
void selection_sort(std::vector<int> &arr);
void bubble_sort(std::vector<int> &arr);
void quick_sort(std::vector<int> &arr, int l, int h, int op);

#endif