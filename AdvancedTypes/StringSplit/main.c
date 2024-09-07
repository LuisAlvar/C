#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define MAX_ENTRIES 1

char *my_strchr(char* string_ptr, char find)
{
  while (*string_ptr != find)
  {
    if (*string_ptr == '\0') return NULL;
    ++string_ptr;
  }
  return string_ptr;
}

int main(void) {
  char line[80];
  char *first_ptr;
  char *last_ptr;

  fgets(line, sizeof(line), stdin);

  /* Get rid of trailing newline */
  line[strlen(line)-1] = '\0';

  last_ptr = line; // set the last pointer to the beginning of the line input array

  first_ptr = my_strchr(line, '/');

  /* Check for an error */
  if (first_ptr == NULL)
  {
    fprintf(stderr, "Error: Unable to find slash in %s\n", line);
    exit(8);
  }

  // zero out the slash
  *first_ptr = '\0';

  // move to first character of name
  ++first_ptr;

  printf("First: %s Last: %s\n", first_ptr, last_ptr);
  return 0;
}
