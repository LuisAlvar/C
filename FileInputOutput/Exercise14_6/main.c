#include <stdio.h>
#include <stdlib.h>
#include <cjson/cJSON.h>
#include <string.h>

//sudo apt-get install libcjson-dev
//add -lcjson on the final compile command

char* program_name;

struct UserData {
  char Name[50];
  char Address[100];
};

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
  cJSON* last_name  = cJSON_GetObjectItemCaseSensitive(json, "last_name");
  cJSON* address  = cJSON_GetObjectItemCaseSensitive(json, "address");
  cJSON* city  = cJSON_GetObjectItemCaseSensitive(json, "city");
  cJSON* state  = cJSON_GetObjectItemCaseSensitive(json, "state");
  cJSON* zip  = cJSON_GetObjectItemCaseSensitive(json, "zip");

  // Map data from json to object type UserData
  struct UserData ud;

  strcpy(ud.Name, "");
  strcat(ud.Name, first_name->valuestring);
  strcat(ud.Name, " ");
  strcat(ud.Name, last_name->valuestring);

  strcpy(ud.Address, "");
  strcat(ud.Address, address->valuestring);
  strcat(ud.Address, " ");
  strcat(ud.Address, city->valuestring);
  strcat(ud.Address, ", ");
  strcat(ud.Address, state->valuestring);
  strcat(ud.Address, " ");
  strcat(ud.Address, zip->valuestring);
  
  printf("Name: %s\n", ud.Name);
  printf("Location: %s\n", ud.Address);

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
