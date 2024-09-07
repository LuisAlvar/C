// gcc .\Exercise5_2.c -o .\bin\Exercise5_2.exe
#include <stdio.h>
#include <math.h>

#define PIE M_PI

char line[100];
float radius;

int main () {

  printf("Enter a radius of calculate the volume of a sphere: ");
  fgets(line, sizeof(line), stdin);
  sscanf_s(line, "%f", &radius);

  float result = (4.0/3.0)*PIE*powf(radius, 3.0);

  printf("The volume of a sphere: %.2f", result);

  return 0;
}