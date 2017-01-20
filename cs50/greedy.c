#include<stdio.h>

int main(void)
{
     int a = 0, b = 0, c = 0, d = 0, changes = 0;
     float change;

     do
     {
        printf("change:");
        scanf("%f",&change);
     }
     while(change<0);

    changes = change*100;


    while(changes >= 25)
    {
        a = changes/25;
        changes = changes%25;
    }

    while(changes >= 10 )
    {
       b = changes/10;
       changes = changes%10;
    }

    while(changes >= 5)
    {
       c = changes/5;
       changes = changes%5;
    }

    if(changes >= 1 )
    {
       d = changes;
    }

    printf("%d",a+b+c+d);

    return 0;
}
