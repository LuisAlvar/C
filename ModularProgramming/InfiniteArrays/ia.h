/*********************************************************************
 * Defintions for the infinite array (ia) package.
 * 
 * An infinite array is an array whose size can grow as needed. Adding
 * more elements to the array will just cause it to grow.
 * -------------------------------------------------------------------
 * struct infinite_array
 *       Used to hold the information for an infinite array.
 * -------------------------------------------------------------------
 * Routines
 *      
 *      ia_init   -- Initializes the array
 *      ia_store  -- Stores an element in the array
 *      ia_get    -- Gets an element from the array
 *********************************************************************/

/* number of elements to store in each cell of the infinite array */
#define BLOCK_SIZE 10

/// @brief used to hold the information for an infinite array
struct infinite_array {
  /* the data for this block */
  int data[BLOCK_SIZE];

  /* pointer to the next array */
  struct infinite_array* next;
};

/// @brief Initialzies the infinite array
/// @param array_ptr the array to initialize
#define ia_init(array_ptr) { (array_ptr)->next = NULL; }

/// @brief Gets an element from an infinite array
/// @param array_ptr pointer to the array to use
/// @param index index into the array
/// @return the value of the element
/// @note You can get an element that has not previously been stored. The value of any uninitialized element is zero.
extern int ia_get(struct infinite_array* array_ptr, int index);

/// @brief Store an element in an infinite array
/// @param array_ptr pointer to the array to use
/// @param index index into the array
/// @param store_data data to store
extern void ia_store(struct infinite_array* array_ptr, int index, int store_data);