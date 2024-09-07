#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

const char* FILE_NAME = "dummy_testfile.txt";
const char* COPY_TO_FILE_NAME = "result_";

int main(void) {

  FILE *in_file;
  FILE *out_fileA;
  FILE *out_fileB;

  char ch;
  int counter = 0;

  time_t current_time;
  time(&current_time);
  struct tm* local_time_info = localtime(&current_time);
  char datetime[40];
  strftime(datetime, sizeof(datetime), "%Y%m%d%H%M%S", local_time_info);
  char final_output_filenameA[100] = "";
  char final_output_filenameB[100] = "";

  strcat(final_output_filenameA, COPY_TO_FILE_NAME);
  strcat(final_output_filenameA, datetime);
  strcat(final_output_filenameA, ".txt");

  local_time_info = localtime(&current_time);
  strftime(datetime, sizeof(datetime), "%Y%m%d%H%M%S2", local_time_info);

  strcat(final_output_filenameB, COPY_TO_FILE_NAME);
  strcat(final_output_filenameB, datetime);
  strcat(final_output_filenameB, ".txt");

  in_file = fopen(FILE_NAME, "r");
  out_fileA = fopen(final_output_filenameA, "w");
  out_fileB = fopen(final_output_filenameB, "w");

  if (in_file == NULL)
  {
    printf("Cannot open %s\n", FILE_NAME);
    exit(8);
  }

  if (out_fileA == NULL)
  {
    printf("Error creating file for %s\n", final_output_filenameA);
    exit(9);
  }

  if (out_fileB == NULL)
  {
    printf("Error creating file for %s\n", final_output_filenameB);
    exit(10);
  }
  
  double num = 0;
  char str[100] = "";
  char num_in_str[10] = "";

  while (1) {
    ch = fgetc(in_file);
    if (ch != EOF && ch != '\n')
    {
      strcat(num_in_str, &ch);
    }
    if (ch != EOF && ch == '\n')
    {
      num = atoi(num_in_str) / 3.0;
      sprintf(str, "%f", num);
      strcat(str,"\n");
      fprintf(out_fileA, str);

      num = 10000  - atoi(num_in_str) ;
      sprintf(str, "%f", num);
      strcat(str,"\n");
      fprintf(out_fileB, str);
      strcpy(num_in_str, "");
    }
 
    if (ch == EOF) break;
  }
  
  fclose(in_file);
  fclose(out_fileA);
  fclose(out_fileB);

  return 0;
}
