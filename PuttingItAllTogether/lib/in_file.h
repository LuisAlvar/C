/***************************************************************
 * input_file -- data from the input file
 * 
 * The current two characters are stored in cur_char and 
 * next_char.
 * 
 * Lines are buffered so that they can be output to the screen
 * after a line is assembled. 
 * 
 * Functions:
 *  in_open       -- opens the input file
 *  in_close      -- closes the input file
 *  read_char     -- reads the next character
 *  in_cur_char   -- returns the current character
 *  in_next_char  -- return the next character
 *  in_flush      -- sends line to the screen
 ***************************************************************/

/// @brief Opens the input file
/// @param name Name of disk file to use for input
/// @return 0, if open succeeded. Otherwise, nonzero, when open failed.
extern int in_open(const char name[]);

/// @brief Closes the input file.
extern void in_close(void);

/// @brief Read the next character from the input file.
extern void in_read_char(void);

/// @brief Gets the current input character.
/// @return Current character
extern int in_cur_char(void);

/// @brief Peeks ahead one character
/// @return Next character
extern int in_next_char(void);

/// @brief Flushes the buffered input line to the screen.
extern void in_flush(void);