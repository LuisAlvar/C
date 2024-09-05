#include <stdio.h>
#include <string.h>

#define MAX_ENTRIES 3

struct mailing {
  char name[60];      /* Last name, first name */
  char address1[60];  /* Two lines of street address */
  char address2[60];
  char city[40];
  char state[3];      /* Two character abbreviation */
  char zip[10];       /* Numeric zip code */
};


int main(void) {

  struct mailing list[MAX_ENTRIES] = {
    {"Luis Aguilar", "1234 Orange Grove Blvd.", "", "Los Angeles","CA","12345"},
    {"Monica Smith", "9876 13th Street", "Bld 3 Apt 345", "Los Angeles", "CA","98765"},
    {"Elizabeth Gomez", "5673 Ash Grove Blvd.", "Apt 2", "Los Angeles", "CA","45232"}
  };
  
  for (int i = 0; i < MAX_ENTRIES; i++)
  {
    printf("Name: %s\n", list[i].name);
    printf("Address: %s", list[i].address1);
    if (strlen(list[i].address2) != 0)
    {
      printf(" %s", list[i].address2);
    }
    printf(" %s, %s %s\n\n", list[i].city, list[i].state, list[i].zip);
  }
  

}
