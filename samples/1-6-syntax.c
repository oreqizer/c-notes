#include <stdio.h>

#define MAXLINE 1000

int readline(char line[], int maxline);
void clear(char line[], int len);
int detectcomment(char line[], int len, int in_comment);
int clearline(char line[], int len, int in_comment);
void replace(char line[], int len, int start, int end);

int main() {
    int len;
    char line[MAXLINE];

    int bround = 0;
    int bsquare = 0;
    int bcurly = 0;

    int in_comment = 0;
    int in_sq_string = 0;
    int in_dq_string = 0;

    char prev = -1; // will never be a valid char
    char prev2 = -1; // will never be a valid char
    int next_comment;
    while ((len = readline(line, MAXLINE)) > 0) {
        next_comment = detectcomment(line, len, in_comment);
        len = clearline(line, len, in_comment);

        for (int i = 0; i < len; i++) {
            if (!in_sq_string && !in_dq_string) {
                switch (line[i]) {
                    case '(': bround++; break;
                    case ')': bround--; break;
                    case '[': bsquare++; break;
                    case ']': bsquare--; break;
                    case '{': bcurly++; break;
                    case '}': bcurly--; break;
                }
            }

            // check for negative brackets
            if (bround < 0) { printf("Mismatched ( ).\n"); return 1; }
            if (bsquare < 0) { printf("Mismatched [ ].\n"); return 1; }
            if (bcurly < 0) { printf("Mismatched { }.\n"); return 1; }
            if (in_dq_string < 0) { printf("Mismatched \" \".\n"); return 1; }
            if (in_sq_string < 0) { printf("Mismatched ' '.\n"); return 1; }

            // TODO there's a weird bug with mismatched ( ) in this 'if':
            if (line[i] == '\''
                && !in_dq_string
                && !(in_sq_string && prev == '\\' && prev2 != '\\')) {
                in_sq_string = !in_sq_string;
            } else if (line[i] == '\"'
                && !in_sq_string
                && !(in_dq_string && prev == '\\' && prev2 != '\\')) {
                in_dq_string = !in_dq_string;
            }
            prev2 = prev;
            prev = line[i];
        }
        clear(line, MAXLINE);
        in_comment = next_comment;
    }

    if (bround) { printf("Mismatched ( ).\n"); return 1; }
    if (bsquare) { printf("Mismatched [ ].\n"); return 1; }
    if (bcurly) { printf("Mismatched { }.\n"); return 1; }
    if (in_dq_string) { printf("Mismatched \" \".\n"); return 1; }
    if (in_sq_string) { printf("Mismatched ' '.\n"); return 1; }

    printf("OK.\n");
    return 0;
}

int readline(char s[], int lim) {
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        s[i] = c;
    }
    if (c != EOF) {
        s[i] = '\n';
        i++;
    }
    return i;
}

void clear(char s[], int len) {
    for (int i = 0; i < len; i++) {
        s[i] = '\0';
    }
}

int detectcomment(char s[], int len, int in_comment) {
    char prev = -1; // will never be a valid char
    for (int i = 0; i < len; i++) {
        if (in_comment) {
            if (prev == '*' && s[i] == '/') in_comment = 0;
        } else {
            // single-line comments are single-line
            if (prev == '/' && s[i] == '/') {
                return 0;
            }

            if (prev == '/' && s[i] == '*') in_comment = 1;
        }

        prev = s[i];
    }
    return in_comment;
}

int clearline(char s[], int len, int in_comment) {
    char prev = -1; // will never be a valid char
    int start = 0;
    int newlen = len;
    for (int i = 0; i < len; i++) {
        if (in_comment) {
            if (prev == '*' && s[i] == '/') {
                in_comment = 0;
                replace(s, len, start, i + 1);
                newlen -= i - start + 1;
            }
        } else {
            // single-line comment
            if (prev == '/' && s[i] == '/') {
                replace(s, len, i - 1, len);
                newlen -= len - i + 1;
                s[newlen - 1] = '\n';
                break;
            }

            if (prev == '/' && s[i] == '*') {
                in_comment = 1;
                start = i - 1;
            }
        }

        prev = s[i];
    }
    // line ends with a comment
    if (in_comment) {
        replace(s, len, start, len);
        newlen -= len - start;
    }
    return newlen;
}

void replace(char s[], int len, int start, int end) {
    int shift = end - start;
    for (int i = start; i < len; i++) {
        s[i] = s[i + shift];
    }
}
