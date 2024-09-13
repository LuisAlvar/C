#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

// https://www.eso.org/~ndelmott/ascii.html

char* program_name;
const char* const output_result_file = "result.txt";

void usage(void) {
  fprintf(stderr, "Usage is %s [options] [file]\n", program_name);
  fprintf(stderr, "Options:\n");
  fprintf(stderr, "\t-r\tremoves all characters with the high bit set\n");
  exit(8);
}

void RemoveCharacterCreateFile(char* file) {
  FILE* input_file = fopen(file, "r");
  if (input_file == NULL)
  {
    fprintf(stderr, "Unable to open given input file %s", file);
    exit(12);
  }

  FILE *output_file = fopen(output_result_file, "w");
  if (output_file == NULL)
  {
    fprintf(stderr, "Unable to create a new file");
    fclose(input_file);
    exit(12);
  }
  
  char ch;

  while (1)
  {
    ch = fgetc(input_file);
    if (ch & 0x80 != 0) fputc(ch, output_file);
    if (ch == EOF) break;
  }
  
  
  fclose(input_file);
  fclose(output_file);
}

int main(int argc, char *argv[]) {

  program_name = argv[0];

  while ((argc > 1) && (argv[1][0] == '-'))
  {
    switch (argv[1][1])
    {
      case 'r':
        RemoveCharacterCreateFile(&argv[1][3]);
        break;
      default:
        fprintf(stderr, "Bad option %s\n", argv[1]);
        usage();
    } 
    ++argv;
    --argc; 
  }

  return 0;
}
