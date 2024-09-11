#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

char *program_name = NULL;
bool is_binary_conversion = false;
bool is_ascii_conversion = false;
char *file_name = NULL;
char *result_filename = "result.txt";

void usage(void) {
  fprintf(stderr, "Usage is %s [options] [file]\n", program_name);
  fprintf(stderr, "Options:\n");
  fprintf(stderr, "\t-b\tConvert [file] to a binary file\n");
  fprintf(stderr, "\t-a\tConvert [file] to a ascii file\n");
  exit(8);
}

void charToBinary(unsigned char c, char* binary) {
  for (int i = 7; i >= 0; i--) {
    binary[i] = (c & 1) ? '1' : '0';
    c >>= 1;
  }
  binary[8] = ' '; // Separate with a space
}

char octetToChar(const char* octet) {
  int decimal = 0;
  for (int i = 0; i < 8; ++i) {
    printf("%c", octet[i]);
    decimal <<= 1; // Shift left
    decimal |= (octet[i] - '0'); // Add the bit
  }
  printf("\n%c\n", (char)decimal);
  return (char)decimal;
}

void ConvertFileToBinary(char* file){

  FILE *read_file = fopen(file, "r");
  if (read_file == NULL)
  {
    fprintf(stderr, "Error with opening given file %s", file);
    exit(11);
  }
  
  FILE* binary_file = fopen(result_filename, "wb");
  if (binary_file == NULL)
  {
    fprintf(stderr, "Error creating binary file");
    fclose(read_file);
    exit(11);
  }

  char buffer[3];
  while(fgets(buffer, sizeof(buffer), read_file)){
    int length = strlen(buffer);
    for (int i = 0; i < length; i++)
    {
      char binary[9]; //8 bits plus a space
      charToBinary(buffer[i], binary);
      fputs(binary, binary_file);
    }
  }
  
  fclose(read_file);
  fclose(binary_file);
}


void ConvertFileToText(char* file)
{
  FILE *read_file = fopen(file, "r");
  if (read_file == NULL)
  {
    fprintf(stderr, "Error with opening given file %s", file);
    exit(11);
  }
  
  FILE* text_file = fopen(result_filename, "w");
  if (text_file == NULL)
  {
    fprintf(stderr, "Error creating text file");
    fclose(read_file);
    exit(11);
  }

  char *buffer;
  buffer = (char*)malloc(8 * sizeof(char));

  char ch;
  int index = 0;

  while(1){
    ch = fgetc(read_file);
    if (ch == EOF) break;
    if (ch != EOF && ch != ' ') {
      buffer[index++] = ch;
    }
    if (index == 8)
    {
      char text = octetToChar(buffer);
      fputc(text, text_file);
      free(buffer);
      buffer = (char*)malloc(8 * sizeof(char));
      printf("\t%d\n",index);
      index = 0;
    }
  }
  free(buffer);
  fclose(read_file);
  fclose(text_file);
}

int main(int argc, char *argv[]) {

  program_name = argv[0];

  while ((argc > 1) && (argv[1][0] == '-'))
  {
    switch (argv[1][1])
    {
      case 'b':
        ConvertFileToBinary(&argv[1][3]);
        break;
      case 'a':
        ConvertFileToText(&argv[1][3]);
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
