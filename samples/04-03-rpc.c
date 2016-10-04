/*
NOTE:
I totally ignored any error handling of stack over/underflows.
Bear that in mind when testing.
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100
#define MAXVAL 100
#define BUFSIZE 100
#define NUMBER '0'

double stack[MAXVAL];
int stacktop = 0;

void push(double n);
double pop(void);

char buf[BUFSIZE];
int buftop = 0;

char getch(void);
void ungetch(char c);
int getop(char s[]);

int main() {
    int type;
    char input[MAXOP];
    double op2;

    while ((type = getop(input)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(input));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                // evaluation order is NOT guaranteed in non-commutative operators
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                push(pop() / op2);
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
        }
    }
    return 0;
}

void push(double n) {
    stack[stacktop++] = n;
}

double pop() {
    return stack[--stacktop];
}

char getch() {
    return buftop > 0 ? buf[--buftop] : getchar();
}

void ungetch(char c) {
    buf[buftop++] = c;
}

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
