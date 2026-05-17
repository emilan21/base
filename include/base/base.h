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

typedef struct {
  u8 *str;
  u64 size;
} string8;

#define KiB(n) ((u64)(n) << 10)
#define MiB(n) ((u64)(n) << 20)
#define GiB(n) ((u64)(n) << 30)

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

#define STR8_LIT(s) (string8){(u8 *)(s), sizeof(s) - 1}
#define STR8_FMT(s8) (int)(s8).size, (s8).str

string8 str8_substr(string8 str, u64 start, u64 end);

#endif
