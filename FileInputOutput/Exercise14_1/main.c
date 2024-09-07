#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ENTRIES 1
const char FILE_NAME[] = "dummy_testfile.txt";

int main(void) {

  FILE *in_file;
  in_file = fopen(FILE_NAME, "r");

  if (in_file == NULL)
  {
    printf("Cannot open %s\n", FILE_NAME);
    exit(8);
  }
  
  char ch;
  char prev;
  int counter = 0;
  bool char_in_line = false;

  while (1)
  {
    ch = fgetc(in_file);
    if (ch == '\n') ++counter;
    if (ch == EOF){
      ++counter;
      break;
    }
  }
  
  printf("Number of lines: %d\n", counter);
  fclose(in_file);
  return 0;
}
