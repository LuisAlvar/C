#include <stdio.h>
#include <math.h>

/*
  AI-did not understand the prompt
*/

// int main(void) {

//   long int num = 34;
//   int arr_bit = sizeof(num)*8;
//   int counter = 1;

//   for (int i = arr_bit - 1;  i >= 0; --i)
//   {
//     if (num >= pow(2.0, (double)i))
//     {
//       printf("1");
//       num = num - pow(2,i);
//     }
//     else {
//       if (num < -1)
//       {
//         printf("1");
//       }else {
//         printf("0");
//       }
//     }
//     if (counter % 4 == 0)
//     {
//       printf("|");
//     }
    
//     ++counter;
//   }
  
//   printf("\n");
//   return 0;
// }

#include <stdio.h>

// Function to split a 32-bit integer into 4-bit values
void splitInto4BitValues(int num) {
  // Ensure we work with the lower 32 bits (ignoring sign extension)
  unsigned int unsignedNum = (unsigned int)num;

  printf("Original integer: %d\n", num);

  // Extract each 4-bit value
  for (int i = 7; i >= 0; --i) {
      unsigned int value = (unsignedNum >> (i * 4)) & 0xF;
      printf("4-bit value %d: %X\n", i, value);
  }
}

int main() {
  int inputNumber;
  printf("Enter a 32-bit integer: ");
  scanf("%d", &inputNumber);

  splitInto4BitValues(inputNumber);

  return 0;
}
