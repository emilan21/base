# base.h

A small C header that defines common fixed-width type aliases and utility macros.

The goal of `base.h` is to provide a simple shared foundation that can be included by other C files or libraries.

## Features

- Short aliases for fixed-width integer types
- Boolean-style integer aliases
- Floating-point aliases
- Memory size helper macros
- Basic `MIN` and `MAX` macros

## Header

```c
#ifndef BASE_H
#define BASE_H

#include <stdint.h>

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef i8 b8;
typedef i32 b32;

typedef float f32;
typedef double f64;

#define KiB(n) ((u64)(n) << 10)
#define MiB(n) ((u64)(n) << 20)
#define GiB(n) ((u64)(n) << 30)

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

#endif
```

## Type Aliases

| Alias | Type |
|---|---|
| `i8` | `int8_t` |
| `i16` | `int16_t` |
| `i32` | `int32_t` |
| `i64` | `int64_t` |
| `u8` | `uint8_t` |
| `u16` | `uint16_t` |
| `u32` | `uint32_t` |
| `u64` | `uint64_t` |
| `b8` | `i8` |
| `b32` | `i32` |
| `f32` | `float` |
| `f64` | `double` |

## Integer Types

The integer aliases are based on the fixed-width integer types from `<stdint.h>`.

Examples:

```c
i32 count = 10;
u64 size = 1024;
```

These aliases make it easy to clearly express the size and signedness of integer values.

## Boolean Types

This header defines two simple boolean-style aliases:

```c
typedef i8 b8;
typedef i32 b32;
```

These are integer aliases intended to be used for boolean-style values.

Example:

```c
b32 is_running = 1;
b32 is_done = 0;
```

This header does not define `true` or `false`. If you want standard C boolean values, include `<stdbool.h>`.

## Floating-Point Types

The floating-point aliases are:

```c
typedef float f32;
typedef double f64;
```

Example:

```c
f32 speed = 12.5f;
f64 distance = 1000.0;
```

## Memory Size Macros

The memory size macros convert a number into bytes using powers of two.

```c
#define KiB(n) ((u64)(n) << 10)
#define MiB(n) ((u64)(n) << 20)
#define GiB(n) ((u64)(n) << 30)
```

Examples:

```c
u64 one_kib = KiB(1);   // 1024 bytes
u64 one_mib = MiB(1);   // 1,048,576 bytes
u64 one_gib = GiB(1);   // 1,073,741,824 bytes
```

Example usage:

```c
u64 buffer_size = MiB(64);
```

## Min and Max Macros

The `MIN` and `MAX` macros return the smaller or larger of two values.

```c
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
```

Example:

```c
i32 a = 10;
i32 b = 20;

i32 smaller = MIN(a, b);
i32 larger = MAX(a, b);
```

## Usage

Include `base.h` in any C source or header file that needs these common aliases or macros.

```c
#include "base.h"

int main(void) {
    u64 size = MiB(16);

    i32 a = 10;
    i32 b = 20;

    i32 min_value = MIN(a, b);
    i32 max_value = MAX(a, b);

    return 0;
}
```

## Using in Another Project

Since `base.h` is header-only, it does not need to be compiled into a static or shared library.

You can use it by copying the file into an include directory:

```text
my_project/
├── include/
│   └── base.h
└── src/
    └── main.c
```

Then include it in your source file:

```c
#include "base.h"
```

Compile with the include directory:

```sh
cc src/main.c -Iinclude -o my_program
```

## Notes

This file only contains typedefs and macros.

It is useful as a lightweight foundation header for small C projects, personal libraries, or programs where you want consistent type names across the codebase.
