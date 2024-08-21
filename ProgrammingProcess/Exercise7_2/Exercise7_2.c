#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

#define DATE_CHAR_ARRAY_SIZE 10

char line[100];

struct DateTime {
  time_t time;
  struct tm st_time;
  int year;
  int day;
  int month;
};


int process_dates(char date1[DATE_CHAR_ARRAY_SIZE], char date2[DATE_CHAR_ARRAY_SIZE]);
void sub_str(char *source, char *dest, int start_index, int size);
struct DateTime convert_dates_to_int_data(char date[DATE_CHAR_ARRAY_SIZE]);


int main() {

  char date_1[DATE_CHAR_ARRAY_SIZE];
  char date_2[DATE_CHAR_ARRAY_SIZE];
  int days = 0;

  while(1){

    printf("Enter first date (mm/dd/yyyy): ");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%s", date_1);
    if(!strcmp(date_1,"q")) break;

    printf("Enter second date (mm/dd/yyyy): ");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%s", date_2);
    if(!strcmp(date_2,"q")) break;

    days = process_dates(date_1, date_2);
    printf("Number of days between the dates: %d\n", days);
  }

  return 0;
}



int process_dates(char date1[DATE_CHAR_ARRAY_SIZE], char date2[DATE_CHAR_ARRAY_SIZE]) {

  struct DateTime dt1, dt2;
  dt1 = convert_dates_to_int_data(date1);
  dt2 = convert_dates_to_int_data(date2);
 
  printf("Formatted date & time: %s\n", ctime(&dt1.time));
  printf("Formatted date & time: %s\n", ctime(&dt2.time));

  return 0;
}


struct DateTime convert_dates_to_int_data(char date[DATE_CHAR_ARRAY_SIZE]) {

  struct DateTime dt;
  char *month = malloc(2 * sizeof(char));
  char *day = malloc(2 * sizeof(char));
  char *year = malloc(4 * sizeof(char));
  
  sub_str(date, month, 0, 2);
  sub_str(date, day, 3, 2);
  sub_str(date, year, 6, 4);

  dt.month = atoi(month);
  dt.day = atoi(day);
  dt.year = atoi(year);

  time_t rawtime;
  struct tm timeinfor;
  
  timeinfor.tm_year = dt.year - 1900;
  timeinfor.tm_mon = dt.month - 1;
  timeinfor.tm_mday = dt.day;
  timeinfor.tm_hour = 0;
  timeinfor.tm_min = 0;
  timeinfor.tm_sec = 0;

  rawtime = mktime(&timeinfor);

  dt.st_time = timeinfor;
  dt.time = rawtime;

  free(month);
  free(day);
  free(year);

  return dt;
}


void sub_str(char *source, char *dest, int start_index, int size){
  int index = start_index;
  while (index < start_index + size) {
    dest[strlen(dest)] = source[index];
    ++index;
  }
}