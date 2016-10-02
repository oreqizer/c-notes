# Cycles

Useful for repeated stuff.

### For

Has the form:

```c
for (expr1; expr2; expr3)
    // statement
```

Runs until `expr2` is not 0. `expr1` and `expr3` are usually *assignments* or *function calls*. Any part can be omitted. If `expr2` is missing, the loop is infinite, unless the inner statement breaks from it.

When we drop any *expression*, we must retain the `;`:

```c
for (;;) {
    // infinite loop
}
```

### While

Basically a *for* rewritten as:

```c
expr1;
while (expr2) {
    // statement
    expr3;
}
```

> **Note:** Although we could do this kind of wizardry just fine, it is more common to use a `for` loop with *init & increment* style loops, so the operations are in one place.

Their behavior is identical, except for `continue`, where in a *while* the `expr2` is executed, in a *for* it jumps to `expr3`. More on that later.

### Do while

Not commonly used. A `while` that executes at least once:

```c
do {
    // stuff done at least once
} while (expr)
```
