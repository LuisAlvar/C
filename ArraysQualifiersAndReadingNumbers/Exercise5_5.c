// gcc .\Exercise5_5.c -o .\bin\Exercise5_5.exe
#include <stdio.h>
#include <math.h>

char line[100];
int hours;
int minutes;

int main () {

  printf("Enter hours and minutes: ");
  fgets(line, sizeof(line), stdin);
  sscanf_s(line, "%d %d", &hours, &minutes);

  int result = hours * (60) + minutes;

  printf("Total number of minutes: %d", result);

  return 0;
}