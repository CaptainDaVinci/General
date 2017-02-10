// Following is a recursive approach to traverse and
// is not used in the LinkedList.c file, on interchanging
// line 7 and 8, we can print the list in reverse, but
// not necessarily reverse the list.

void recursion(struct node *curr)
{
    if (curr == NULL) return;
    printf("%d ", curr -> data);
    recursion(curr -> link);
}
