#include <stdio.h>

void swap(int *a, int *b);
void quickSort(int *arr, int l, int h);
int partition(int *arr, int l, int h);

int main(void) {
    printf("Size: ");
    int n;
    scanf("%d", &n);

    int arr[n];

    printf("Elements: ");
    for (size_t i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    quickSort(arr, 0, n - 1);

    for (size_t i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

void quickSort(int *arr, int l, int h) {
    if (l >= h) {
        return ;
    }

    int pivot = partition(arr, l, h);
    quickSort(arr, 0, pivot - 1);
    quickSort(arr, pivot + 1, h);
}

int partition(int *arr, int l, int h) {
    int pivot = arr[l];
    int pivot_index = l;

    for (int i = l + 1; i <= h; ++i) {
        if (arr[i] <= pivot) {
            ++pivot_index;
            swap(&arr[i], &arr[pivot_index]);
        }
    }

    swap(&arr[l], &arr[pivot_index]);

    return pivot_index;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
