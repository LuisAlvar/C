#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char line[100];
int number;
char result[200];

enum PlaceValues {
  ones,
  tens, 
  hundred, 
  thousands,
  ten_thousands,
  houndred_thousands, 
  millions
};


void ConvertToWords(int num, char *p);
bool PlacementPair(int place);
void UpperRankPlacement(int place, char *p);
void LowerRankPlacement(int place, char *p);
void CurrentRankPlacement(int place, char *p);
void Decimal(int digit, char *p);
void Vigesimal(int digit, char *p);
void Tens(int digit, char *p) ;

int main() {

  while (1)
  {
 
    printf("Enter a number to convert to words: ");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d", &number);

    ConvertToWords(number, result);

    printf("%s\n", result);
  }

  return 0;
}


void ConvertToWords(int num, char *p) {
  char char_arry_num[5];
  char temp[100] = "";
  char result[100] = "";
  int arry_size;

  sprintf(char_arry_num, "%d", num);
  arry_size = strlen(char_arry_num);
  int cur_index = 0;
  int adj_index = cur_index + 1;
  char lower_rank[20] = "";
  char upper_rank[20] = "";
  char rank[20] = "";
  bool isPair = false;
  int rank_index =  arry_size - 1;

  printf("Rank Index: %d\n", rank_index);
  printf("%c\n", char_arry_num[0]);
  printf("%c\n", char_arry_num[1]);

  isPair = PlacementPair(rank_index);

  printf("Is current rank a pair: %d\n", isPair);
  // cur_index && adj_index;
  // atoi(&char_arry_num[cur_index])
  CurrentRankPlacement(rank_index, rank);
  printf("This is the current rank: %s\n", rank);

  if (isPair)
  {
    char *digit2 = (char*)malloc(sizeof(char)); 
    *(digit2) = char_arry_num[cur_index];
    char *digit1 = (char*)malloc(sizeof(char)); 
    *(digit1) = char_arry_num[adj_index];

    int two_digit_value = atoi(digit2) * 10 + atoi(digit1);
    printf("%d\n", two_digit_value);

    Vigesimal(two_digit_value, temp);
    if(strlen(temp) == 0) 
    {
      Tens(atoi(digit2), temp);
      strcat(result, temp);

      if(atoi(digit1) != 0){
        Decimal(atoi(digit1), temp);
        strcat(result, "-");
        strcat(result, temp);
      }
    }else
    {
      strcat(result, temp);
    }
    printf("%s\n", result);
    free(digit1);
    free(digit2);
    // cur_index = adj_index;
    // ++cur_index;
    // adj_index = adj_index + 1;
  }
  else 
  {
    char *digit = (char*)malloc(sizeof(char));
    *(digit) = char_arry_num[cur_index];
    Decimal(atoi(digit), temp);
    strcat(result, temp);
    printf("%s\n", result);
    free(digit);
    // ++cur_index;
  }

  UpperRankPlacement(rank_index, upper_rank);
  LowerRankPlacement(rank_index, lower_rank);

  printf("upper rank: %s\n", upper_rank);
  printf("lower rank: %s\n", lower_rank);

  if (strlen(lower_rank) != 0)
  {
    strcat(result, " ");
    strcat(result, lower_rank);
  }

  UpperRankPlacement(rank_index - 1, rank);

  if(strcmp(upper_rank, rank))
  {
    // if different, then add upper rank
    strcat(result, " ");
    strcat(result, upper_rank);
  }
  
  
  printf("%s", result);
  printf("\n");
}

bool PlacementPair(int place)
{
  switch (place)
  {
    case 0:
      return false;
    case 1:
      return true;
    case 2: 
      return false;
    case 3:
      return false;
    case 4:
      return true;
    case 5:
      return false;
    case 6:
      return false;
  }
}

void UpperRankPlacement(int place, char *p) 
{
  switch (place)
  {
    case 0:
      strcpy(p, ""); 
      return;
    case 1:
      strcpy(p, "");
      return;
    case 2: 
      strcpy(p, "hundred");
      return;
    case 3:
      strcpy(p, "thousand");
      return;
    case 4:
      strcpy(p, "thousand");
      return;
    case 5:
      strcpy(p, "thousand");
      return;
    case 6:
      strcpy(p, "million");
      return;
    default:
      strcpy(p, "");
      return;
  }
}

void LowerRankPlacement(int place, char *p) 
{
  switch (place)
  {
    case 0:
      strcpy(p, ""); 
      return;
    case 1:
      strcpy(p, "");
      return;
    case 2: 
      strcpy(p, "");
      return;
    case 3:
      strcpy(p, "");
      return;
    case 4:
      strcpy(p, "");
      return;
    case 5:
      strcpy(p, "hundred");
      return;
    case 6:
      strcpy(p, "");
      return;
  }
}

void CurrentRankPlacement(int place, char *p) 
{
  switch (place)
  {
    case 0:
      strcpy(p, "one"); 
      return;
    case 1:
      strcpy(p, "ten");
      return;
    case 2: 
      strcpy(p, "hundred");
      return;
    case 3:
      strcpy(p, "thousand");
      return;
    case 4:
      strcpy(p, "ten_thousand");
      return;
    case 5:
      strcpy(p, "hundred_thousand");
      return;
    case 6:
      strcpy(p, "million");
      return;
  }
}

void Decimal(int digit, char *p) 
{
  switch (digit)
  {
    case 0:
      strcpy(p, "");
      return;
    case 1:
      strcpy(p, "one");
      return;
    case 2:
      strcpy(p, "two");
      return;
    case 3:
      strcpy(p, "three");
      return;
    case 4:
      strcpy(p, "four");
      return;
    case 5:
      strcpy(p, "five");
      return;
    case 6:
      strcpy(p, "six");
      return;
    case 7:
      strcpy(p, "seven");
      return;
    case 8:
      strcpy(p, "eight");
      return;
    case 9:
      strcpy(p, "nine");
      return;
    default:
      return;
  }
}

void Vigesimal(int digit, char *p) 
{
  switch (digit)
  {
    case 10:
      strcpy(p, "ten");
      return;
    case 11:
      strcpy(p, "eleven");
      return;
    case 12:
      strcpy(p, "twelve");
      return;
    case 13:
      strcpy(p, "thirteen");
      return;
    case 14:
      strcpy(p, "fourteen");
      return;
    case 15:
      strcpy(p, "fifteen");
      return;
    case 16:
      strcpy(p, "sixteen");
      return;
    case 17:
      strcpy(p, "seventeen");
      return;
    case 18:
      strcpy(p, "eighteen");
      return;
    case 19:
      strcpy(p, "nineteen");
      return;
    case 20:
      strcpy(p, "twenty");
      return;
    default:
      return;
  }
}

void Tens(int digit, char *p) 
{
  switch (digit)
  {
    case 2:
      strcpy(p, "twenty");
      return;
    case 3:
      strcpy(p, "thirty");
      return;
    case 4:
      strcpy(p, "forty");
      return;
    case 5:
      strcpy(p, "fifty");
      return;
    case 6:
      strcpy(p, "sixty");
      return;
    case 7:
      strcpy(p, "seventy");
      return;
    case 8:
      strcpy(p, "eighty");
      return;
    case 9:
      strcpy(p, "ninety");
      return;
    default:
      return;
  }
}





