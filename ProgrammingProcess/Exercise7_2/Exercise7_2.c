#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

#define DATE_CHAR_ARRAY_SIZE 10

char line[100];

struct DateTime {
  int year;
  int day;
  int month;
  bool isLeapYear;
};


int process_dates(char date1[DATE_CHAR_ARRAY_SIZE], char date2[DATE_CHAR_ARRAY_SIZE]);
struct DateTime convert_dates_to_int_data(char date[DATE_CHAR_ARRAY_SIZE]);
int process_years(int year1, int year2);
int process_month_day(int month_a, int day_a, int month_b, int day_b);
int days_in_this_month(int month);
bool isLeapYear(int year);
void sub_str(char *source, char *dest, int start_index, int size);


int main() {

  char date_1[DATE_CHAR_ARRAY_SIZE];
  char date_2[DATE_CHAR_ARRAY_SIZE];
  int days = 0;

  printf("Enter first date (mm/dd/yyyy): ");
  fgets(line, sizeof(line), stdin);
  sscanf(line, "%s", date_1);
  // if(!strcmp(date_1,"q")) break;

  printf("Enter second date (mm/dd/yyyy): ");
  fgets(line, sizeof(line), stdin);
  sscanf(line, "%s", date_2);
  // if(!strcmp(date_2,"q")) break;

  days = process_dates((char*)date_1, (char*)date_2);
  printf("Number of days between the dates: %d\n", days);

  return 0;
}



int process_dates(char *date1, char *date2) {
  int total_days = 0;

  struct DateTime dt1, dt2;
  dt1 = convert_dates_to_int_data(date1);
  dt2 = convert_dates_to_int_data(date2);
  
  printf("first month: %d\n", dt1.month);
  printf("second month: %d\n", dt2.month);

  total_days += process_month_day(dt1.month, dt1.day, dt2.month, dt2.day);
  total_days += process_years(dt1.year, dt2.year);

  return total_days;
}

struct DateTime convert_dates_to_int_data(char *date) {

  struct DateTime dt;
  struct tm tm = {0};

  if (strptime(date, "%m/%d/%Y", &tm) == NULL)
  {
    printf("Date parsing failed!\n");
    exit(2);
    return dt;
  }

  time_t final_date = mktime(&tm);
  printf("Date: %s", asctime(&tm));

  dt.month = tm.tm_mon + 1;
  dt.day = tm.tm_mday;
  dt.year = tm.tm_year;
  dt.isLeapYear = isLeapYear(dt.year);
  printf("Is year a leap year: %d\n", dt.isLeapYear);
  printf("Breaked %d/%d/%d\n", dt.month, dt.day, dt.year);

  return dt;
}

/// @brief Use to calculate the number of days between the two year within an interval. 
/// @param year1 the first year within the interval (i.e., as the a within [a, b] interval)
/// @param year2 the second year within the interval (i.e., as the b within [a, b] interval)
/// @return Number of days 
int process_years(int year1, int year2)
{

  int smaller_year = year1;
  int greater_year = year2;

  if(year1 > year2){
    smaller_year  = year2;
    greater_year = year1;
  }

  int count_the_num_of_years = greater_year - smaller_year;
  int count_the_num_of_leap_year_in_between = 0;

  for (int i = smaller_year; i <= greater_year; i++)
  {
    if(isLeapYear(i)) ++count_the_num_of_leap_year_in_between;
  }
  
  return (count_the_num_of_years * 365) + (count_the_num_of_leap_year_in_between * 1);
}

/// @brief Use to calculate the number of day between two dates in terms of their months and days. 
/// @param month_a the coresponding month of the given month date A
/// @param day_a  the corresponsing day of the given month date A
/// @param month_b the corresponding month of the given month date B
/// @param day_b the corresponding day of the given month date B
/// @return Number of days between a given mm/dd and another mm/dd 
int process_month_day(int month_a, int day_a, int month_b, int day_b)
{

  printf("this is month_a: %d\n", month_a);
  printf("this is month_b: %d\n", month_b);
  int counter = 0;

  int greater_month = 0;
  int greater_day = 0;

  greater_month = month_b;
  greater_day = day_b;

  int smaller_month = 0;
  int smaller_day = 0;

  smaller_month = month_a;
  smaller_day = day_a;

  if (month_a > month_b)
  {
    printf("month a is greater than month b");
    greater_month = month_a;
    greater_day = day_a;

    smaller_month = month_b;
    smaller_day = day_b;
  }

  // counter = Total days of a given month - the current day. 
  printf("smaller_month %d: \n", smaller_month);
  counter += days_in_this_month(smaller_month) - smaller_day;
  printf("Counter check after (1): %d\n", counter);
  // we move the given month from 01 to 02, because we alway accounted for the first month.
  ++smaller_month;

  // Now iterator throught the number from months from 02 to 11, and add the number of days within each month. 
  for (int i = smaller_month; i < greater_month; i++)
  {
    counter += days_in_this_month(i);
  }
  
  // Once you get to the last month, then we count upwards to the day. 
  for (int i = 1; i <= days_in_this_month(greater_month); i++)
  {
    ++counter;
    if (i == greater_day) break;
  }
  

  return counter;
}

/// @brief Use to get the number of days within a given month. 
/// @param month Any given month 
/// @return Number of days within a given month
int days_in_this_month(int month) {
  int days = 0;
  switch (month)
  {
    case 1:
      days = 31;
      break;
    case 2:
      days = 28;
      break;
    case 3:
      days = 31;
      break;
    case 4:
      days = 30;
      break;
    case 5:
      days = 31;
      break;
    case 6:
      days = 30;
      break;
    case 7:
      days = 31;
      break;
    case 8:
      days = 31;
      break;
    case 9:
      days = 30;
      break;
    case 10:
      days = 31;
      break;
    case 11:
      days = 30;
      break;
    case 12:
      days = 31;
      break;
  }
  return days;
}

/// @brief 
/// @param year 
/// @return 
bool isLeapYear(int year)
{
  bool result = false;
  if (year % 4 == 0)
  {
    result = true;
  }
  else if(year % 100 == 0 && year % 400 != 0) {
    result = false;
  }
  return result;
}


/// @brief 
/// @param source 
/// @param dest 
/// @param start_index 
/// @param size 
void sub_str(char *source, char *dest, int start_index, int size){
  int index = start_index;
  char *result = (char*)(size * sizeof(char));
  int arr_index = 0;
  while (index < start_index + size) {
    printf("%c ", source[index]);
    // dest[strlen(dest)] = source[index];
    result[arr_index] = source[index];
    ++arr_index;
    ++index;
  }
  printf("\n");
  printf("modified array: %s\n", result);
}