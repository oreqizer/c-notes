#include <stdio.h>

#define MAXLINE 1000

int readline(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
    int len;                // current line length
    int max = 0;            // max line length
    char line[MAXLINE];     // current line
    char longest[MAXLINE];  // longest line

    while ((len = readline(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }

    if (max > 0) {
        printf("%s", longest);
    }

    return 0;
}

int readline(char s[], int lim) {  // TODO fix
    int c, i;
    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; i++) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    return i;
}

void copy(char to[], char from[]) {
    int i = 0;
    while ((to[i] = from[i]) != '\0') {
        i++;
    }
}
