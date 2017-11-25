#include <stdio.h>

void mergeSort(int *arr, int l, int h);
void merge(int *arr, int l, int m, int h);

int main(void) {
    printf("Size: ");
    int n;
    scanf("%d", &n);

    int arr[n];

    printf("Elements: ");
    for (size_t i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, 0, n - 1);

    for (size_t i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

void mergeSort(int *arr, int l, int h) {
    if (l < h) {
        int m = (l + h) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, h);
        merge(arr, l, m, h);
    }
}

void merge(int *arr, int l, int m, int h) {
    int n1 = m - l + 1;
    int n2 = h - m;

    int left[n1], right[n2];

    for (size_t i = 0; i < n1; i++) {
        left[i] = arr[l + i];
    }

    for (size_t i = 0; i < n2; i++) {
        right[i] = arr[m + i + 1];
    }

    int i, j, k;
    i = j = 0;
    k = l;

    while (i < n1 && j < n2) {
        arr[k++] = (left[i] < right[j]) ? left[i++] : right[j++];
    }

    while (i < n1) {
        arr[k++] = left[i++];
    }

    while (j < n2) {
        arr[k++] = right[j++];
    }
}
