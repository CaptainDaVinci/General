#include<stdio.h>

int main(void)
{
 int i,j,height,k;
    do
    {
        printf("height:");
        scanf("%d",&height);
    }
    while (height<0 || height>23 );

    for(i=0;i<height;i++)
    {

        for(j=height-1;j>i;j--)
        {
            printf(" ");
        }
        for(j=0;j<=i;j++)
        {
            printf("#");

        }
        printf("  ");
        for(j=0;j<=i;j++)
        {

            printf("#");

        }

        printf("\n");

    }
    return 0;


}
