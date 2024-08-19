// gcc .\Exercise6_4.c -o .\bin\Exercise6_4.exe
#include <stdio.h>
#include <math.h>
#include <string.h>

char line[100];
float amount;

struct Currency {
  char name[10];
  float value;
};

int main() {

  struct Currency american[4];

  strcpy_s(american[0].name, sizeof(american[0].name), "quarter");
  american[0].value = 0.25;
  strcpy_s(american[1].name, sizeof(american[1].name), "dime");
  american[1].value = 0.10;
  strcpy_s(american[2].name, sizeof(american[2].name), "nickel");
  american[2].value = 0.05;
  strcpy_s(american[3].name, sizeof(american[3].name), "penny");
  american[3].value = 0.01;

  // Print to verify
  printf("Enter a dollar amount (less than $1.00): ");
  fgets(line, sizeof(line), stdin);
  sscanf_s(line, "%f", &amount);

  for (int i = 0; i < 4; ++i)
  {
    if (amount >= american[i].value) {
      int multiple = amount / american[i].value;
      amount -= american[i].value * multiple;
      printf("%d %s\n", multiple, american[i].name);
    }
  }

  return 0;
}
