#include <stdio.h>

void insertionSort(int *arr, int n);

int main(void) {
    printf("Size: ");
    int n;
    scanf("%d", &n);

    int arr[n];

    printf("Elements: ");
    for (size_t i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    insertionSort(arr, n);

    for (size_t i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

void insertionSort(int *arr, int n) {
    for (int i = 1; i < n; ++i) {
        int j = i - 1;
        int key = arr[i];

        while (j >= 0 && key < arr[j]) {
            arr[j + 1] = arr[j];
            --j;
        }

        arr[j + 1] = key;
    }
}
