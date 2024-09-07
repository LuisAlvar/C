#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


int Max(int array[], int size)
{
  int result = 0;
  for (int i = 0; i < size; i++)
  {
    if (result < array[i]) result = array[i]; 
  }
  return result;
}

int main() 
{
  int arry[] = {4,25,24,14,6,8,10,14,33,29};
  int arry_size = sizeof(arry) / sizeof(int);

  printf("array size: %d\n", arry_size);
  int result = Max(arry, arry_size);

  printf("Max value in array: %d\n", result);

  return 0;
}
