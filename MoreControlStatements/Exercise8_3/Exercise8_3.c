#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char line[100];
double number = 0;
double total = 0.0;
double sum = 0.0;
int counter = 0;

int main() {
  printf("Exit the program with -1\n");

  while (1)
  {
    printf("Enter a number to add to the average: ");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%lf", &number);
    if(number == -1) break;

    sum += number;
    ++counter;
  }
  
  total =  sum / counter;
  printf("The average of the %d-number provided is %.2lf\n", counter, total);
  return 0;
}
