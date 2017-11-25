#include <stdio.h>

void swap(int *a, int *b);
void bubbleSort(int *arr, int n);

int main(void) {
    printf("Size: ");
    int n;
    scanf("%d", &n);

    int arr[n];

    printf("Elements: ");
    for (size_t i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, n);

    for (size_t i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

void bubbleSort(int *arr, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
