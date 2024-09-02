#include <stdio.h>

#define X_SIZE 40 /* size of array in X direction */
#define Y_SIZE 40 /* size of array in Y direction */

/*
* We use X_SIZE/8 because we pack 8 bits per byte: 5 
*/
char graphics[X_SIZE/8][Y_SIZE]; /* the graphics data */

#define SET_BIT(x,y) graphics[(x)/8][y] |= (0x80 >> ((x)%8))
/*
  In other words for SET_BIT macro: for example(20,20)
  byte_y = y = 20
  byte_x = x / 8; 20 / 8 = 2.5 = 2

  bit_index = 20 % 8 = 4
  bit = 0x80 >> bit_index = 1000|0000 >> 4 = 0000 | 1000
  graphics[2][20] |= bit = 0x08
*/
void print_graphics(void);

int main(void) {
  int loc;

  for (loc = 0; loc < X_SIZE; ++loc)
  {
    // 0,0 | 1,1 | .. | 38,38 | 39,39
    SET_BIT(loc, loc);
  }
  
  print_graphics();
  return 0;
}

void print_graphics(void) {
  int x;
  int y;
  unsigned int bit;

  for(y = 0; y < Y_SIZE; ++y)// 0 to 39
  {
    for (x = 0; x < X_SIZE /8; ++x) // 0 to 4 bytes | each char bytes is 8 bits.  
    {
      // Move the place of the 1 to the right within each iteration
      for (bit = 0x80; bit > 0; bit = (bit >> 1)) // 1000|0000 (x80) to 0000|0001 (x01)
      {
        // if graphics[2][20] = 0x80 & 0x80 = 0x80 != 0, then print \\ 
        if ((graphics[x][y] & bit) != 0)
        {
          printf("\\");
        }
        // otherwise if does not match, then
        else {
          printf(".");
        }
      }
    }
    printf("\n");
  }
}
