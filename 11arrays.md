# Arrays

Arrays and pointers share a lot in common in **C**. Creating an array gives us the address of the _0th_ element:

```c
int a[5] = {1, 2, 3, 4, 5};
int *pa = &a[0]; // pa == a
```

### Pointer arithmetics

The ability to do math on pointers. It is _consistent_, meaning that when a type occupies more space, doing `p++` still advances the position to the next element of the type.

* `a[9]` gets the _10th_ element
* `*(a + 4)` gets the _5th_ element

> Note: a pointer is a _variable_ and we can modify it with `pa = a;` or `pa++;`. Array, however, is not, and thus these constructs would be illegal.

Valid operations:

* addition and subtraction
* assignment
* comparison of pointers to the same array
* comparison to `NULL`

### Strings

A string is just an array of characters ending with the `\0` character. Thus, the length of a string is always one character longer.

There's a difference between definitions:

```c
char atxt[] = "kek"; // an array
char *ptxt = "kek"; // a pointer to a string constant (const char*)
```

You can modify `atxt`, but you can only make `ptxt` point elsewhere.
