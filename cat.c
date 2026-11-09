#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef float f32;
typedef double f64;

int main(i32 arcg, char *argv[]) {
  FILE *f;
  if (arcg > 2) {
    f = fopen(argv[2], "r");
    if (f == NULL) {
      perror(argv[2]);
      return 1;
    }
  } else {
    f = stdin;
  }
  i32 max = atoi(argv[1]);
  i32 c;
  i32 lines = 0;
  while ((c = getc(f)) != EOF && lines < max) {
    putchar(c);
    if (c == '\n') {
      lines++;
    }
  }
  if (f != stdin) {
    fclose(f);
    return 0;
  }
}
