#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Square{
  int width;
  int height;
  char h_type;
  char w_type;
};

struct MultiplicationBoard {
  int row;
  int col;
};

int main() {

  struct Square sq;
  sq.height = 4;
  sq.width = 5;
  sq.h_type = '|';
  sq.w_type = '-';

  struct MultiplicationBoard cb;
  cb.col = 10;
  cb.row = 10;

  const int arr_length_cols =  cb.col * sq.width + (cb.col + 1);
  const int arr_length_rows = cb.row * sq.height + (cb.row + 1);

  char board[arr_length_rows][arr_length_cols];

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

  int insert_index = 4;
  int size = 0;
  int result = 0;
  char operands[2];
  char compute[3];
  int char_index = size - 1;
  int multiplication_value_row = 1;
  int multiplication_value_col = 1;

  // render the multiplication table
  for (int row = 0; row < cb.row; ++row)
  {
    multiplication_value_col = 1;
    for (int col = 0; col < cb.col; ++col)
    {
      // First operand
      sprintf(operands, "%d", multiplication_value_row);
      size = strlen(operands);
      char_index = size - 1;
      insert_index = 4;

      while (size != 0)
      {
        board[((sq.height + 1) * row) + 1][((sq.width + 1) * col) + insert_index] = operands[char_index];
        --size;
        --insert_index;
        --char_index;
      }

      // The multiplicaiton sign will always be the same place. 
      board[((sq.height + 1) * row) + 2][((sq.width + 1) * col) + 2] = 'x';

      // Second operand 
      sprintf(operands, "%d", multiplication_value_col);
      size = strlen(operands);
      char_index = size - 1;
      insert_index = 4;
      while (size != 0)
      {
        board[((sq.height + 1) * row) + 2][((sq.width + 1) * col) + insert_index] = operands[char_index];
        --size;
        --insert_index;
        --char_index;
      }

      // The diviser does not change is always constant
      board[((sq.height + 1) * row) + (sq.height -1)][((sq.width + 1) * col) + 2] = '-';
      board[((sq.height + 1) * row) + (sq.height -1)][((sq.width + 1) * col) + 3] = '-';
      board[((sq.height + 1) * row) + (sq.height -1)][((sq.width + 1) * col) + 4] = '-';

      // The computation
      result = multiplication_value_row * multiplication_value_col;
      sprintf(compute, "%d", result);
      size = strlen(compute);
      char_index = size - 1;
      insert_index = 4;
      while (size != 0)
      {
        board[((sq.height + 1) * row) + 4][((sq.width + 1) * col) + insert_index] = compute[char_index];
        --size;
        --insert_index;
        --char_index;
      }

      ++multiplication_value_col;
    }
  
    ++multiplication_value_row;
  }


  // render the final result
  for (int row = 0; row < arr_length_rows; row++)
  {
    for (int col = 0; col < arr_length_cols; col++)
    {
      printf("%c", board[row][col]);
    }  
    printf("\n");
  }
  
  return 0;
}


