#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int i, j;
    int m, n, p, q;
    int matrix_a[10][10], matrix_b[10][10];
    printf("Enter the order of first matrix : ");
    scanf("%d%d", &m, &n);
    printf("Enter the order of second matrix : ");
    scanf("%d%d", &p, &q);
    if (m != p && n != q)
    {
        printf("Matrix addition not possible\n");
        exit(0);
    }
    printf("Enter the elements of Matrix A :\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &matrix_a[i][j]);
        }
    }
    printf("Enter the elements of Matrix B :\n");
    for (i = 0; i < p; i++)
    {
        for (j = 0; j < q; j++)
        {
            scanf("%d", &matrix_b[i][j]);
        }
    }
    printf("Matrix A + Matrix B =\n");
    for (i = 0; i < m ; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf(" %5d ", matrix_a[i][j] + matrix_b[i][j]);
        }
        printf("\n");
    }

}
