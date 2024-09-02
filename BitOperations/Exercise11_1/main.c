#include <stdio.h>

#define CLEAR_BIT(v,p) ((v) &= ~(1U << (p)))
#define TEST_BIT(v,p) (((v)&(1U << (p))) != 0)
#define SET_BIT(x,p) x|=(1U << (p))

void bin(unsigned n)
{
  if(n > 1) {
    bin(n >> 1);
  }
  printf("%d", n & 1);
}


int main(void) {
  unsigned int num = 0b0010100;
  printf("Original: %u\n", num);
  bin(num);
  printf("\n");
  num = CLEAR_BIT(num, 2);
  printf("After clearing bit 3: %u\n", num);
  bin(num);
  printf("\n");

  if(TEST_BIT(num, 4)) {
    printf("Bit 5 is set.\n");
  } else {
    printf("Bit 5 is not set.\n");
  }

  num = SET_BIT(num, 3);
  bin(num);
  printf("\n");
  if(TEST_BIT(num, 3)) {
    printf("Bit 4 is set.\n");
  } else {
    printf("Bit 4 is not set.\n");
  }

  return 0;
}
