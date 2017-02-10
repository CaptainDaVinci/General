void insert(int x)
{
    struct node *curr = malloc(sizeof(struct node));

    if(head == NULL)    // for empty list condition
    {
        head = curr;
        curr -> data = x;
        curr -> link = NULL;
        return;
    }
    struct node *prev = head;
    while(prev -> link != NULL) // traverse throughout the list
    {
        prev = prev -> link;
    }
    curr -> data = x;
    prev -> link = curr;
    curr -> link = NULL;
}
