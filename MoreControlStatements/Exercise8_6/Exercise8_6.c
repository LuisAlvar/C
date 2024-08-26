#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char line[100];
int number;
char result[200];

void ConvertToWords(int num, char *p);

int main() {

  while (1)
  {
 
    printf("Enter a number to convert to words: ");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d", &number);

    ConvertToWords(number, result);

    printf("%s\n", result);
  }

  return 0;
}


void ConvertToWords(int num, char *p) {
  char char_arry_num[5];
  int arry_size;

  sprintf(char_arry_num, "%d", num);
  arry_size = strlen(char_arry_num);


  strcpy(p, "hello back");
}



