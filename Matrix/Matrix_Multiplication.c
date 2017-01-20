#include <stdio.h>

void matrix_mult(int matrixA[][10], int matrixB[][10], int matrixC[][10], int m, int n, int q)
{
    int i, j, k;

    for(i = 0; i < m; i++)
    {
        for(j = 0; j < q; j++)
        {
            matrixC[i][j] = 0;

            for(k = 0; k < n; k++)
            {
                matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    print_matrix(matrixA, m, n);
}
