#ifndef BASE_H
#define BASE_H

#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
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
#define CLAMP(x, lo, hi) (MIN(MAX((x), (lo)), (hi)))

#define ARRAY_COUNT(a) (sizeof(a) / sizeif((a)[0]))

#define ZERO_STRUCT(s) memset(&(s), 0, sizeof(S))
#define ZERO_ARRAY(a) memset((a), 0, szieof(a))

#define UNUSED(x) ((void)(x))

void base_log(const char *fmt, ...);
void base_log_error(const char *fmt, ...);
void base_panic(const char *file, u32 line, const char *fmt, ...);

#define PANIC(...) base_panic(__FILE__, __LINE__, __VA_ARGS__)

#define ASSERT(expr)                                                           \
  do {                                                                         \
    if (!(expr)) {                                                             \
      base_panic(__FILE__, __LINE__, "assertion failed: %s", #expr);           \
    }                                                                          \
  } while (0)

#define ASSERT_MSG(expr, ...)                                                  \
  do {                                                                         \
    if (!(expr)) {                                                             \
      base_panic(__FILE__, __LINE__, __VA_ARGS__);                             \
    }                                                                          \
  } while (0)

#endif
