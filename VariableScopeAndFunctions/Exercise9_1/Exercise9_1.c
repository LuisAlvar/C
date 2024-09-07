#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


/// @brief Computes the number of spaces in a sequence of characters. (Will not determine if a word is exactly a word)
/// @param str a charcter pointer to a array of characters.
/// @return the number of "words" within a sequence of characters
int CountWordsInString(char *str)
{
  int size = strlen(str);
  int counter = 0;

  for (int i = 0; i < size; i++)
  {
    if (str[i] == ' ' 
    || str[i] == '.'
    || str[i] == '!'
    || str[i] == '?'
    || str[i] == '-') ++counter;    
  }
  return counter;
}

int main() {

  char line[500];
  int result;

  printf("Enter a sentence: ");
  fgets(line, sizeof(line), stdin);

  result = CountWordsInString(line);
  printf("Number of words: %d\n", result);
  return 0;
}
