#include <stdio.h>
#include <stdlib.h>

#define MAX_SERIAL_TRANSMISSION_SIZE_BUFFER 960
#define SECONDS_IN_A_MINUTE 60
#define MINUTES_IN_A_HOUR 60
#define HOURS_IN_A_DAY 24

char line[100];

int main() {

  char send_buffer[MAX_SERIAL_TRANSMISSION_SIZE_BUFFER];
  int filesize_in_bytes;
  double completion_eta;

  printf("Enter file size: ");
  fgets(line, sizeof(line), stdin);
  sscanf(line, "%d", &filesize_in_bytes);

  int max_send_buffer_size_bytes_per_second =  sizeof(send_buffer);
  completion_eta = (filesize_in_bytes/max_send_buffer_size_bytes_per_second) * (1.0/SECONDS_IN_A_MINUTE) * (1.0/MINUTES_IN_A_HOUR) * (1.0/HOURS_IN_A_DAY);

  printf("Based on the limitation of our hardware, max transmission of 960 bytes per second is allowed.\n");
  printf("A file size of %d bytes will take %.2f days.\n", filesize_in_bytes, completion_eta);

  return 0;
}
