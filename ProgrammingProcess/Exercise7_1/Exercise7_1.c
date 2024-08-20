#include <stdio.h>
#include <stdbool.h>
#include <string.h>

char line[100];

struct Metric {
  double conversion;
  char unit[10];
};
enum LengthUnits {
  in, 
  yd, 
  ft, 
  mile
};
static const char *ImperialUnitsOfLength[] = { "in", "yd", "ft", "mile" };
static const double MetricConversionOfLength[] = { 1/39.3700787, 1/1.094, 1/3.28084, 1609.34};

static const char *MeterUnitsScaleChart[] = { "Km","cm", "mm"};
static const double MeterScale[] = { 1/1e3, 1e-2, 1e-3 };

struct Metric Map(char imperial_unit[10]);

int main() {

  double value;
  char unit[10];
  double result = 0;
  double conversion = 0.0;
  
  while(1){

    printf("Enter an imperial value along with its unit: ");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%lf %s", &value, unit);

    if(value == -1) break;

    struct Metric equalivance;
    equalivance = Map(unit);
    result = value * equalivance.conversion;
    printf("Metric unit: %lf %s\n", result,  equalivance.unit);
  }

}

bool isImperialUnitOfLength(char unit[10]) {
  bool result = false;
  for (int i = 0; i < 4; i++)
  {
    if(!strcmp(ImperialUnitsOfLength[i], unit)) {
      result = true;
    }
  }
  return result;
}

float getProperUnitOfLengthConversion(char unit[10]) {
  for (int i = 0; i < 4; i++)
  {
    if(!strcmp(ImperialUnitsOfLength[i], unit)) {
      return MetricConversionOfLength[i];
    }
  }
}

struct Metric Map(char imperial_unit[10]) {
  struct Metric result;
  result.conversion = 0.0;
  
  // printf("mapping this unit: %s\n", imperial_unit);
  
  if(isImperialUnitOfLength(imperial_unit))
  {
    // meters is the standard unit of length 
    strcpy(result.unit, "m");
    result.conversion = getProperUnitOfLengthConversion(imperial_unit);
    // printf("mapping to conversion: %lf\n", result.conversion);
  }

  return result;
}
