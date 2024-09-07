// gcc .\Exercise5_6.c -o .\bin\Exercise5_6.exe
#include <stdio.h>
#include <math.h>

char line[100];
int minutes;

int main () {

  printf("Enter number of minutes: ");
  fgets(line, sizeof(line), stdin);
  sscanf_s(line, "%d", &minutes);

  int f_hours = minutes/60; 
  int f_min = minutes - (f_hours * 60);

  printf("Total %d hours %d minutes", f_hours, f_min);

  return 0;
}