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
  sq.height = 3;
  sq.width = 5;
  sq.h_type = '|';
  sq.w_type = '-';

  struct CheckerBoard cb;
  cb.col = 8;
  cb.row = 8;

  const int arr_length_cols =  cb.col * sq.width + (cb.col + 1);
  const int arr_length_rows = cb.row * sq.height + (cb.row + 1);

  char board[arr_length_rows][arr_length_cols];

  printf("The total sizes of the width: %d\n", arr_length_cols);
  printf("The total sizes of the height: %d\n", arr_length_rows);

  int row_counter = 0;
  int col_counter = 0;

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
          printf("+");
        }else {
          printf("%c",sq.w_type);
        }
         
      }
      else{
        // |      |      | row type
        if (col_counter == 0)
        {
          printf("%c",sq.h_type);
        }
        else {
          printf(" ");
        }
      }

      if (col_counter - sq.width == 0)
      {
        col_counter = -1;
      }
      ++col_counter;
    }

    printf("\n");

    if (row_counter - sq.height == 0) 
    {
      row_counter = -1;
    }

    ++row_counter;
  }
  

  return 0;
}
