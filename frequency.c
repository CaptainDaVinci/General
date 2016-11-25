#include <stdio.h>

int main(void)
{
    int i, j;
    int n, count;
    int arr[100], freq[100];
    printf("Enter the size of the array : ");
    scanf("%d", &n);
    printf("Enter the elements of the array : ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        freq[i] = -1;
    }
    // Calculating the frequency.
    for(i = 0; i < n; i++)
    {
        count = 1;
        if (freq[i] != 0)
        {
            for ( j = i + 1; j < n; j++)
            {
                if (arr[i] == arr[j])
                {
                    freq[j] = 0;
                    count++;
                }
            }
            freq[i] = count;
        }
    }

    for(i = 0; i < n; i++)
    {
        if (freq[i] != 0)
        {
            printf("Element : %d, Frequency : %d\n", arr[i], freq[i]);
        }
    }
    return 0;
}
