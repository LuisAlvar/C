// gcc .\Exercises.c -o .\bin\Exercises.exe
#include <stdio.h>
#include <stdbool.h>

int main(void) {

	/*>>>>>>>>>>>>>>>>> Exercise 4-1 <<<<<<<<<<<<<<<<*/

	printf("Name: LuisAlvar\n");
	printf("Social Security Number: 123-44-5678\n");
	printf("Date of birth: 01/01/1024\n");

	/*>>>>>>>>>>>>>>>>> Exercise 4-2 <<<<<<<<<<<<<<<<*/

	int width = 5;
	int height = 7;
	bool last = false;

	for (int i = 0; i < 3; ++i)
	{
		if (i == 2)
		{
			last = true;
		}

		for (int j = 0; j < width; ++j)
		{
			printf("*");
		}
		printf("\n");

		if (!last)
		{
			int it = (height - 3) / 2;
			for (int r = 0; r < it; ++r)
			{
				printf("*\n");
			}
		}
	}

	/*>>>>>>>>>>>>>>>>> Exercise 4-3 <<<<<<<<<<<<<<<<*/
	float r_width = 6.8;
	float r_height = 2.3;

	float r_area = r_width * r_height;
	float r_perimeter = (r_width * 2) + (r_height * 2);

	printf("Area of a rectangle with width(%.2f) and height(%.2f): %.2f\n", r_width, r_height, r_area);
	printf("Perimeter of a rectangle with width(%.2f) and height(%.2f): %.2f\n", r_width, r_height, r_perimeter);

	/*>>>>>>>>>>>>>>>>> Exercise 4-5 <<<<<<<<<<<<<<<<*/
	printf("Deliberate mistake: %d\n", 3.14);
	printf("Deliberate mistake: %f\n", 4);
	printf("Deliberate mistake: %d\n", 'X');



	return 0;

}