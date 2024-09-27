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