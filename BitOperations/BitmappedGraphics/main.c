#include <stdio.h>

#define X_SIZE 40 /* size of array in X direction */
#define Y_SIZE 60 /* size of array in Y direction */

/*
* We use X_SIZE/8 because we pack 8 bits per byte: 5 
*/
char graphics[X_SIZE/8][Y_SIZE]; /* the graphics data */

#define SET_BIT(x,y) graphics[(x)/8][y] |= (0x80 >> ((x)%8))

void print_graphics(void) {
  int x;
  int y;
  unsigned int bit;

  for(y = 0; y < Y_SIZE; ++y) 
  {
    for (x = 0; x < X_SIZE /8; ++x)
    {
      for (bit = 0x80; bit > 0; bit = (bit >> 1))
      {
        if ((graphics[x][y] & bit) != 0)
        {
          printf("\\");
        }
        else {
          printf(".");
        }
      }
    }
    printf("\n");
  }
}

int main(void) {
  int loc;
  void print_graphics(void);

  for (loc = 0; loc < X_SIZE; ++loc)
  {
    SET_BIT(loc, loc);
  }
  
  print_graphics();
  return 0;
}
