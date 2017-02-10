void traverse()
{
    struct node *curr = head;
    if(head == NULL) // to check if list is empty.
    {
        printf("The List is empty\n");
        return;
    }
    while(curr != NULL) // traverse till the end of the list
    {
        printf("%d ", curr -> data);
        curr = curr -> link;
    }
    printf("\n");
}
