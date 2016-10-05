/*
NOTE:
I totally ignored any error handling of stack over/underflows.
Bear that in mind when testing.
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "rpc.h"

#define MAXOP 100

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
