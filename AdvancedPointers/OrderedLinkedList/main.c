#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct item {
  int value;
  struct item* next_ptr;
};

struct ordered_linked_list {
  struct item* first_ptr;
  int size;
};

struct ordered_linked_list ls;

void enter(struct item** first_ptr, const int value)
{
  struct item* before_ptr =  NULL;
  struct item* after_ptr = NULL;
  struct item* new_item_ptr =  NULL;
  struct item* current_ptr = NULL;

  // allocate the new node
  new_item_ptr = malloc(sizeof(struct item));
  new_item_ptr->value = value;
  new_item_ptr->next_ptr = NULL;

  if (*first_ptr == NULL)
  {
    *first_ptr =  new_item_ptr;
    return;
  }

  if (*first_ptr != NULL && value < (*first_ptr)->value)
  {
    new_item_ptr->next_ptr = *first_ptr;
    *first_ptr = new_item_ptr;
    return;
  }

  current_ptr = *first_ptr;
  printf("%d\n", current_ptr->value);
  return ;
  while (1)
  {
    if (current_ptr->value >= value) break;
    current_ptr = current_ptr->next_ptr;
  }
  
  new_item_ptr->next_ptr = current_ptr->next_ptr;
  current_ptr->next_ptr = new_item_ptr;
}


int main (void) {

  ls.first_ptr = NULL;
  ls.size = 0;
  
  enter(&ls.first_ptr, 3);
  ++ls.size;

  //printf("%d\n", ls.first_ptr->value);

  enter(&ls.first_ptr, 1);
  ++ls.size;

  enter(&ls.first_ptr, 6);
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