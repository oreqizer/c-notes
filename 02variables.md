# Variables

Declared by the syntax `T <name>;`, where `T` is a *type*. We can modify declarations with additional semantics:

* constants: `const T <name>;`
* initial values: `T <name> = <value>;`
* external: `extern T <name>;`

These declarations can be combined, with `extern` being 1st, `const` 2nd. Using all three, we can get something like `extern const T <name> = <value>;`.

### Constants

The `const` keyword is used for variables that won't be changed in the future.

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

> **Note:** It is a good practice to **not** declare any global variables if possible. If really needed, all global variables should be at the *top* of a file for clarity.

### Symbolic constants

They are useful for giving values a name, for example **Pi**. They are usually written all *UPPERCASE*. Their value can be any *string* or a *number*. Defined using the `#define`:

```c
#define PI 3.14159

void main() {
    float circle = 2 * PI;
}
```
