#include <stdio.h>
char line[100];

float Map(char imperial_unit[10]);

int main() {

  float value;
  char unit[10];
  float result = 0;
  float conversion = 0.0;

  printf("Result: %f\n", result);

  printf("Enter an imperial value along with its unit: ");
  fgets(line, sizeof(line), stdin);
  sscanf(line, "%f %s", &value, unit);

  conversion = Map(unit);
  
}

float Map(char imperial_unit[10]) {
  float conversion = 0.0;

  printf("mapping this unit: %s\n", imperial_unit);

  return conversion;
}

enum Length {
  in, 
  yd, 
  ft,
  mile
};