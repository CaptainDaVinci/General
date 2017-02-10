/*

  Impilmentation of Double Linked Lists
  which contains features such as
  Inserting nodes at nth position
  Deleting a node at nth position
  traversing the list.
  Author : CaptainDaVinci

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 struct node
{
    int data;
    struct node *next;
    struct node *previous;
};

struct node *head;

void insert(int data);
void traverse(void);
void insert2(int data, int n);
void delete(int n);
void reverse();

int main(void)
{
    int n, data, i, option;
    head = NULL;

    printf("Enter the number of data to be inserted : ");
    scanf("%d", &n);

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

void insert(int data)
{
    struct node *new = malloc(sizeof(struct node));

    if(head == NULL)
    {
        head = new;
        new -> data = data;
        new -> next = NULL;
        new -> previous = head;
        return;
    }

    struct node *curr = head;

    while(curr -> next != NULL)
    {
        curr = curr -> next;
    }

    curr -> next = new;
    new -> previous = curr;
    new -> data = data;
    new -> next = NULL;
}

void traverse(void)
{
    if(head == NULL)
    {
        printf("The list is empty");
        return ;
    }

    struct node *curr = head;

    while(curr != NULL)
    {
        printf("%d ", curr -> data);
        curr = curr -> next;
    }
    printf("\n");
}

void insert2(int data, int n)
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct node *new = malloc(sizeof(struct node));
    struct node *curr = head;
    struct node *prev;
    int i;

    if(n == 1)
    {
        head = new;
        curr -> previous = new;
        new -> data = data;
        new -> next = curr;
        new -> previous = head;
        return;
    }

    for(i = 0; i < n - 2; i++)
    {
        curr = curr -> next;
    }
    new -> data = data;
    prev = curr -> next;
    curr -> next = new;
    new -> previous = curr;
    new -> next = prev;
    if(prev != NULL) prev -> previous = new;
}

void delete(int n)
{
    if(n == 0)
    {
        printf("Error\n");
        return;
    }

    int i;
    struct node *curr = head;
    struct node *prev;

    if(n == 1)
    {
        head = curr -> next;
        free(curr);
        return;
    }

    for(i = 0; i < n - 1; i++)
    {
        curr = curr -> next;
    }
    prev = curr -> previous;
    prev -> next = curr -> next;
    free(curr);
}

void reverse()
{
    struct node *prev = NULL;
    struct node *curr = head;
    while(curr != NULL)
    {
        curr -> previous = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = curr -> previous;
    }
    head = prev;
    prev -> previous = head;
}
