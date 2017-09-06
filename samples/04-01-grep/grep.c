#include <stdio.h>

#define MAXLINE 1000

int readline(char line[], int max);
int strindex(char line[], char grep[]);

int main(int argc, char* argv[]) {
    char line[MAXLINE];
    char* pattern = argv[1]; // requred param
    int found = 0;

    while (readline(line, MAXLINE) > 0) {
        if (strindex(line, pattern) >= 0) {
            printf("%s", line);
            found++;
        }
    }
    return !found;
}

int readline(char line[], int max) {
    int c, i;
    for (i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        line[i] = c;
    }
    if (c == '\n') {
        line[i] = c;
        i++;
    }
    line[i] = '\0';
    return i;
}

int strindex(char line[], char grep[]) {
    int i, j, k;
    for (i = 0; line[i] != '\0'; i++) {
        for (j = i, k = 0; grep[k] != '\0' && line[j] == grep[k]; j++, k++);
        if (k > 0 && grep[k] == '\0') {
            return i;
        }
    }
    return -1;
}
