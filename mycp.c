#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
  FILE *in;
  FILE *out;
  if (strcmp(argv[1], argv[2]) != 0) {
    if (arcg != 2) {
      in = fopen(argv[1], "r");
      out = fopen(argv[2], "w");
      if (in == NULL) {
        perror(argv[1]);
        return 1;
      }
    } else {
      in = stdin;
    }
    i32 c;
    while ((c = getc(in)) != EOF) {
      putc(c, out);
    }
    if (in != stdin) {
      fclose(in);
      fclose(out);
      return 0;
    }
  } else {
    return 0;
  }
}
