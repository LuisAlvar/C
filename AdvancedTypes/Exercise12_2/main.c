#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 3
#define SECONDS_IN_MIN (1.0/60.0)

struct TimeDate {
  struct tm set_time;
  time_t raw_time;
};

int main(void) {
  
  struct TimeDate td1, td2;
  td1.set_time.tm_year = 2024 - 1900;
  td1.set_time.tm_mon =  9 - 1;
  td1.set_time.tm_mday = 4;
  td1.set_time.tm_hour = 14;
  td1.set_time.tm_min = 0;
  td1.set_time.tm_sec = 0;
  td1.raw_time = mktime(&td1.set_time);

  td2.set_time.tm_year = 2024 - 1900;
  td2.set_time.tm_mon =  9 - 1;
  td2.set_time.tm_mday = 4;
  td2.set_time.tm_hour = 23;
  td2.set_time.tm_min = 0;
  td2.set_time.tm_sec = 0;
  td2.raw_time = mktime(&td2.set_time);

  double timeDifference = difftime(td2.raw_time, td1.raw_time);
  printf("Time difference: %.2f minutes\n", timeDifference * SECONDS_IN_MIN);

  return 0;
}
