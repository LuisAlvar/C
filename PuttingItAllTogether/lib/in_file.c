/***************************************************************
 * in_file module 
 *  Handles opening, reading, and display of data from the input file.
 * 
 * Functions:
 *  in_open       -- opens the input file
 *  in_close      -- closes the input file
 *  read_char     -- reads the next character
 *  in_cur_char   -- returns the current character
 *  in_next_char  -- return the next character
 *  in_flush      -- sends line to the screen
 ***************************************************************/
#include <stdio.h>
#include <errno.h>
#include "in_file.h"

#define LINE_MAX 500; /* Longest possible line */

struct input_file {
  FILE* file;           /* File we are reading */
  char line[LINE_MAX];  /* Current line */
  char* char_ptr;       /* Current character on the line*/

  int cur_char;         /* Current character (can be EOF)*/
  int next_char;        /* Next character (can be EOF)*/
};

/* Input file that we are reading */
static struct input_file in_file = {
  NULL,   /* file */
  "",     /* line */
  NULL,   /* char_ptr */
  '\0',   /* cur_char */
  '\0'    /* next_char */
};

/// @brief Opens the input file
/// @param name Name of disk file to use for input
/// @return 0, if open succeeded. Otherwise, nonzero, when open failed.
int in_open(const char name[]) 
{
  in_file.file = fopen(name, "r");
  if (in_file.file == NULL) return (errno);
  
  // Initialize the input file and read the first two characters.
  in_file.cur_char = fgetc(in_file.file);
  in_file.next_char = fgetc(in_file.file);
  in_file.char_ptr = in_file.line;
  return 0;
}

/// @brief Closes the input file.
void in_close(void) 
{
  if(in_file.file != NULL)
  {
    fclose(in_file.file);
    in_file.file = NULL;
  }
}

/// @brief Gets the current input character.
/// @return Current character
int in_cur_char(void)
{
  return (in_file.cur_char);
}

/// @brief Peeks ahead one character
/// @return Next character
int in_next_char(void)
{
  return (in_file.next_char);
}

/// @brief Flushes the buffered input line to the screen.
void in_flush(void)
{
  *in_file.char_ptr = '\0';
  fputs(in_file.line, stdout);
  in_file.char_ptr = in_file.line;
}

/// @brief Read the next character from the input file.
void in_read_char(void)
{
  *in_file.char_ptr = in_file.cur_char;
  ++in_file.char_ptr;

  in_file.cur_char = in_file.next_char;
  in_file.next_char = fgetc(in_file.file);
}
