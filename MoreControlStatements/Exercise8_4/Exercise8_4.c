#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Square{
  int width;
  int height;
  char h_type;
  char w_type;
};

struct CheckerBoard {
  int row;
  int col;
};

int main() {

  struct Square sq;
  sq.height = 4;
  sq.width = 5;
  sq.h_type = '|';
  sq.w_type = '-';

  struct CheckerBoard cb;
  cb.col = 10;
  cb.row = 10;

  const int arr_length_cols =  cb.col * sq.width + (cb.col + 1);
  const int arr_length_rows = cb.row * sq.height + (cb.row + 1);

  char board[arr_length_rows][arr_length_cols];

  printf("The total sizes of the width: %d\n", arr_length_cols);
  printf("The total sizes of the height: %d\n", arr_length_rows);

  int row_counter = 0;
  int col_counter = 0;

  // rendering the boarding layout 
  for (int row = 0; row < arr_length_rows; ++row)
  {
    col_counter = 0;

    for (int col = 0; col < arr_length_cols; ++col)
    {

      if (row_counter == 0)
      {
        // +------+--------+ row type
        if (col_counter == 0)
        {
          // printf("+");
          board[row][col] = '+';
        }else {
          // printf("%c",sq.w_type);
          board[row][col] = sq.w_type;
        }
         
      }
      else{
        // |      |      | row type
        if (col_counter == 0)
        {
          // printf("%c",sq.h_type);
          board[row][col] = sq.h_type;
        }
        else {
          // printf(" ");
          board[row][col] = ' ';
        }

      }

      if (col_counter - sq.width == 0)
      {
        col_counter = -1;
      }
      ++col_counter;
    }

    // printf("\n");

    if (row_counter - sq.height == 0) 
    {
      row_counter = -1;
    }

    ++row_counter;
  }
  
  row_counter = 0;
  col_counter = 0;

  // first iteration
  board[1][4] = '1';
  board[2][2] = 'x';
  board[2][4] = '1';

  board[3][2] = '-';
  board[3][3] = '-';
  board[3][4] = '-';

  board[4][3] = '2';
  board[4][4] = '4';

  // second iteration: sq.width + 1 due to the | of the right side
  col_counter = 9;

  // The operands
  board[1][((sq.width + 1) * col_counter) + 3] = '1';
  board[1][((sq.width + 1) * col_counter) + 4] = '0';
    // this is the same for all 
    board[2][((sq.width + 1) * col_counter) + 2] = 'x';
  board[2][((sq.width + 1) * col_counter) + 3] = '1';
  board[2][((sq.width + 1) * col_counter) + 4] = '0';

  // This is constant for all 
  board[3][((sq.width + 1) * col_counter) + 2] = '-';
  board[3][((sq.width + 1) * col_counter) + 3] = '-';
  board[3][((sq.width + 1) * col_counter) + 4] = '-';

  // The result
  board[4][((sq.width + 1) * col_counter) + 2] = '1';
  board[4][((sq.width + 1) * col_counter) + 3] = '0';
  board[4][((sq.width + 1) * col_counter) + 4] = '0';


  for (int row = 0; row < arr_length_rows; row++)
  {

    for (int col = 0; col < arr_length_cols; col++)
    {
      printf("%c", board[row][col]);
    }  
    
    if (row_counter == sq.height + 1)
    {
      printf("\n");
      break;
    }
    
    printf("\n");
    ++row_counter;
  }
  


  return 0;
}
