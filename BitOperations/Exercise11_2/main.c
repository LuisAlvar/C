#include <stdio.h>

#define CLEAR_BIT(v,p) ((v) &= ~(1U << (p)))
#define TEST_BIT(v,p) (((v)&(1U << (p))) != 0)
#define SET_BIT(x,p) x|=(1U << (p))

#define X_SIZE 10
#define Y_SIZE 10

char graphics[X_SIZE][Y_SIZE];


void print_graphics(void);

int main(void) {

  print_graphics();
  return 0;
}


void print_graphics(void) {
  int x;
  int y;
  unsigned int bit;

  for(y = 0; y < Y_SIZE; ++y)// 0 to 39
  {
    for (x = 0; x < X_SIZE; ++x) // 0 to 4 bytes | each char bytes is 8 bits.  
    {
      printf(".");
    }
    printf("\n");
  }
}
