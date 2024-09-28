/***************************************************************
 * char_type -- character type module
 * 
 * The purpose of this module is to read chracters and decode
 * their types. 
 * 
 * For the most part, this computation is done through a table
 * named type_info. 
 ***************************************************************/
enum CHAR_TYPE {
  C_EOF,            /* End of file character*/
  C_WHITE,          /* Whitespace or control character */
  C_NEWLINE,        /* A newline character */
  C_ALPHA,          /* A Letter (includes _) */
  C_DIGIT,          /* A number */
  C_OPERATOR,       /* An operator */
  C_SLASH,          /* The character '/' */
  C_L_PAREN,        /* The character '(' */
  C_R_PAREN,        /* The character ')' */
  C_L_CURLY,        /* The character '{' */
  C_R_CURLY,        /* The character '}' */
  C_SINGLE,         /* The character '\'' */
  C_DOUBLE,         /* The character '"' */

  C_HEX_DIGIT,      /* Hexidecimal digit */
  C_ALPHA_NUMBERIC  /* Alpha numeric */
};

/// @brief Determines if a character belongs to a given character type
/// @param ch Character to check
/// @param kind Type to chekc it for
/// @return Return 0 if chracter is not of the specified kind. Otherwise, 1, chracter is of the specified kind. 
extern int is_char_type(int ch, enum CHAR_TYPE kind);

/// @brief Given a character, returns its type
/// @note We return the simple types. Composite types such as C_HEX_DIGIT and C_ALPHA_NUMBERIC are not returned.
/// @param ch Character having the type we want
/// @return character type
extern enum CHAR_TYPE get_char_type(int ch);