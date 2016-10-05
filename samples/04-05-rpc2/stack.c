#define MAXVAL 100

double stack[MAXVAL];
int stacktop = 0;

void push(double n) {
    stack[stacktop++] = n;
}

double pop() {
    return stack[--stacktop];
}
