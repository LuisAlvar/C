#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


int count(char array[], int size)
{
  int hashcode = 0;
  for (int i = 0; i < size; i++)
  {
    hashcode += array[i];
  }
  return hashcode;
}

int main() 
{
  char arry[] = {'1','a','z', '9','z'};
  int arry_size = sizeof(arry) / sizeof(char);

  printf("array size: %d\n", arry_size);
  int result = count(arry, arry_size);

  printf("Primitive hash code: %d\n", result);

  return 0;
}
