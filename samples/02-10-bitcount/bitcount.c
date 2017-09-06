/* Exercise 2-9 */
#include <stdio.h>
#include <stdlib.h>

int bitcount(unsigned x) {
    /*
    'x &= (x - 1)' works by the fact '-1' always flips all 0s to 1s
    and the first 1 to 0. Since we are doing this sequentially, the
    leading 1s are ANDed with 0s from the previous iterations, thus
    keeping 0, and the first 0 occurence shuts down the first bit.
    */
    int count;
    for (count = 0; x != 0; x &= (x - 1)) {
        count ++;
    }
    return count;
}

int main(int argc, const char** argv) {
    if (argc < 2) {
        printf("Not enough arguments.\n");
        return 1;
    }

    int num = atoi(argv[1]);
    printf("Bits: %d\n", bitcount(num));
    return 0;
}
