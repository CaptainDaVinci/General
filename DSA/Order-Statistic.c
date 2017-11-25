#include <stdio.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int *arr, int l, int h) {
    int pivot = arr[l];
    int index = l;

    for (int i = l + 1; i <= h; ++i) {
        if (arr[i] <= pivot) {
            ++index;
            swap(arr + i, arr + index);
        }
    }

    swap(arr + l, arr + index);

    return index;
}

int order_statistic(int *arr, int l, int h, int target) {
    if (l >= h) {
        return arr[l];
    }

    int pivot = partition(arr, l, h);

    if (pivot == target) {
        return arr[pivot];
    }

    if (pivot < target) {
        return order_statistic(arr, pivot + 1, h, target);
    }

    return order_statistic(arr, l, pivot - 1, target);
}

int main(void) {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; ++i) {
        scanf("%d", arr + i);
    }

    int target;
    printf("Enter the target element: ");
    scanf("%d", &target);

    printf("The %d smallest element is %d\n", target, order_statistic(arr, 0, n - 1, target - 1));
}
