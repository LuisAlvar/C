#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


int count(int number, int array[], int size)
{
  // Base case: If the arry is empty, return -
  if (size == 0) return 0;

  int cur_element = array[0];
  printf("current element: %d\n", cur_element);
  int count_the_rest = count(number, array + 1, size - 1);
  
  // if the current element matches, add 1 to the count
  if (cur_element == number)
  {
    return 1 + count_the_rest;
  } else {
    return count_the_rest;
  }
  
}

int main() 
{
  int arry[] = {5,3,2,5,12,62,1,3,5,3,6,2,5,9,5};
  int arry_size = sizeof(arry) / sizeof(int);
  int target_num = 5;

  printf("array size: %d\n", arry_size);
  int result = count(target_num, arry, arry_size);
  printf("Number of occurrences of %d in the array: %d\n", target_num, result);

  return 0;
}
