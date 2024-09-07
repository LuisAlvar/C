#include <stdio.h>

int BitCounter(int number)
{
  printf("%d\n", number);

  if (number == 1) return 1;
  
  int counter = 0;
  if(number > 1) {
    counter = BitCounter(number >> 1); //right-shifting 1 place is the same as dividing by 2
  }

  if (counter != 0 && number & 1)
  {
    return counter + 1;
  }
  
  return counter;
}

void bin(unsigned n)
{
  if(n > 1) {
    bin(n >> 1);
  }
  printf("%d", n & 1);
}


int main(void) {
  int num = 1;
  bin(num);
  printf("\n");
  printf("Contains 1 bits: %d\n", BitCounter(num));
  return 0;
}
