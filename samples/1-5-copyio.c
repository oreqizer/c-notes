#include <stdio.h>

int main() {
    int c; // EOF doesn't fit into 'char' which is 8bit
    while ((c = getchar()) != EOF) { // parentheses needed due to precedence
        putchar(c);
    }
    return 0;
}
