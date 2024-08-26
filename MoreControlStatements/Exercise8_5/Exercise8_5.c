#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char line[100];

bool isVowel(char letter);

int main() {

  char letter;

  while (1)
  {
    printf("Enter a letter to determine whether its a vowel or consonant: ");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%c", &letter);

    if (letter == '!') break;
    

    if (isVowel(letter))
    {
      printf("Letter is a vowel.\n");
    } else {
      printf("Letter is a consonant.\n");
    }

  }

  return 0;
}

bool isVowel(char letter) {
  bool result = false;
  switch (letter)
  {
    case 'a':
      result = true;
      break;
    case 'e':
      result = true;
      break;
    case 'i':
      result = true;
      break;
    case 'o':
      result = true;
      break;
    case 'u':
      result = true;
      break;
    case 'y':
      result = true;
      break;
  }
  return result;
}
