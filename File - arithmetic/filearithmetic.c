#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *p, *q;
    char b;
    int a, c;

    p = fopen("input.txt", "r");
    q = fopen("output.txt", "w");

    if(p == NULL || q == NULL)
    {
        printf("Error!\n");
        exit(1);
    }

    while(fscanf(p, " %d %c %d\n", &a, &b, &c) != EOF)
    {
        switch(b)
        {
            case '+' : fprintf(q, "%d\n", a + c);
                        break;

            case '-' : fprintf(q, "%d\n", a - c);
                        break;

            case '*' : fprintf(q, "%d\n", a * c);
                        break;

            case '/' : fprintf(q, "%.2f\n", (float)a / c);
                        break;
        }
    }

    fclose(p);
    fclose(q);

    return 0;
}
