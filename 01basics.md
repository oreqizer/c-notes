# Basics

C is a low-level general purpose programming language. Characteristics:

* **imperative**
* **static**, but **weak** typing
* **low-level** hardware access

### Comments

```c
// single-line comment

/*
multi-line
comment
*/
```

### Symbolic constants

They are useful for giving values a name, for example **Pi**. They are usually written all *UPPERCASE*. Their value can be any *string* or a *number*. Defined using the `#define`:

```c
#define PI 3.14159

void main() {
    float circle = 2 * PI;
}
```
