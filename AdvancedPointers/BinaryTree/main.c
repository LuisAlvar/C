/************************************************************************
* 
* 
*
*
*
* 
************************************************************************/
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

struct node {
  char *word;         /* word for this node */
  struct node* left;  /* node to the left   */
  struct node* right; /* node to the right  */
};

// the tope of the tree
struct node* root = NULL;

/// @brief Writes error and dies
void memory_error() 
{
  fprintf(stderr, "Error: Out of memory\n");
  exit(8);
}

/// @brief saves a string on the heap
/// @param string string to save
/// @return pointer to malloc-ed section of memory with the string copied into it.
char* save_string(char* string)
{
  char* new_string;
  new_string = malloc((unsigned)(strlen(string) + 1));
  if (new_string == NULL) memory_error();
  strcpy(new_string, string);
  return new_string;
}

/// @brief enter a word into the tree
/// @param node current node we are looking at
/// @param word word to enter
void enter(struct node** node, char* word)
{
  int result;

  if ((*node) == NULL)
  {
    /* Allocate memory for a new node */
    (*node) = malloc(sizeof(struct node));
    (*node)->left = NULL;
    (*node)->right = NULL;
    (*node)->word = save_string(word);
    return;
  }
  
  /* Check to see where the word goes */
  result = strcmp((*node)->word, word);

  /* The current node already contians the word, no entry necessary */
  if (result == 0) return;

  /* The word must be entered in the left or right subtree */
  if (result < 0)
  {
    enter(&(*node)->right, word);
  }
  else
  {
    enter(&(*node)->left, word);
  }  
}

void print_tree(struct node* top)
{
  if (top == NULL) return;
  print_tree(top->left);
  printf("%s\n", top->word);
  print_tree(top->right);
}

int main (void) {

  enter(&root, "lemon");
  enter(&root, "apple");
  enter(&root, "pear");
  enter(&root, "orange");
  print_tree(root);

  return 0;
}