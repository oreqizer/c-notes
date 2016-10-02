# Control flow

Determine which branches of a code and in which order will be executed.

### Statements & Blocks

An *expression* becomes a *statement* when it's followed by a `;`, which is a **statement terminator** in **C**.

Braces `{` and `}` group statements and declarations to **blocks**, which are syntactically equivalent to a single statement.

### If & else

Determine branching. *Non-zero* expression gets chosen. They can be written without braces

```c
if (expr)
    // statement1;
else
    // statement2;
```

where the `else` part is always connected to the closest `if`, or with braces, so our intentions are explicit:

```c
if (expr) {
    // block 1
} else {
    // block 2
}
```

We can chain more `if` + `else` statements:

```c
if (expr1) {
    // block 1
} else if (expr2) {
    // block 2
} else {
    // block 3
}
```

The `else` part is optional, so `if (expr) fn();` is perfectly OK.

### Switch

A multi-way decision:

```c
switch (expr) {
    case 1:
        // statement 1
        break;
    case 3:
    case 7:
        // statement 2
        break;
    default:
        // statement 3
}
```

Execution starts with the first match, and is *fall-through*, thus `break` statements are needed. The `default` is optional. Order of specifying `case` and `default` clauses doesn't matter.

### GOTO

The forbidden fruit, a `goto` statement is used to jump to a *label* execution, mostly from nested loops.

```c
for (; expr1;) {
    for (; expr2;) {
        if (disaster)
            goto error;  // any name can be chosen, 'error' is just an example
    }
}

error:
    // mess cleanup statement
```

> **NEVER** use this unless you are **totally** sure what you are doing! For each `goto`, there are two better ways of doing things.
