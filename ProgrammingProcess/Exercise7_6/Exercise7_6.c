#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {

  char line[100];
  int num;
  int positive_counter = 0;
  int negative_counter = 0;

  while(1) {

    printf("Enter a integer number: ");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d", &num);

    if (num < 0)
    {
      ++negative_counter;
    }
    else if (num > 0) {
      ++positive_counter;
    }

    printf("Postive Counter(%d) | Negative Counter(%d)\n", positive_counter, negative_counter);
  }

  return 0;
}
