#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct double_list {
  int data;
  struct double_list* next_ptr;
  struct double_list* pre_ptr;
};

struct double_list ls;




int main (void) {

  ls.first_ptr = NULL;
  ls.size = 0;
  
  enter(&ls.first_ptr, 3);
  ++ls.size;

  enter(&ls.first_ptr, 1);
  ++ls.size;

  enter(&ls.first_ptr, 6);
  ++ls.size;

  enter(&ls.first_ptr, 4);
  ++ls.size;

  enter(&ls.first_ptr, 10);
  ++ls.size;

  struct item* current_ptr = NULL;
  current_ptr = ls.first_ptr;

  while (current_ptr != NULL)
  {
    printf("%d\n", current_ptr->value);
    current_ptr = current_ptr->next_ptr;
  }
  
  

  return 0;
}