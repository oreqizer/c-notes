# Functions

The building blocks of our program. Syntax:

```
RT <name>(...T args) {
    // body
}
```

Where:

* `RT` is the function's *return* type. The return *value* is converted to the *type* if needed. It's an implicit `int` if omitted, default value is 0.
* `...T args` are *0-n* argument declarations of arbitrary types.

A minimal function is `dummy() {}`. Return value can be ignored when calling the function.

### Declaration

Functions should be declared before being used, so their *return type* (if it's non-`int`) and *argument types* are known. They are declared like variables:

```c
int main() {
    double res, tripleme(double);
    res = tripleme(tripleme(5));
    printf("%f\n", res);
    return 0;
}

double tripleme(double n) {
    return n * 3;
}
```

> **Note:** Functions are implicitly assumed to return an `int`, nothing is assumed of their arguments. Since this is not what we want most of the time, it's a good idea to **always** declare your functions.

Dummy variable names that *don't* have to match the implementation's names can be specified. We could write the above declaration like:

```c
double res, tripleme(double number);
```

If we don't specify any arguments to a function declaration, the argument checking is *turned off*. This exists for legacy reasons and should be avoided.

To specify that a function has *no arguments*, put `void` instead of the argument list.
