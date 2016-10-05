#include <stdio.h>

#define BUFSIZE 100

char buf[BUFSIZE];
int buftop = 0;

char getch() {
    return buftop > 0 ? buf[--buftop] : getchar();
}

void ungetch(char c) {
    buf[buftop++] = c;
}
