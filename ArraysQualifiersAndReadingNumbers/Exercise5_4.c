// gcc .\Exercise5_4.c -o .\bin\Exercise5_4.exe
#include <stdio.h>
#include <math.h>
#define CONVERSION 0.6213712

char line[100];
float kilometer;

int main () {

  printf("Enter kilometers per hour: ");
  fgets(line, sizeof(line), stdin);
  sscanf_s(line, "%f", &kilometer);

  float result = kilometer * CONVERSION;

  printf("Miles per hour: %f", result);

  return 0;
}