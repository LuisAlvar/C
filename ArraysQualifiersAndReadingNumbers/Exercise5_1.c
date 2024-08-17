// gcc .\Exercise5_1.c -o .\bin\Exercise5_1.exe
#include <stdio.h>

char line[100];
float value;

int main () {

  printf("Enter a Celsius value: ");
  fgets(line, sizeof(line), stdin);
  sscanf_s(line, "%f", &value);

  float result = (9.0/5.0)*value + 32;

  printf("Fahrenheit value: %.2f", result);
  return 0;
}