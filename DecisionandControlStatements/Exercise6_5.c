// gcc .\Exercise6_5.c -o .\bin\Exercise6_5.exe
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

char line[100];
bool isLeapYear;
int year;

int main() {

	while (1)
	{
		printf("Enter a year (will show if a leap year): ");
		fgets(line, sizeof(line), stdin);
		sscanf_s(line, "%d", &year);

		if (year == -1) return 0;
		isLeapYear = false;

		if (year % 4 == 0)
		{
			isLeapYear = true;
		}
		else if (year % 100 == 0 && year % 400 != 0)
		{
			isLeapYear = false;
		}

		printf("Year %d is ", year);
		if (isLeapYear) printf("a leap year.\n");
		if (!isLeapYear) printf("not a leap year.\n");
	}

	return 0;
}

