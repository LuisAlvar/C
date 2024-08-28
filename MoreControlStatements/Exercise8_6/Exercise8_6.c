#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char line[100];
int number;
char result[500];

void ConvertToWords(int num, char *p);
bool PlacementPair(int place);
void UpperRankPlacement(int place, char *p);
void LowerRankPlacement(int place, char *p);
void CurrentRankPlacement(int place, char *p);
void Decimal(int digit, char *p);
void Vigesimal(int digit, char *p);
void Tens(int digit, char *p) ;

int main(void) {
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
  char temp[250] = "";
  char result[500] = "";
  // number tracking with two indices
  char char_arry_num[6]; /*limitation on the conversion - its okay for now*/
  int char_arry_size;  
  int cur_index = 0;
  int adj_index = cur_index + 1;
  // tracking the number placement 
  char lower_rank[50] = "";
  char upper_rank[50] = "";
  char rank[50] = "";
  bool isPair = false;
  int rank_index = 0;

  sprintf(char_arry_num, "%d", num);
  char_arry_size = strlen(char_arry_num);
  rank_index =  char_arry_size - 1;

  while(rank_index != -1)
  {
    strcpy(temp, ""); /*Reset the temp buffer*/
    isPair = PlacementPair(rank_index);
    CurrentRankPlacement(rank_index, rank);
    printf("Rank Index: %d\n", rank_index);
    printf("Is Rank: %d\n", isPair);
    printf("Current Placement Rank: %s\n", rank);

    /*>>>>>>>>>>>>>> 1. Handle the Numberic Conversion to Words <<<<<<<<<<<<<*/
    if (isPair)
    {
      // Get the current index value and the adjacent index value: 4 3
      char *digit2 = (char*)malloc(sizeof(char)); 
      *(digit2) = char_arry_num[cur_index];
      char *digit1 = (char*)malloc(sizeof(char)); 
      *(digit1) = char_arry_num[adj_index];

      int two_digit_value = atoi(digit2) * 10 + atoi(digit1);
      printf("%d\n", two_digit_value);

      Vigesimal(two_digit_value, temp); // if the value is 10-19
      if(strlen(temp) == 0) 
      {
        // otherwise, we break down the two digits
        // breaking down the second digit
        Tens(atoi(digit2), temp);
        strcat(result, temp);

        if (strlen(temp) != 0 && atoi(digit1) != 0)
        {
          // in the case we get a valid result from Tens method 
          // and the adjacent value is not zero,
          // then add this spacer
          strcat(result, "-");
        }
        
        // breaking down the first digit
        Decimal(atoi(digit1), temp);
        strcat(result, temp);
      }
      else
      {
        // if the value is 10-19, just add the temp to the final buffer
        strcat(result, temp);
      }

      free(digit1); /*deallocate the memory for deep copy*/
      free(digit2); /*deallocate the memory for deep copy*/
      // adjusting the two indices
      cur_index = adj_index;
      ++cur_index;
      adj_index = cur_index + 1;
    }
    else 
    {
      // Get the current index value 
      char *digit = (char*)malloc(sizeof(char));
      *(digit) = char_arry_num[cur_index];
      Decimal(atoi(digit), temp);
      strcat(result, temp);
      free(digit);
      // adjusting the two indices. 
      ++cur_index;
      adj_index = cur_index + 1;
    }

    /*>>>>>>>>>>>>>> 2. Handle the Value Placement Quantity <<<<<<<<<<<<<*/
    UpperRankPlacement(rank_index, upper_rank);
    LowerRankPlacement(rank_index, lower_rank);
    printf("upper rank: %s\n", upper_rank);
    printf("lower rank: %s\n", lower_rank);

    // In the case there we have placement like hundred thousands 
    if (strlen(lower_rank) != 0)
    {
      //add the hundreds word as the lower rank compared to the thousands.
      strcat(result, " ");
      strcat(result, lower_rank);
      // we dont have print the upper rank yet.
    }

    // adjust the rank index based on if isPair.
    if (isPair)
    {
      rank_index -= 2;
    }
    else{
      --rank_index; 
    }

    // check the rank under this new rank index
    UpperRankPlacement(rank_index, rank);

    // compare previous rank with this new rank
    if(strcmp(upper_rank, rank))
    { 
      // for example upper_rank is thousand and new rank is hundreds, this means there is a change in placement
      // if different, then add upper rank
      strcat(result, " ");
      strcat(result, upper_rank);
    }

    strcat(result, " ");
    printf("next cur_index: %d\n", cur_index);
    printf("next adj_index: %d\n", adj_index);
    printf("next rank: %d\n", rank_index);
    printf("Result: %s\n", result);
    printf("\n");
  }
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





