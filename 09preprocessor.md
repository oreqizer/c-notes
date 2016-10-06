# C Preprocessor

Does magics that happen before the compilation itself.

### Include

The `#include` directive is replaced with the contents of the specified *file*. The file can be specified in two ways. Say we want to include `stdio.h`:

* `"stdio.h"` begins the search at the location of the source file
* `<stdio.h>`, and search when *quoted* file wasn't found, is implementation dependent

### Macro substitution

The `#define` directive we've seen in [#3](./03variables.md) is capable a lot more than just symbolic constants. Any *name* can be defined with any *replacement text*:

```c
#define forever for (;;)

int main() {
    forever {
        printf("I will now print stuff to eternity.");
    }
}
```

Macros can also have *arguments*. It is important to surround them in *braces*, so operator precedence works as expected:

```c
#define max(A, B) ((A) > (B) ? (A) : (B))  // OK

#define power(x) x * x  // Wrong!
```

The expression `x = max(p+q, r+s);` then expands to:

```c
x = (p+q) > (r+s) ? (p+q) : (r+s);
```

> **Note:** Although macro substitution with arguments looks like a function call, it is not. It's a mere text replacement while preprocessing. It ain't Turing complete.

The part with macros only being text substitution is important, because if we do, say, `x = max(i++, j++);`, `i` and `j` will get incremented *twice*, due to how it replaces the text. Don't do that.

If an *argument* is prepended with `#`, the expression is turned into a **string**:

```c
#define debug(expr) printf(#expr " = %g\n", expr);

int main() {
    debug(2 + 3);  // printf("2 + 3" " = %g\n", 2 + 3); -> 2 + 3 = 5
}
```

The preprocessor operator `##` joins two names together:

```c
#define multivar(name, num) name ## num

int main() {
    int number1 = 13;
    int number2 = 37;
    // number ## 1 -> number1
    printf("%d\n", multivar(number, 1));  // 13
    // number ## 2 -> number2
    printf("%d\n", multivar(number, 2));  // 37
}
```

### Conditional inclusion

`#if` evaluates a *constant integer expression* (no function calls allowed). There are corresponding `#else`, `#elif` and `#endif` directives:

```c
// SYSTEM is a symbol with the system's name
#if SYSTEM == SYSV:
    #define HDR "sysv.h"
#elif SYSTEM == BSD:
    #define HDR "bsd.h"
#elif SYSTEM == MSDOS:
    #define HDR "msdos.h"
#else
    #define HDR "default.h"
#endif
#include HDR
```

Theres a `defined` preprocessor function that checks if a name has been defined before:

```c
#if !defined(HDR)
// define hdr.h
#endif
```

This is useful for not defining the same constant or including the same file multiple times. There are also `#ifdef` and `#ifndef` directives for checking if a name has been defined before:

```c
#ifndef HDR
#define HDR
// define hdr.h
#endif
```
