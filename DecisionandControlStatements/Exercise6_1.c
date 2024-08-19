// gcc .\Exercise6_1.c -o .\bin\Exercise6_1.exe
#include <stdio.h>
#include <math.h>

char line[100];	/*input line*/
float distance;	/*actual distance of two points*/

struct Point {
	int x;
	int y;
}; /*stuct to hold x and y values*/

int main() {
	struct Point a, b;

	printf("Enter an x and y value for Point a: ");
	fgets(line, sizeof(line), stdin);
	sscanf_s(line, "%d %d", &a.x, &a.y);

	printf("Enter an x and y value for Point b: ");
	fgets(line, sizeof(line), stdin);
	sscanf_s(line, "%d %d", &b.x, &b.y);

	int change_in_x_square = pow(abs(b.x - a.x), 2);
	int change_in_y_square = pow(abs(b.y - a.y), 2);

	distance = sqrt( change_in_x_square + change_in_y_square);

	printf("Distance between these two points: %f", distance);
	return 0;
}