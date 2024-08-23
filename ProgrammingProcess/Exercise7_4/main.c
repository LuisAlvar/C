#include <stdio.h>
#include <math.h>

#define CA_SALES_TAX .08

char line[100];


int main() {

  double sub_total = 0.0;
  double total = 0;
  double taxation = 0.0;

  printf("Enter a sub_total: ");
  fgets(line, sizeof(line), stdin);
  sscanf_s(line, "%lf", &sub_total);

  taxation = round((sub_total * CA_SALES_TAX) * 100) / 100.0;
  printf("+ %.2lf sales tax\n", taxation);
  total = round((sub_total + taxation)*100) / 100.0;
  printf("Your total is $%.2lf\n", total);

  return 0;
}

// GNU MPFR library
// Intel Decimal Floating Point Math library 
