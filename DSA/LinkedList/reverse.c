void reverse()
{
    struct node *curr;
    struct node *prev;
    struct node *next;

    prev = NULL;
    curr = head;
    next = curr -> link;
    head = prev;

    while(curr != NULL)
    {
        curr -> link = prev;
        prev = curr;
        curr = next;
        if(next != NULL) next = next -> link;
    }
    head = prev;
}
