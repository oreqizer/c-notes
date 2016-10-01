# Operators

Operators are symbols which operate on given values, producing a new one.

### Arithmetics

There are five arithmetic operators: `+`, `-`, `*`, `/` and `%`.

* *integer* division throws away the fractional part
* `%` cannot be applied to `float` or `double`
* truncation direction of `/` and sign of `%` are machine-dependent

They are **left-associative**. Precedence is in this order, from *highest* to *lowest*:

* unary `+` and `-`
* `*`, `/` and `%`
* binary `+` and `-`

### Logic

Pretty standard stuff: `<`, `>`, `>=`, `<=`, `!=`, `==`, `!`, `&&` and `||`.

Precedence *high* to *low*:

* all *arithmetic* operators
* `<`, `>`, `>=` and `<=`
* `!=` and `==`
* `&&`
* `||`

Unary `!`, negation, turns 0 to 1, and non-0 to 0. It has higher precedence than all *binary* operators, but lower than unary `+` and `-`.

Logical operators `&&` and `||` are **left-associative**, and are **lazy-evaluated**, allowing for a code like:

```c
int readlim(char s[], int lim) {
    int i = 0;
    while (i < lim - 1 && (s[i] = getchar()) != EOF) {
        i++;
    }
    return i;
}
```

> If it wasn't for lazy evaluation, `i < lim - 1 && (s[i] = getchar()) != EOF` would result in an unexpected behavior. `i < lim - 1` makes sure the whole expression ends before we try to assign something to `s[lim]`.
