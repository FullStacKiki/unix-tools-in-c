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

int main(i32 argc, char *argv[]) {
  /*Reading from a file called with the point *f */
  FILE *f;
  /* If it has given a argument in the shell then*/
  if (argc > 1) {
    f = fopen(argv[1], "r");
    if (f == NULL) {
      perror(argv[1]);
      return -1;
    }
  } else {
    f = stdin; // f = input written in the terminal
  }
  i32 lines = 0, words = 0, chars = 0;
  i32 in_word = 0;
  i32 c;

  while ((c = getc(f)) != EOF) {
    chars++;
    if (c == '\n') {
      lines++;
    } // when we go to a new line lines++
    if (c == ' ' || c == '\n' || c == '\t') {
      in_word = 0;
    } else if (!in_word) {
      in_word = 1;
      words++;
    }
  }
  printf("%d righe, %d parole, %d caratteri\n", lines, words, chars);
  if (f != stdin) {
    fclose(f);
    return 0;
  }
}
