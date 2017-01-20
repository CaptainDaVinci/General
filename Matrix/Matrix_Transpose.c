#include <stdio.h>

void transpose(int matrix[][10], int m, int n)
{
    int i, j;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            printf("%5d", matrix[j][i]);
        }

        printf("\n");
    }
}
