#include <stdio.h>
#include "matrix.h"

void matrix_add(int matrixA[][10],int matrixB[][10], int matrixC[][10], int m, int n)
{
    int i, j;

    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            matrixC[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}
