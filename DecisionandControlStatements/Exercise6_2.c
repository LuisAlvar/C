// gcc .\Exercise6_2.c -o .\bin\Exercise6_2.exe
#include <stdio.h>
#include <math.h>

char line[100];
int grade_entered;

struct Grade {
	char letter;
	int lower_range;
	int high_range;
};

struct Modifer {
	char sign;
	int lower_bound;
	int upper_bound;
};

int main() {
	
	struct Grade gradeTable[5];
	struct Modifer modifers[3];

	gradeTable[0].letter = 'A';
	gradeTable[0].lower_range = 91;
	gradeTable[0].high_range = 100;
	gradeTable[1].letter = 'B';
	gradeTable[1].lower_range = 81;
	gradeTable[1].high_range = 90;
	gradeTable[2].letter = 'C';
	gradeTable[2].lower_range = 71;
	gradeTable[2].high_range = 80;
	gradeTable[3].letter = 'D';
	gradeTable[3].lower_range = 61;
	gradeTable[3].high_range = 70;
	gradeTable[4].letter = 'F';
	gradeTable[4].lower_range = 0;
	gradeTable[4].high_range = 61;

	modifers[0].sign = '-';
	modifers[0].lower_bound = 1;
	modifers[0].upper_bound = 3;
	modifers[1].sign = ' ';
	modifers[1].lower_bound = 4;
	modifers[1].upper_bound = 7;
	modifers[2].sign = '+';
	modifers[2].lower_bound = 8;
	modifers[2].upper_bound = 9;

	while (1) {

		printf("Enter a numeric grade (exit enter -1): ");
		fgets(line, sizeof(line), stdin);
		sscanf_s(line, "%d", &grade_entered);

		if (grade_entered == -1) break;

		char cal_letter = 'A';
		int ones = 0;
		char modifier = ' ';

		for (int i = 0; i < 5; i++)
		{
			if (gradeTable[i].lower_range <= grade_entered 
				&& grade_entered <= gradeTable[i].high_range)
			{
				cal_letter = gradeTable[i].letter;
				ones = grade_entered % (gradeTable[i].lower_range - 1);
				break;
			}
		}

		if (cal_letter != 'F')
		{
			for (int i = 0; i < 3; i++)
			{
				if (ones <= modifers[i].upper_bound)
				{
					modifier = modifers[i].sign;
					break;
				}
			}
		}

		if (ones == 10)
		{
			modifier = '+';
		}

		printf("This is your letter grade: %c%c %d\n\n", cal_letter, modifier, ones);
	}


	return 0;
}