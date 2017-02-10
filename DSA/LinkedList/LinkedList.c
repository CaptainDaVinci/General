/*

  Impilmentation of Linked Lists
  which contains features such as
  Inserting nodes at nth position
  Deleting a node at nth position
  traversing the list.
  Author : CaptainDaVinci

*/
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int main(void)
{
    head = NULL;
    int n, data, i, option;
    printf("Enter the number of data to be inserted : ");
    scanf("%d", &n);

    if(n == 0)
    {
        printf("No elements to insert\n");
        exit(1);
    }

    printf("Enter the data : ");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &data);
        insert(data);
    }

    printf("1.Insert\n2.Traverse\n3.Delete\n4.Reverse\n5.Exit\n");

    repeat :

    printf("\nOption   : ");
    scanf("%d", &option);

    switch(option)                  //bit of overkill :)
    {
        case 1 : printf("Data     : ");
                 scanf("%d", &data);
                 printf("Position : ");
                 scanf("%d", &n);
                 if(n != 0)
                 insert2(data, n);
                 else printf("Not a valid position\n");
                 break;

        case 2 : traverse();
                 break;

        case 3 : printf("Position : ");
                 scanf("%d", &n);
                 if(n != 0)
                 delete(n);
                 else printf("Not a valid position\n");
                 break;

        case 4 : reverse();
                 break;

        case 5 : exit(0);

        default : printf("ERROR-Enter a valid option\n");
    }

    goto repeat;

    return 0;
}
