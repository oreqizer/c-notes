# Variables

Declared by the syntax `T <name>;`, where `T` is a *type*. We can modify declarations with additional semantics:

* constants: `const T <name>;`
* initial values: `T <name> = <value>;`
* external: `extern T <name>;`

These declarations can be combined. We can get something like `extern const T <name> = <value>;`.

### Declaration

Variables must be always declared before use (except when made implicit by context).

We can declare more *variables* of a *type* at the same time:

```c
int lower, upper, step;
char c, line[1000];
```

> **Note:** It is often more convenient to declare one variable per line to allow easy commenting and code formatting.

*External* and *static* variables are initialized to 0 by default. Other variables without an initial value are initialized to a *garbage* (undefined) value.

### Constants

The `const` keyword is used for variables that won't be changed in the future. Applies to all elements in the context of an *array*.

Functions can have a `const` on *array* arguments to indicate they won't be changed:

```c
int sum(const int[] nums, int len) {
    int sum = 0;
    for (int i = 0; i < len; i++) {
        sum += nums[i];  // 'nums' not changed
    }
    return sum;
}
```

### Symbolic constants

They are useful for giving values a name, for example **Pi**. They are usually written all *UPPERCASE*. Their value can be any *string* or a *number*. Defined using the `#define`:

```c
#define PI 3.14159

void main() {
    float circle = 2 * PI;
}
```

### Initialization

By default, initialization rules are loosely divided to two groups:

**External and static**:

* have initial value of 0
* initialization value must be a *constant expression*

**Automatic and registered**:

* *garbage* initial value
* initialization value may be an arbitrary *expression* or a *function* call

These types will be discussed further in [#8](./08scope.md).

*Arrays* can also be initialized with values:

```c
int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
```

The *length* will be the lowest possible if not specified, 12 in this case.
