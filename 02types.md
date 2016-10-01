# Types

**C** has only a few basic data types:

* `char` - a single byte, holds one character set
* `int` - an integer with the natural size of the host machine
* `float` - single precision floating point
* `double` - double precision floating point

### Modifiers

The basic types can have *modifiers* that adjust their byte size.

**Size**:

Specific size depends on the compiler.

* `short int` - more or equal 16bits, always no more than `int`
* `long int` - more or equal 32bits, always no less than `int`
* `long double` - extended-precision floating point, also applies `float` <= `double` <= `long double`

**Sign**:

Applies to `int`, `char`:

* `signed` - include also negative numbers
* `unsigned` - only negative numbers

*Unsigned* numbers can go up the size **2^n - 1**, *signed* are between **-2^(n-1)** to **2^(n-1) - 1**, where **n** is the number of bits. For example, `char`, which is 8bit, can have values 0 to 255 when unsigned, and -128 to 127 when signed.

Specifying only `long` implicitly means `long int`. This also applies to `signed` and `unsigned`.

### Default types

Certain values are certain types by default. We can alter the type with a *suffix*:

* `1234` - `signed int`
* `1234l` or `L` - `long`
* `1234u` or `U` - `unsigned int`
* `1234ul` or `UL` - `unsigned long`

A value too large to fit to `int` is implicitly `long`.

* `123.4` - `double`
* `1e-2` - `double`
* `123.4f` or `F` - `float`
* `123.4l` or `L` - `long double`

Alternative radix can be specified with a *prefix*:

* `01234` - octal (trailing `0`)
* `0x1234` - hexadecimal

### Character constants

An *integer* written as one character within single quotes, like `'x'`. It's a numeric value in the host machine's character set (usually **ASCII**).

> **Note:** although it's guaranteed that a character expression like `'x'` will never have a negative value, arbitrary bit patterns in a `char` may. It's thus better to always explicitly state `signed` or `unsigned`.

They can be manipulated the same way any other *integer* can, though they are most commonly used in comparisons with other `char`s.

Some characters are represented by *escape sequences*, like `'\n'` (newline). Arbitrary byte-sized bit pattern can also be used:

* `\ooo` where `o` is one of the *octal digits* (0..7)
* `\xx` where `x` is one of the *hexadecimal digits* (0..F)

There's a **null character**, written `'\0'`, that represents the character with numeric value of 0. Characters are this value by default.

### Constant expression

An *expression* that consists only of constants, and thus can be evaluated during compile time. They can thus be used in place of constants:

```c
#define MAXLINE 1000

char line[MAXLINE + 1];
```

### String literal

A sequence of *0-n* character surrounded by **double quotes**. They can be concatenated at compile time:

```c
printf("Hello, " "world");  // "Hello, world"
printf("Hello, "
       "other line");       // "Hello, other line"
```

Strings are an array of characters. They always have the *null character* at the end, so writing an empty string `""` is like an array of size one with the '\0' character.

`strlen` is a standard library function (in `<string.h>`) that determines the string length *excluding* the null character.

### Booleans

**C** has no explicit *Boolean* type. It goes by the rules:

* `0` is *false*
* non-`0` is *true*

### Enums

Defined using the `enum` keyword. It's a list of constant integer values with names. Default initial value is **0**, subsequent are always larger by 1:

```c
enum monster { ZOMBIE, CHICKEN, PIG };  // 0, 1, 2 respectively
```

We can specify their values manually:

```c
enum escapes { BELL = '\a', BACKSPACE = '\b', TAB = '\t', NEWLINE = '\n' };
```

Or describe the initial value and let it implicitly increment:

```c
enum months { JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC };
```

Names in an `enum` must be distinct. They are often used as a convenient alternative to `#define` symbolic constants, with the added benefit of debuggers being able to print the enumeration's symbolic form.

### Conversion

Conversions are done by a small number of rules:

* *narrower* to a *wider* type, meaning no information is lost, is done automatically (`int` -> `long`, `int` -> `float`...)
* expressions that don't make sense, like a `float` as a subscript are disallowed
* expressions that *may* lose information, e.g. `long` -> `int`, may only raise a warning

Arithmetic operations always convert it's operands to the *wider* one. If no `unsigned` is present, this set of rules is sufficient to remember:

* if `long double` -> `long double`
* if `double` -> `double`
* if `float` -> `float`
* `char` and `short` -> `int`
* if either operand is `long` convert to `long`

> **Note:** Conversion rules with `unsigned` are more complicated, because they depend on the machine's size of various *integer* types. Suppose `int` is 16bits, `long` is 32 bits, then `1U -> -1L`, which is a `signed long`. But `-1L -> 1UL`, because `-1L` is promoted to `unsigned long`, and appears as a very large number.

Longer *integers* are converted to shorter ones by dropping *high-order bits*.

Conversion is also done in assignment - *value* gets converted to a *type* where it's assigned:

```c
int i;
char c = 100;
float f = 13.37;

i = c;  // OK
c = i;  // OK due to the previous assignment
i = f;  // fractional part is lost :(
```

**Type casting** is also available in the form `(T)<value>`, producing a *new* value of the type `T`. Useful when a function expects a specific type (e.g. `sqrt` expects `double`, else producing nonsense).

If arguments are declared by a *function prototype*, types are coerced automatically.
