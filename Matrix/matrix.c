#include <stdio.h>
#include "matrix.h"

int main(void)
{
    int m, n, p, q, option;
    int matrixA[10][10];
    int matrixB[10][10];
    int matrixC[10][10];

    printf("1. Transpose\n");
    printf("2. Addition\n");
    printf("3. Multiplication\n");
    scanf("%d", &option);

    switch(option)
    {
        case 1: printf("Enter the order of the matrix : ");
                scanf("%d%d", &m, &n);
                printf("Enter the elements of the matrix\n");
                matrix_input(matrixA, m, n);
                printf("Transpose of the matrix is\n");
                transpose(matrixA, m, n);
                break;

        case 2: printf("Enter the order of matrix A : ");
                scanf("%d%d", &m, &n);

                printf("Enter the order of matrix B : ");
                scanf("%d%d", &p, &q);

                if(m == p && n == q)
                {
                    printf("Enter the elements of matrix A\n");
                    matrix_input(matrixA, m, n);

                    printf("Enter the elements of matrix B\n");
                    matrix_input(matrixB, p, q);

                    printf("Matrix A + Matrix B\n\n");
                    matrix_add(matrixA, matrixB, matrixC, m, n);
                    print_matrix(matrixC, m, n);

                }

                else printf("Matrix Addition Not Possible.\n");

                break;

        case 3: printf("Enter the order of matrix A : ");
                scanf("%d%d", &m, &n);

                printf ("Enter the order of matrix B : ");
                scanf("%d%d", &p, &q);

                if(m == q && n == p)
                {
                    printf("Enter the Elements of Matrix A\n");
                    matrix_input(matrixA, m, n);

                    printf("Enter the Elements of Matrix B\n");
                    matrix_input(matrixB, p, q);

                    printf("Matrix A * Matrix B \n\n");
                    matrix_mult(matrixA, matrixB, matrixC, m, n, q);
                    print_matrix(matrixC, m, q);
                }

                else printf("Matrix multiplication not possible.\n");

                break;

    }
}
