# Pointers

A *pointer* is a variable that contains the *address* of a *variable* in memory. Pointers have a *type* which is the same as the value pointed on.

* `*` unary operator is the *dereferencing* operator
* `&` unary operator obtains the address of a variable

Declaring a pointer is a *mnemonic* - it uses the same `*` operator as dereferencing does:

```c
int v = 13;
int *p = &v;  // pointer 'p' points to the address of 'v'
```

*Getting* and *setting* a value at the address where the pointer points is done using the `*` operator:

```c
int v = 37;
int *p = &v;  // *p = 37, points to 'v'
int *q = p;   // *q = 37, both 'p' and 'q' point to 'v'
*q *= 2;      // v = 74, *p = 74, *q = 74
```

> **Note:** Unary operators associate *right* to *left*, thus we need to surround expressions with parens when using more of them - incrementing a pointer with `++*p` is OK, but in `(*p)++` the parens are needed.

### Mutating arguments

Pointers can be used together with *functions* to mutate it's arguments:

```c
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int i = 37;
    int j = 13;
    printf("%d%d\n", i, j);  // 3713
    swap(&i, &j);            // swap takes pointers - pass addresses
    printf("%d%d\n", i, j);  // 1337
}
```

In the example, `swap` takes two addresses and swaps the underlying values.

> **Note:** Be careful when using this pattern! It may be confusing and hard to track in a big programs if functions arbitrarily change values passed to them.
