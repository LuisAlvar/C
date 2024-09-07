#include <stdio.h>
#include <time.h>
#include <string.h>

#include <sys/stat.h>

#include <stdlib.h>
#include <stdbool.h>

const char* FILE_NAME = "dummy_testfile.txt";
const char* COPY_TO_FILE_NAME = "result_";

long int get_file_size(const char* filename) {
  struct stat st;
  if (stat(filename, &st) == 0)
  {
    return st.st_size;
  }
  return -1;
}

int main(void) {

  FILE *in_file;
  FILE *out_file;
  char ch;
  int counter = 0;

  time_t current_time;
  time(&current_time);
  struct tm* local_time_info = localtime(&current_time);
  char datetime[40];
  strftime(datetime, sizeof(datetime), "%Y%m%d%H%M%S", local_time_info);
  char final_output_filename[100] = "";

  strcat(final_output_filename, COPY_TO_FILE_NAME);
  strcat(final_output_filename, datetime);
  strcat(final_output_filename, ".txt");

  in_file = fopen(FILE_NAME, "r");
  out_file = fopen(final_output_filename, "w");

  if (in_file == NULL)
  {
    printf("Cannot open %s\n", FILE_NAME);
    exit(8);
  }

  if (out_file == NULL)
  {
    printf("Error creating file for %s\n", final_output_filename);
    exit(9);
  }
  
  while (1)
  {
    ch = fgetc(in_file);
    if (ch == EOF) break;
    if (ch != '\t')
    {
      fputc(ch, out_file);
    }
    else
    {
      fputc(' ', out_file);
      fputc(' ', out_file);
    }
  }
  
  fclose(in_file);
  fclose(out_file);

  return 0;
}
