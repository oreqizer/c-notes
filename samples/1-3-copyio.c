#include <stdio.h>

int main() {
    int c; // EOF doesn't fit into 'char' which is 8bit
    while ((c = getchar()) != EOF) {
        putchar(c);
    }
    return 0;
}
