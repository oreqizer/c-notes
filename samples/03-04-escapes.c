/* Exercise 3-2 */
#include <stdio.h>

#define MAXLINE 256

void escape(char out[], char in[], int lim);
void unescape(char out[], char in[], int lim);

int main() {
    int i = 0;
    char c;
    char in[MAXLINE];
    char out[MAXLINE * 2];
    while (i < MAXLINE - 1 && (c = getchar()) != EOF) {
        in[i++] = c;
    }
    escape(out, in, MAXLINE);
    printf("Escaped:\n%s\n", out);
    unescape(in, out, MAXLINE);
    printf("Unescaped:\n%s\n", in);
    return 0;
}

void escape(char out[], char in[], int lim) {
    int o = 0;
    for (int i = 0; i < lim - 1; i++) {
        switch (in[i]) {
            case '\n':
                out[o++] = '\\';
                out[o++] = 'n';
                break;
            case '\t':
                out[o++] = '\\';
                out[o++] = 't';
                break;
            default:
                out[o++] = in[i];
        }
    }
}

void unescape(char out[], char in[], int lim) {
    char prev = '\0';
    char o = 0;
    for (int i = 0; i < lim - 1; i++) {
        if (prev == '\\') {
            switch (in[i]) {
                case 'n':
                    out[o - 1] = '\n';
                    break;
                case 't':
                    out[o - 1] = '\t';
                    break;
                default:
                    out[o++] = in[i];
            }
        } else {
            out[o++] = in[i];
        }
        prev = in[i];
    }
}
