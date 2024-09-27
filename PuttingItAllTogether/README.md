# C Statistics Gathering Program
## Preliminary Specification 
>[!WARNING]
>This document is a preliminary specification. Any resemblance to any software living or dead is purely coincidental. 

The program stat gathers statics about C source files and prints them. The command line is:
```bash
  stat <files..>
```
Where <files..> is a list of source files. The following shows the output of the program on a short test file. 
```bash
[File: stat/stat.out]

```

## Code Design 
First, we have a token scanner, which reads raw C code and turns it into tokens. This subdivides into three smaller modules. 
- The first reads the input file
- The second determiens what type of character we ahve
- Lastly, assembles this information into a token

A token is a group of characters that form a single word, number, or symbol.

The main module consumes tokens and output statistics. Again, this module breaks down into smaller submodules: a do_file procedure to manage each file and a submodule for each statistic. 

---
### Token Module
Our program scans C source code and uses the tokens to genereate statistics. For example, the line:
```C
anwser = (123 + 456) / 89; /* Compute some sort of result */
```
consists of the tokens:

Tokens     |Descriptions|
-----------|------------|
T_ID       | The word "answer"
T_OPERATOR | The character "="
T_L_PAREN  | Left parenthesis
T_NUMBER   | The number 123
T_OPERATOR | The character "+"
T_NUMBER   | The number 456
T_R_PAREN  | The right parenthesis
T_OPERATOR | The divide operator
T_NUMBER   | The number 89
T_OPERATOR | The semicolon
T_COMMENT  | The comment 
T_NEW_LINE | The end-of-line character

We can easily distinguish between * character as an operator token, and the "a" character as the start of an identifer. However, some characters are ambiguous. Like, the / character, it could be the divide operator, or it could be the start of a /* comment. In order to identify this character, we need to look ahead one character. 

So one of the requirements for our input module is that it allow us to peek ahead one character. 
(current character, currect character + 1)

The token module builds tokens from groups of characters. For example, an identifier is defined as a letter or underscore, followed by any number of letters or digits. So our tokenizer needs to contain the pseudo code:
```pseudo
if the current character is a letter, then 
  scan until we get a character that's not a letter or digit
```
Our tokenizer depends a great deal on character types, so we need a module to help us with the type information.

---
### Input Module
We need two things on this module:
1. The need to provde the current and next character to the token module
2. Needs to buffer the entire line for display at a later time 

Sometimes a software design will undergo several revisions before it is finally coded, as was the case with the input module. 

The first design consists of a public structure:
```c
struct input_file {
  FILE* file;           /* File we are reading */
  char line[LINE_MAX];  /* Current line from File */
  char* char_ptr;       /* Current character on line*/

  int cur_char;         /* Current character (can be EOF) */
  int next_char;        /* Next character (can be EOF)*/
}
```
---
<div>
<h4 style="text-align: center">What's a good module design?</h4>
A good module design:
<ul>
  <li>The amount of infomation needed by the people who use the module should be minimized.</li>
  <li>The number rules that the users of the module must follow in order to use the module properly should be small.</li>
  <li>The module should be easily expandable.</li>
</ul>
</div>
<hr/>

The final design on this module will contain the following functions:
```c
extern int in_open(const char name[]);
extern void in_close(void);
extern void in_read_char(void);
extern void in_cur_char(void);
extern void in_next_char(void);
extern void in_flush(void);
```
Within this final design, these fucntions hide all the bookkeeping necessary to handle the input file.
The caller does nto need to know about the structure of the input file. 

Few drawbacks:
* A lot more functions
* Module only allows one file open at a time

The one-file restriction limits our flexibility. 
However, we dont need to open multiple files, so we dont need this feature at this time. 
In this case, we decided that the gain of simplifying the interface was well worth the decrease in flexibility. 

---
### Character Type Module 
The purpose of the character type module is to read characters and decode their types. Some types overlap.
For example, the C_ALPHA_NUMBERIC incldues the C_NUMERIC character set.

This module stores most of the type information in an array, and requires only a little logic to handle the special types like C_ALPHA_NUMBERIC.

The functions in this module are:
```c
extern int is_char_type(int ch, enum CHAR_TYPE kind);
extern enum CHAR_TYPE get_char_type(int ch);
```

##### How do we initialize the character array?
We could require the user to initialize it before he calls any of the functions.
Another solution is to put a check at the beginning of each function to initialize the array if needed.
- The second method requires a little more code. But it has several advantages.
  - It makes life simpler for the user. Mistakes are harder to make. If the user doesnt have to do the initializaiton, user can't forget to do it. 
  - This mehtod hides an internal bookkeeping matter inside the character type module so that the user doesnt have to worry about it.
---

### Statistics Submodules
Some statistics are reported on a line-by-line basis, such as the current parentheses nesting. Others are reported at the end-of-file, such as the maximum nesting of parentheses.

We collect four statistics
* a count of the number of lines
* the parentheses () nesting 
* the curly-brace {} nesting
* a count of the lines with comments versus the lines without comments.

|Function|Description|
|--------|-----------|
|xx_init |Initializes the statistic. This function is called at the beginning of each file.|
|xx_take_token|Receives a token and updates the statistic based on it.|
|xx_line_start|Writes out the value of the statistic that's output at the beginning of each line.<br/>In some cases, this may be nothing|
|xx_eof|Writes out the statistical information that goes at the end of the file.|

The xx part of the identifier is the submodule identifier. It is:
* lc - line counter submodule
* pc - parentheses counter submodule
* bc - brace coutner submodule
* cc - comment / not-comment line counter submodule

## Functional Description
This section describes all moduels and major functions in our program. For a more complete and detialed description, take a look at the end. 

### ch_type Module
The ch_type module computes the type of a character. For the most part, this computation is done through a table named type_info. Some types like C_ALPHA_NUMBERIC, for example, include two different types of characters, C_ALPHA and C_DIGIT.
So, in addition to our table, we need a little code for the special cases.

### token Module 
We want an input stream of tokens. We have to start with an input stream consisting of characters. The main function of this class, next_token, turns characters into tokens. The coding for this function is fairly straightforward, except for the fact that it breaks up multimline comments into a series fo T_COMMENT and T_NEW_LINE tokens.

### Line Counter Submodule (lc)
The simplest statistic we collect is a count of the number of lines processed so far. This concept is done through the line_counter submodule. Only token it cares about is T_NEW_LINE.

### Brace counter submodule (dc)
This submodule keeps track of the nesting level of the curly braces {}. We feed the submodule a stream of tokens through the bc_take_token function. This funciton keeps track of the left and right curly braces and ignores everything else:

```c
void bc_take_token(enum TOKEN_TYPE token) {
  switch(token) {
    case T_L_CURLY:
      ++bc_cur_level;
      if(bc_curl_level > bc_max_level) bc_max_level = bc_curl_level;
      break;
    case T_R_CURLY:
      --bc_cur_leve;
      break;
    default:
      break
  }
}
```
This results of this statistic are printed in two places. This first is at the beginning of each line. The second is at the end-of-file. We define two functions to print these statistics:
```c
static void bc_line_start(void) {
  printf("{%-2d",bc_cur_level);
}
static void bc_eof(void) {
  printf("Maximum nesting of {}: %d\n", bc_max_level);
}
```
### Parentheses Counter Submodule (pc)
This submodule is very similar to the brace counter submodule. 

### Comment Counter Submodule (cc)
In these functions, we keep track of lines with comments in them, lines with code in them, lines with both, and lines with none. The results ar printed at the end of file.

### do_file procedure 
The do_file procedure reads each file one token at a time, adn sends each token to the take_token routine for every statistic class:
```c
while(1) {
  cur_token = next_token();
  lc_take_token(cur_token)
  pc_take_token(cur_token)
  bc_take_token(cur_token)
  cc_take_token(cur_token);
}
```

## Testing
File file
```c
/* This is a single line comment */
/*
* This is a multiline 
* comment
*/

int main() {
  /* A procedure */
  int i;          /* Comment / Code line */
  char foo[10];

  strcpy(foo, "abc");   /* String */
  strcpy(foo, "a\"bc"); /* String with special character */

  foo[0] = 'a';
  foo[1] = '\'';
  
  i = 3 / 2;
  i = 3;
  i = 0x123ABC;
  i = ((1+2) *
        (3+4));
  {
    int j;
  }

  return (0);
}
```

## Reference
Oualline, Steve. Practioncal C Programming. 3rd Edition. August 1997.