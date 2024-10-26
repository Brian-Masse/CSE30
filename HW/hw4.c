#include <stdio.h>

int main () {
    int x = 10;
    int len = 5;
    int *p = &x;

    int *endptr = p + len;
    int sum = 0;

    printf("len * 4 = %d\n", len << 2);

    while (p < endptr) {
        printf( "p: %p, endptr: %p\n", p, endptr );

        int num = *p++;

        printf( "num: %d, (num & 1): %d\n", num, (num & 1) );
        
        if (num & 1) {
            sum += num;
        }
    }

    printf( "sum: %d\n", sum );

}