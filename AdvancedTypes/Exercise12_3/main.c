#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 1

struct AirlineReservation {
  char flight_number[7];
  char origin_airport_code[4];
  char destination_airport_code[4];
  time_t departure_time;
  time_t arrival_time;
};

int main(void) {

  struct tm set_time_dep = {0};
  set_time_dep.tm_year = 2024 - 1900; // Year (since 1900)
  set_time_dep.tm_mon = 8;   // September (0-based)
  set_time_dep.tm_mday = 25;  // Day of the month
  set_time_dep.tm_hour = 15;  // Hour (24-hour format)
  set_time_dep.tm_min = 30;  // Minutes
  set_time_dep.tm_sec = 0;   // Seconds

  struct tm set_time_arr = {0};
  set_time_arr.tm_year = 2024 - 1900; // Year (since 1900)
  set_time_arr.tm_mon = 8;   // September (0-based)
  set_time_arr.tm_mday = 25;  // Day of the month
  set_time_arr.tm_hour = 16;  // Hour (24-hour format)
  set_time_arr.tm_min = 45;  // Minutes
  set_time_arr.tm_sec = 0;   // Seconds

  struct AirlineReservation resev_list[MAX_ENTRIES] = {
    {"AF296Q","JFK","LAX", mktime(&set_time_dep), mktime(&set_time_arr)}
  };


  char time_dept[30];
  char time_arr[30];

  for(int i = 0; i < MAX_ENTRIES; ++i) 
  {
    strftime(time_dept, sizeof(time_dept),"%H:%M:%S", localtime(&resev_list[i].departure_time));
    strftime(time_arr, sizeof(time_arr),"%H:%M:%S", localtime(&resev_list[i].arrival_time));

    printf("%s flight %s to %s | Departure time ", resev_list[i].origin_airport_code, resev_list[i].flight_number, resev_list[i].destination_airport_code);
    printf("%s | ETA %.2lf hours\n", time_dept, difftime(resev_list[i].arrival_time, resev_list[i].departure_time) * (1/60.0) * (1/60.0));
  }
  




  return 0;
}
