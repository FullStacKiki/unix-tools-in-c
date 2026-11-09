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
  i32 c;
  i32 count[26] = {0};
  while ((c = getc(f)) != EOF) {
    putchar(c);
    if (c >= 'a' && c <= 'z') {
      count[c - 'a']++;
    } else if (c >= 'A' && c <= 'Z') {
      count[c - 'A']++;
    }
  }
  for (i32 i = 0; i < 26; i++) {
    if (count[i] > 0) {
      printf("%c : %d \n", 'a' + i, count[i]);
    }
  }
  if (f != stdin) {
    fclose(f);
  }
  return 0;
}
