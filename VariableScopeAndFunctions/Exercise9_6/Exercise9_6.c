#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


void Replace(char *array, char find, char replace)
{
  for (int i = 0; i < strlen(array); i++)
  {
    if (array[i] == find) array[i] = replace; 
  }
}

int main() 
{
  char arry[] = "I took my cat for a walk around the-block.";
  int arry_size = sizeof(arry) / sizeof(char);

  printf("array size: %d\n", arry_size);
  printf("Original array: %s\n", arry);
  Replace(arry, '-', ' ');
  printf("Updated array: %s\n", arry);

  return 0;
}
