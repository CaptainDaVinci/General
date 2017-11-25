#include <stdio.h>

struct Range {
    int start, end, max_val;
};

struct Range max_subarray_1(int *arr, int n) {
    int max = arr[0], curr_max = arr[0];
    int start = 0, end = 0, s = 0;
    for (int i = 1; i < n; ++i) {
        curr_max += arr[i];

        if (arr[i] > curr_max) {
            s = i;
            curr_max = arr[i];
        }

        if (curr_max >= max) {
            max = curr_max;
            end = i;
            start = s;
        }
    }

    struct Range range = {start, end, max};
    return range;
}

int main(void) {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    struct Range range = max_subarray_1(arr, n);
    printf("The maximum subarray is from %d to %d with sum %d\n", range.start, range.end, range.max_val);
}
