#include <stdio.h>
#include <ctype.h>
#include "rpc.h"

int getop(char s[]) {
    int i, c;
    while ((s[0] = c = getch()) == ' '); // skip whitespace
    s[1] = '\0';
    if (!isdigit(c) && c != '.') {
        return c;
    }
    i = 0;
    if (isdigit(c)) {
        // int part
        while (isdigit(s[++i] = c = getch()));
    }
    if (c == '.') {
        // frac part
        while (isdigit(s[++i] = c = getch()));
    }
    s[i] = '\0';
    if (c != EOF) {
        ungetch(c);
    }
    return NUMBER;
}
