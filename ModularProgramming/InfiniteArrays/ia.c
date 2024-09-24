/*********************************************************************
 * infinite-array -- routines to handle infinite arrays
 * 
 * An infinite array is an array that grows as needed.
 * There is no index too large for an infinite array
 * (unless) we run out of memory.
*********************************************************************/
#include "ia.h"
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

/// @brief (private) Gets the location of an infinite array element. 
/// @param array_ptr (type infinite_array*) pointer to the array to use
/// @param index index into the array
/// @param current_index_ptr pointer to the index into this bucket (returned)
/// @return pointer to the current bucket
static struct infinite_array* ia_locate(struct infinite_array* array_ptr, int index, int* current_index_ptr)
{
  /* pointer to the current bucket */
  struct infinite_array* current_ptr;
  current_ptr = array_ptr;
  *current_index_ptr = index;

  while(BLOCK_SIZE <= *current_index_ptr)
  {
    // if we are at the end of the data structure
    if (current_ptr->next == NULL)
    {
      current_ptr->next = malloc(sizeof(struct infinite_array));
      // if we did not get the allocated memory we required, then
      if (current_ptr->next == NULL)
      {
        fprintf(stderr, "Error: Out of memory\n");
        exit(8);
      }
      // set the allocated memory for the new instance to empty
      memset(current_ptr->next, '\0', sizeof(struct infinite_array));
    }
    
    // as you interate from start of the linked list to the end
    current_ptr = current_ptr->next;
    *current_index_ptr -= BLOCK_SIZE; // your index gets smaller by BLOCK_SIZE 
  }
  return (current_ptr);
}

/// @brief Stores an element into an infinite array.
/// @param array_ptr pointer to the array to use
/// @param index index into the array
/// @param store_data data to store
void ia_store(struct infinite_array* array_ptr, int index, int store_data)
{
  /* pointer to the current bucket */
  struct infinite_array* current_ptr;
  int current_index;

  current_ptr = ia_locate(array_ptr, index, &current_index);
  current_ptr->data[current_index] = store_data; /* each data is limited to 0 to (BLOCK_SIZE-1) */
}

/// @brief Gets an element from an infinite array. 
/// @param array_ptr pointer to the array to use
/// @param index index into the array
/// @return the value of the element
/// @note You can get an element that has not previously been stored.
///       The value of any uninitialized element is zero.
int ia_get(struct infinite_array* array_ptr, int index)
{
  /* pointer to the current bucket */
  struct infinite_array* current_ptr;
  int current_index;
  current_ptr = ia_locate(array_ptr, index, &current_index);
  return (current_ptr->data[current_index]);
}