# Scope

Scope of *variables* and *functions* is mainly determined by the placement of the *declaration*. Conditions for the *name* to be in a scope:

* Declared in the same source file
* Declared *above* what we're interested in
* Declared outside of a function's scope

The scope lasts from the *declaration* to the end of the *source file*.

### External variables

The `extern` keyword is for using external variables within a function. It is only required when the variable is defined **after** the function body:

```c
void printstuff() {
    extern const char* stuff;
    printf("%s\n", stuff);  // "stuffs to print"
}

const char* stuff = "stuffs to print";
```

If it was declared **before** the function, the `extern` variable declaration is redundant:

```c
const char* before = "before stuff";

void printstuff() {
    extern const char* stuff;
    printf("%s\n", before);  // "before stuff", no 'extern' needed
    printf("%s\n", stuff);  // "stuffs to print"
}

const char* stuff = "stuffs to print";
```

If we *define* a variable outside of a function, *storage* is set aside for them:

```c
int number;
int arr[100];
```

*Declaring* an `extern` variable only make the variable available within the source file from that point forward, doesn't reserve storage for them:

```c
extern int number;
extern int arr[];  // array size is optional here, could also write 'arr[100];'
```

> **Note:** mind the difference between **declaration** and **definition** of an external variable. A *declaration* announces the properties of a variable, a *definition* also causes the *storage* to be set aside.

There can only be *one definition* of an external variable among all the source files that make up a program, others can only use `extern` to access it. The same file can use `extern` to access a variable defined *lower* than the line wanting to access it, as discussed above.

### Header files

A convenient way of centralizing *declarations* of various names, be it *functions* or *variables*. We can then `#include` them in a file, and they will all be available within the file:

```c
// rpc.h
#define NUMBER '0'
void push(double);
double pop(void);
int getop(char []);
int getch(void);
void ungetch(int);
```

It is convenient to maintain only *one* header file in smaller projects. It's worth splitting up only in larger ones.

### Static variables

Declared using the `static` keyword. These variables and functions have their *scope* limited to the source file they are declared in only - we cannot access them even using `extern`.

There's one special usage of `static` in internal function variables - when a variable is declared `static` within a function, the existence and *value* of the variable remains forever between all the function calls:

```c
void printplus() {
    static int i = 0;
    printf("%d ", i++);
}

int main() {
    printplus(); printplus(); printplus();  // 0 1 2
    return 0;
}
```

### Register variables

Variables that are heavily used can be declared as `register`. The compiler will try to put the variable into *registers*. The compiler can decide whether to do so or not, depending if the `register` declaration is valid, and whether there is a free register.

It can be applied only to *automatic variables* and *function parameters*:

```c
void turbo(register unsigned n) {
    register int i;
    // do some crazy computations
}
```

> **Note:** An *automatic* variable is one that is allocated and deallocated automatically when the program flow enters or leaves the variable's scope.

### Block scope

Variables declared inside *blocks* are only visible within that block. If a variable is declared with a name that already exists within an outer scope, it **shadows** the upper one until the end of the block:

```c
void dummy(int foo) {
    int bar = 13;
    if (foo == 37) {
        int bar = foo - 10;
        printf("%d\n", bar); // 27
    }
    printf("%d\n", bar); // 13
}
```
