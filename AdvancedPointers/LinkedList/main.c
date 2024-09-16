#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct linked_list {
  char data[30];
  struct linked_list* next_ptr;
};

struct linked_list *first_ptr = NULL;

/// @brief Add a new node to the list
/// @param item data you wish to storage on a node for a linked list
void add_list(char* item) {
  /* pointer to the next item in the list */
  struct linked_list* new_item_ptr;
  
  // allocate and set the data - on this node
  new_item_ptr = malloc(sizeof(struct linked_list));
  strcpy((*new_item_ptr).data, item); 

  // Set the new node next_ptr to the front of the list. 
  (*new_item_ptr).next_ptr = first_ptr;
  
  // Now the first_ptr is the new one
  first_ptr = new_item_ptr;
}

bool find(char* name) {
  /* current strucutre we are looking at */
  struct linked_list* current_ptr;
  current_ptr = first_ptr;

  if (current_ptr == NULL) return false;
  
  while ( (current_ptr != NULL) && (strcmp(current_ptr->data, name) != 0) )
  {
    current_ptr = current_ptr->next_ptr;
  }
  return (current_ptr != NULL);
}

int main (void) {


  add_list("3");
  add_list("8");
  add_list("1");
  add_list("6");
  
  bool found = false;
  found = find("3");

  printf("Does list contain value: %d\n", found);

  return 0;
}