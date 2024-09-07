#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char line[100];
int resistor = 0;
double total_resistnace = 0.0;
double sum_resistance = 0.0;
int counter = 0;

int main() {

  while (1)
  {
    printf("Enter a value of a resistor (for total enter -1): ");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d", &resistor);
    if(resistor == -1) break;

    sum_resistance += (1.0 / resistor);
    ++counter;
  }
  
  total_resistnace =  1.0/sum_resistance;
  printf("The total resistance of our %d-resistor network is %.2lf ohms\n", counter, total_resistnace);
  return 0;
}
