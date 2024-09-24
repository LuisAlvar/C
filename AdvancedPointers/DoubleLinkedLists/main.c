#include <stdio.h>
#include <stdlib.h>

// Not the best implementation. 
// Just to show the pointer logic connections. 
struct double_list {
  int size;
  int data;
  struct double_list* next_ptr;
  struct double_list* previous_ptr;
};

void double_enter(struct double_list *head_ptr, int item) 
{
  struct double_list* insert_ptr;
  struct double_list* new_item;

  // allocation of the new node.  
  new_item = malloc(sizeof(struct double_list));
  new_item->data = item;
  new_item->next_ptr = NULL;
  new_item->previous_ptr = NULL;

  // we assume that the head is already populated, so we move to the next ptr
  insert_ptr = head_ptr;
  while (1)
  {
    if (insert_ptr == NULL) break;
    if (insert_ptr->next_ptr == NULL) break;
    if (item <= insert_ptr->data) break;
    insert_ptr = insert_ptr->next_ptr;
  }
  
  // node insertion: either you append to the list or you split the elements on the list
  if (insert_ptr != NULL 
    && insert_ptr->next_ptr == NULL)
  {
    insert_ptr->next_ptr = new_item;
    new_item->previous_ptr = insert_ptr;
  }
  else {
    new_item->previous_ptr = insert_ptr->previous_ptr;
    insert_ptr->previous_ptr->next_ptr = new_item;
    new_item->next_ptr = insert_ptr;
    insert_ptr->previous_ptr = new_item;
  }

  head_ptr->size += 1;
  return;
}

int main (void) {

  struct double_list list;
  list.size = 1;
  list.data = 2;
  list.next_ptr = NULL;
  list.previous_ptr = NULL;

  double_enter(&list, 4);
  double_enter(&list, 6);
  double_enter(&list, 11);
  double_enter(&list, 34);

  double_enter(&list, 8);
  struct double_list* ptr;
  ptr = &list;
  while (ptr != NULL)
  {
    printf("%d ", ptr->data);
    ptr = ptr->next_ptr;
  }
  printf("\n");

  return 0;
}