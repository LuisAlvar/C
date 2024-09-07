#include <stdio.h>

int main(void) {

  short int i; /* Loop counter */
  printf("size of short int: %ld bytes | %ld bits\n", sizeof(short int), sizeof(short int) * 8);
  signed char ch; /* Loop counter of another kind */
  printf("size of signed char: %ld bytes | %ld bits\n", sizeof(signed char), sizeof(signed char) * 8);

  int count = 0;
  /* Works */
  // the nature of short int |
  for(i = 0x80; i != 0; i = (i >> 1)) 
  {
    printf("i is %x (%d)\n", i, i);
  }

  /* Fails */
  // when shifting to the right, its adding 1. for negative numbers.  
  // when a right shift is done on this variable, the sign bit is used for fill. 
  // So, 1000|0000 >> 2 is 1100|0000
  // Fix: is to change from signed char to unsigned char.
  for(ch = 0x80; ch != 0; ch = (ch >> 1))
  {
    printf("ch is %x (%d)\n", ch, ch);
    if (++count == 8) break;
  }
  
  return 0;
}