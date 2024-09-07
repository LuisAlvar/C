#include <stdio.h>

#define X_SIZE 10
#define Y_SIZE 10

#define TEST_BIT(v,p) (((v)&(1U << (p))) != 0)

char graphics[X_SIZE % 8][Y_SIZE];

void print_graphics(void);

#define SET_BIT(x,y) graphics[(x)%8][y] |= 0x20

/*
  0 byte            1 byte
                   0 1         
  0 1 2 3 4 5 6 7 | 8 9 
0  
1
2
3
4
5
6
7
8
9
*/


int main(void) {
  printf("%ld\n", sizeof(unsigned int) * 8);
  printf("%ld\n", sizeof(char)*8);

  int x;
  int y;
  unsigned int bit;
  int index = 0;
  int cur_btye = 0;

  for(y = 0; y < Y_SIZE; ++y)// 0 to 10
  {
    index = 0;
    for (x = 0; x < X_SIZE % 8; ++x) // 0 to 1 bytes | each char bytes is 8 bits.  
    {
      for (bit = 0x80; bit > 0; bit = (bit >> 1))
      {
        if (index < X_SIZE - 2)
        { 
          if (y == 0 || y == Y_SIZE - 1) {
            graphics[x][y] = '-';
            // printf("-");
          }
          else{
            graphics[x][y] = ' ';
          }
        }
        ++index;
      }
    }
  }


  for(y = 0; y < Y_SIZE; ++y)// 0 to 10
  {
    for (x = 0; x < X_SIZE; ++x) // 0 to 1 bytes | each char bytes is 8 bits.  
    {
      if (x==0) printf("|");
      
      for (bit = 0x80; bit > 0; bit = (bit >> 1))
      {
        printf("%c", graphics[x][y]);
      }
    }
    printf("|\n");
  }


  // print_graphics();
  return 0;
}

void print_graphics(void) {
  int x; 
  int y;
  unsigned int bit;
  
  for(y = 0; y < Y_SIZE; ++y)// 0 to 10
  {
    for (x = 0; x < X_SIZE; ++x) // 0 to 1 bytes | each char bytes is 8 bits.  
    {
      for (bit = 0x80; bit > 0; bit = (bit >> 1))
      {
        printf("%c", graphics[x][y]);
      }
    }
    printf("\n");
  }
  return;
}
