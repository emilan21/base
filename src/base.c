#include <base/base.h>

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

void base_log(const char *fmt, ...) {
  va_list args;
  va_start(args, fmt);

  vfprintf(stdout, fmt, args);
  fprintf(stdout, "\n");

  va_end(args);
}

void base_log_error(const char *fmt, ...) {
  va_list args;
  va_start(args, fmt);

  fprintf(stderr, "error: ");
  vfprintf(stderr, fmt, args);
  fprintf(stderr, "\n");

  va_end(args);
}

void base_panic(const char *file, u32 line, const char *fmt, ...) {
  va_list args;
  va_start(args, fmt);

  fprintf(stderr, "panic: ");
  vfprintf(stderr, fmt, args);
  fprintf(stderr, "\n");
  fprintf(stderr, "at %s:%d\n", file, line);

  va_end(args);

  abort();
}
