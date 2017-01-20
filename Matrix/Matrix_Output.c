#include <stdio.h>

void print_matrix(int matrix[][10], int m, int n)
{
    int i, j, k;

    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%4d", matrix[i][j]);
        }
    }
}
