#include <stdio.h>
#include <stdlib.h>

#define CA_SALES_TAX .08

char line[100];


int main() {

  double sub_total = 0.0;
  double total = 0;

  printf("Enter a sub_total: ");
  fgets(line, sizeof(line), stdin);
  sscanf(line, "%f", &sub_total);

  total =  sub_total + (sub_total * CA_SALES_TAX);

  printf("Your total is %.2f", total);

  return 0;
}
