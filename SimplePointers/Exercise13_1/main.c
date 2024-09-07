#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 1

void array_reset(int *arry_ptr, int size){
  int *p = arry_ptr;
  int counter = 0;
  while (counter < size && p != NULL)
  {
    *p = 0;
    ++p;
    ++counter;
  }
}

int main(void) {

  int array[10] = {1,54,32,6,7,2,8,4,7,5};
  printf("before\n");
  for (size_t i = 0; i < 10; i++)
  {
    printf("%d ", array[i]);
  }
  printf("\n");
  array_reset(array,10);
  printf("after reset\n");
  for (size_t i = 0; i < 10; i++)
  {
    printf("%d ", array[i]);
  }
  printf("\n");

  return 0;
}
