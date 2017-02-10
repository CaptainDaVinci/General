#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void)
{
    printf("Range of INT: %d to %d\n", INT_MIN, INT_MAX);
    printf("Range of Unsigned INT: 0 to %u\n\n", UINT_MAX);

    printf("Range of SHORT: %d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("Range of Unsigned SHORT: 0 to %u\n\n", SHRT_MAX);

    printf("Range of CHAR: %d to %d\n", CHAR_MIN, CHAR_MAX);
    printf("Range of Unsigned INT: 0 to %d\n\n", CHAR_MAX);

    printf("Range of LONG: %ld to %ld\n", LONG_MIN, LONG_MAX);
    printf("Range of Unsigned INT: 0 to %lu\n\n", ULONG_MAX);

    printf("Range of FLOAT: %f to %e\n\n", FLT_MIN, FLT_MAX);

    printf("Range of DOUBLE: %lf to %e\n", DBL_MIN, DBL_MAX);
}
