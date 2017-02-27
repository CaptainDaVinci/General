#include <stdio.h>
#include "matrix.h"

void matrix_input(int matrix[][10], int m, int n)
{
    int i, j;

    for(i = 0; i < m && i < 10; i++)
    {
        for(j = 0; j < n && j < 10; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}
