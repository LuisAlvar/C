/***************************************************************
 * token -- token handling module
 * 
 * Functions:
 *  next_token -- gets the next token from the input 
 ***************************************************************/

/// @brief Define the enumerated list of tokens
enum TOKEN_TYPE 
{
  T_NUMBER,
  T_STRING,
  T_COMMENT,
  T_NEWLINE,
  T_OPERATOR,
  T_L_PAREN,
  T_R_PAREN,
  T_L_CURLY,
  T_R_CURLY,
  T_ID,
  T_EOF
};

/*
 * We use #define here instead of "const int" because so many old software 
 * packages use #define. We must have picked up a header file that uses #define
 * for TRUE/FALSE. Consequently, we protect against double defines as well as against 
 * using #define ourselves.
 */
#ifndef TRUE
#define TRUE 1    /* Define a simple TRUE/FALSE values */
#define FALSE 0
#endif /* TRUE */

/// @brief Reads the next token in an input stream.
/// @return Next token
extern enum TOKEN_TYPE next_token(void);