#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 1

char *FirstChar(char *str, int size) {
  char* ptr = str;
  int counter = 0;
  while (counter < size && ptr != NULL)
  {
    if (*ptr != ' ') return ptr;
    ++ptr;
    ++counter;
  }
  return ptr;
}

int main(void) {

  char array[30] = "I took my cat for a walk";
  char*result = FirstChar(array, 30);
  printf("%-10p\n", result);
  printf("char: %c\n", *result);
  return 0;
}
