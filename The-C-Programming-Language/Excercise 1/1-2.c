#include <stdio.h>

int main(void)
{
    printf("hello, \cworld\n"); // prints hello, cworld (as \c is not an escape sequence).
    return 0;
}
