#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


/// @brief 
/// @param str1 
/// @param str2 
/// @return 
bool begins(char *str1, char * str2) 
{
  // before we compare, then need to ensure that the second string is not longer that the first string. 
  // the second string should be a subset of the first string.
  if (strlen(str2) > strlen(str1)) return false;

  for (int i = 0; i < strlen(str2); i++)
  {
    if (i < strlen(str1) && str1[i] != str2[i] ) return false;
  }
  
  return true;
}

int main() {

  char str_a[500];
  char str_b[500];
  bool result;

  printf("Enter for first string: ");
  fgets(str_a, sizeof(str_a), stdin);
  str_a[strlen(str_a)-1] = '\0';

  printf("Enter for second string: ");
  fgets(str_b, sizeof(str_b), stdin);
  str_b[strlen(str_b)-1] = '\0';

  result = begins(str_a, str_b);
  printf("Comparsion: does %s begin with %s: ", str_a, str_b);
  if (result)
  {
    printf("True\n");
  } 
  else {
    printf("False\n");
  }
  
  return 0;
}
