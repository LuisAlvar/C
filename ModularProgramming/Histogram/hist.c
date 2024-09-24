/*********************************************************************
 * hist -- generates a histogram of an array of numbers
 * Usage
 *      hist <file>
 * Where
 *      file is the name of the file to work on
*********************************************************************/
#include "./bin/ia.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

// define the number of lines in the histogram
#define NUMBER_OF_LINES 30 /* Number of lines in the histogram */
const int DATA_MIN = 1;    /* Number of the smallest item */
const int DATA_MAX = 30;   /* Number of the largest item */

/*
* WARNING: the number of items from DATA_MIN to DATA_MAX (inclusive)
* must match the number of lines.
*/

// number of characters wide to make the histogram
const int WIDTH = 60;

// global data structure of type (infinite_array)
static struct infinite_array data_array;
// global tracker the size of main data structure
static int data_items;

/// @brief Reads data from the input file into the data_array.
/// @param name The name of the file to read.
void read_data(const char name[]);

/// @brief prints the histogram output
void print_histogram();

int main(int argc, char* argv[])
{
  if (argc != 2)
  {
    fprintf(stderr, "Error: Wrong number of arguments\n");
    fprintf(stderr, "Usage is: \n");
    fprintf(stderr, "\thist <data-file>\n");
  }
  ia_init(&data_array);
  data_items = 0;

  read_data(argv[1]);
  print_histogram();
  return 0;
}

/// @brief Reads data from the input file into the data_array.
/// @param name The name of the file to read.
void read_data(const char name[]) 
{
  char line[100]; /* line from input file*/
  FILE* in_file;  /* input file */
  int data;       /* data from input */

  in_file = fopen(name, "r");
  if (in_file == NULL)
  {
    fprintf(stderr, "Error: Unable to open %s\n", name);
    exit(8);
  }
  while (1)
  {
    if (fgets(line, sizeof(line),in_file) == NULL) break;

    if (sscanf(line, "%d", &data) != 1)
    {
      fprintf(stderr, "Error: Input data not integer number\n");
      fprintf(stderr, "Line: %s", line);
    }
    ia_store(&data_array, data_items, data); 
    ++data_items;
  }
  fclose(in_file);
}

/// @brief prints the histogram output
void print_histogram()
{
  /* upper bound for printout */
  int counters[NUMBER_OF_LINES]; // default size is 30

  int out_of_range = 0;   /* number of items out of bounds */
  int max_count = 0;      /* biggest counter */
  float scale;            /* scale for outputting dots */
  int index;              /* current index for the data */

  memset(counters, '\0', sizeof(counters)); // initializing the array data with zeros

  for (index = 0; index < data_items; ++index)
  {
    int data; // data for this point
    data = ia_get(&data_array, index);

    if ((data < DATA_MIN) || (data > DATA_MAX))
    {
      ++out_of_range;
    }
    else
    {
      // for the location index on the array, increment the value by 1;
      // for example if data is 3, then 3-1 = 2. On the index 2, we increment by 1.      
      ++counters[data - DATA_MIN];
      // if true, then set max_count to this counter value
      if (counters[data - DATA_MIN] > max_count) max_count = counters[data - DATA_MIN];
    }
  }
  
  scale = ((float)max_count) / ((float)WIDTH);

  for (index = 0; index < NUMBER_OF_LINES; ++index)
  {
    // index for outputting the dots
    int char_index;
    int number_of_dots;  // number of * to output

    printf("%2d (%4d): ", index + DATA_MIN, counters[index]);
    number_of_dots = (int) (((float)counters[index]) / scale);

    for (char_index = 0; char_index < number_of_dots; ++char_index)
    {
      printf("*");
    }
    printf("\n");
  }
  printf("%d items out of range\n", out_of_range);
}