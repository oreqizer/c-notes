#include <stdio.h>

int main() {
    char c;
    char prev;
    int first = 1;
    while ((c = getchar()) != EOF) {
        if (!first) {
            if (prev != ' ' || c != ' ') {
                putchar(c);
            }
        } else {
            first = 0;
            putchar(c);
        }
        prev = c;
    }
    return 0;
}
