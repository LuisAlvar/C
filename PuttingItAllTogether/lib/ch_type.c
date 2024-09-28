/***************************************************************
 * char_type module
 * 
 * This module is used to determine the type of various chracters.
 * 
 * Public functions:
 * init_char_type   -- initializes the table
 * is_char_type     -- is a character of a given type
 * get_char_type    -- given char, return type
 ***************************************************************/
#include <stdio.h>
#include "ch_type.h"

/* Define the type information array */
static enum CHAR_TYPE type_info[256];
static int ch_setup = 0;              /* True if character type info setup */

/// @brief Fills in a range of types for the character type class.
/// @param start Range of items to fill in.
/// @param end Range of items to fill in.
/// @param type Type to use for filling.
static void fill_range(int start, int end, enum CHAR_TYPE type)
{
  int cur_ch; /* Character we are handling now */

  for (cur_ch = start; cur_ch <= end; ++cur_ch)
  {
    type_info[cur_ch] = type;
  }
}

/// @brief Initializes the char type table
static void init_char_type(void)
{
  fill_range(0, 255, C_WHITE);
  fill_range('A', 'Z', C_ALPHA);
  fill_range('a', 'z', C_ALPHA);

  type_info['_'] = C_ALPHA;
  fill_range('0', '9', C_DIGIT);

  type_info['!'] = C_OPERATOR;
  type_info['#'] = C_OPERATOR;
  type_info['$'] = C_OPERATOR;
  type_info['%'] = C_OPERATOR;
  type_info['^'] = C_OPERATOR;
  type_info['&'] = C_OPERATOR;
  type_info['*'] = C_OPERATOR;
  type_info['-'] = C_OPERATOR;
  type_info['+'] = C_OPERATOR;
  type_info['='] = C_OPERATOR;
  type_info['|'] = C_OPERATOR;
  type_info['~'] = C_OPERATOR;
  type_info[','] = C_OPERATOR;
  type_info[':'] = C_OPERATOR;
  type_info['?'] = C_OPERATOR;
  type_info['.'] = C_OPERATOR;
  type_info['<'] = C_OPERATOR;
  type_info['>'] = C_OPERATOR;

  type_info['/'] = C_SLASH;
  type_info['\n'] = C_NEWLINE;

  type_info['('] = C_L_PAREN;
  type_info[')'] = C_R_PAREN;

  type_info['{'] = C_L_CURLY;
  type_info['}'] = C_R_CURLY;

  type_info['"'] = C_DOUBLE;
  type_info['\''] = C_SINGLE;
}

/// @brief Determines if a character belongs to a given character type.
/// @param ch Character to check
/// @param kind to check it for
/// @return Return 0, if character is not of the specified kind. Otherwise, 1, if character is of the specified kind.
int is_char_type(int ch, enum CHAR_TYPE kind)
{
  if (!ch_setup)
  {
    init_char_type();
    ch_setup = 1;
  }
  if (ch == EOF) return (kind == C_EOF);
  switch (kind)
  {
    case C_HEX_DIGIT:
      if (type_info[ch] == C_DIGIT) return 1;
      if ((ch >= 'A') && (ch <= 'F')) return 1;
      if ((ch >= 'a') && (ch <= 'f')) return 1;
      return 0;
    case C_ALPHA_NUMBERIC:
      return ( (type_info[ch] == C_ALPHA) || (type_info[ch] == C_DIGIT) );
    default:
      return (type_info[ch] == kind);
  }
}

/// @brief Given a character, returns its type
/// @note We return the simple types. Composite types such as C_HEX_DIGIT and C_ALPHA_NUMBERIC are not returned.
/// @param ch Character having the type we want
/// @return character type
enum CHAR_TYPE get_char_type(int ch)
{
  if (!ch_setup)
  {
    init_char_type();
    ch_setup = 1;
  }
  if (ch == EOF) return (kind == C_EOF);
  return type_info[ch];
}