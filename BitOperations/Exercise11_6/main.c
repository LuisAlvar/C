#include <stdio.h>

/*
  AI-did not understand the prompt
*/

// Function to left-justify the bits in a number
unsigned int leftJustifyBits(unsigned int num) {
  // Count the number of leading zeros
  int leadingZeros = __builtin_clz(num);

  // Shift the number left by the count of leading zeros
  return num << leadingZeros;
}

void bin(unsigned n)
{
  if(n > 1) {
    bin(n >> 1);
  }
  printf("%d", n & 1);
}

int main() {
  unsigned int inputNumber;
  printf("Enter an unsigned integer: ");
  scanf("%u", &inputNumber);

  bin(inputNumber);
  printf("\n");

  unsigned int result = leftJustifyBits(inputNumber);
  printf("Left-justified result: %u\n", result);

  bin(result);
  printf("\n");

  return 0;
}
