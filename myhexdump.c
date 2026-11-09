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

int main(i32 argc, char *argv[]) {
  FILE *f;
  if (argc > 1) {
    f = fopen(argv[1], "r");
    if (f == NULL) {
      perror(argv[1]);
      return 1;
    }
  } else {
    f = stdin;
  }
  i32 bytes_occupied = 0;
  i32 c;
  printf("\nBytes totally occupied for each line: \n");
  printf(" %08x", bytes_occupied);
  while ((c = getc(f)) != EOF) {
    bytes_occupied++;
    printf(" %02x ", c);
    if (bytes_occupied % 16 == 0) {
      printf("\n %08x", bytes_occupied);
    }
  }
  printf("\n");
  if (f != stdin) {
    fclose(f);
  }
  return 0;
}
