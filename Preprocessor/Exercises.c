#include <stdio.h>
#include <ctype.h>

#define is_divideble(x) (x%10==0)
#define is_digit(x) (x-(int)x== 0)

#define is_hex(x) (isxdigit(x) == 0 && is_digit(x))
#define SWAP_INTS(a, b) do { \
    (a) ^= (b); \
    (b) ^= (a); \
    (a) ^= (b); \
} while (0)

int main(void) {

  if (is_divideble(30))
  {
    printf("Yes, 30 is divideble\n");
  }

  printf("14.3 is digit: %d\n", is_digit(14.3));
  printf("12 is digit: %d\n", is_digit(12));
  printf("AF is hex: %d\n", is_hex(0xAF));

  int x = 10;
  int y = 20;

  printf("Before swapping: x = %d, y = %d\n", x, y);

  // Swap x and y using the macro
  SWAP_INTS(x, y);

  printf("After swapping: x = %d, y = %d\n", x, y);


  return 0;
}