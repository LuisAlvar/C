// gcc .\Exercise5_3.c -o .\bin\Exercise5_3.exe
#include <stdio.h>
#include <math.h>

char line[100];
float width;
float height;
float perimeter;

int main () {

  printf("Enter width and height: ");
  fgets(line, sizeof(line), stdin);
  sscanf_s(line, "%f %f", &width, &height);

  float result = 2 * (width + height);

  printf("The perimeter of a rectangle: %.2f", result);

  return 0;
}