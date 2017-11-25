#include <stdio.h>

void swap(int *a, int *b);
void selectionSort(int *arr, int n);

int main(void) {
    printf("Size: ");
    int n;
    scanf("%d", &n);

    int arr[n];

    printf("Elements: ");
    for (size_t i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    selectionSort(arr, n);

    for (size_t i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

void selectionSort(int *arr, int n) {
    for (int i = 0; i < n - 1; ++i) {
        int min = i;

        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }

        swap(&arr[i], &arr[min]);
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
