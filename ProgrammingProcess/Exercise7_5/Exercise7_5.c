#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void isPrime(int number) {
  bool is_prime = true;

  if (number == 1 || number < 0)
  {
    printf("\t\tPrime number can only be natural numbers. Excluding 1\n");
    return;
  }
  
  for (int i = 2; i <= number; i++)
  {
    if (number != i && number % i == 0)
    {
      is_prime = false;
      break;
    }
  }

  if (is_prime)
  {
    printf("\t\tNumber is prime\n");
  } else {
    printf("\t\tNumber is not prime\n");
  }
}

int main() {

  char line[100];
  int num;

  while(1) {
    printf("Check if a number if prime: ");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d", &num);
    if (num == -1) break;
    isPrime(num);
  }

  return 0;
}
