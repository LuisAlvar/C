#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

char line[100];

struct Employee {
	float total_hours;
	float hourly_wage;
	float hours_against_overtime;
	float weekly_payroll;
};

int main() {

	struct Employee main;
	float hours;
	float rate;

	printf("Enter total hours and hourly rate: ");
	fgets(line, sizeof(line), stdin);
	sscanf_s(line, "%f %f", &hours, &rate);

	main.total_hours = hours;
	main.hourly_wage = rate;
	main.hours_against_overtime = 0;
	main.weekly_payroll = 0;

	if (hours > 40) {
		main.hours_against_overtime = hours - 40;
	}
	else {
		main.hours_against_overtime = 0;
	}

	main.weekly_payroll = (main.hourly_wage * (main.total_hours - main.hours_against_overtime)) + (main.hours_against_overtime * (main.hourly_wage * 2));

	printf("This is your weekly payroll: %.2f", main.weekly_payroll);

	return 0;
}
