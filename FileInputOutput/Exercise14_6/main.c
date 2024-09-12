#include <stdio.h>
#include <stdlib.h>
#include "./cJSON.h"

char* program_name;

void usage(void) {
  fprintf(stderr, "Usage is %s [options] [file]\n", program_name);
  fprintf(stderr, "Options:\n");
  fprintf(stderr, "\t-r\tread the given json file\n");
  exit(8);
}

void ReadJsonFile(char* file) {
  FILE* input_file = fopen(file, "r");
  
  if(input_file == NULL) {
    fprintf(stderr, "Error: unable to open the file (%s).\n", file);
    exit(12);
  }

  char buffer[1024];
  int len = fread(buffer, 1, sizeof(buffer), input_file);
  fclose(input_file);

  cJSON* json = cJSON_Parse(buffer);
  if (json == NULL) {
    const char* error_ptr = cJSON_GetErrorPtr();
    fprintf(stderr, "Error: while parsing JSON file: (%s)\n", error_ptr);
    exit(14);
  }

  // Access specific values from the JSON object
  cJSON* first_name  = cJSON_GetObjectItemCaseSensitive(json, "first_name");

  printf("First name: %s\n", first_name->valuestring);

  cJSON_Delete(json);
}


int main(int argc, char *argv[]) {

  program_name = argv[0];

  while ((argc > 1) && (argv[1][0] == '-'))
  {
    switch (argv[1][1])
    {
      case 'r':
        ReadJsonFile(&argv[1][3]);
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
