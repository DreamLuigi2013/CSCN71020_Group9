#include <stdio.h>
#include <stdbool.h>

#include "triangle.h"

#define MIN_SIDE_LENGTH 0.0
#define MAX_SIDE_LENGTH 100000.0

void getTriangleSideInput(double* out, int side_num) {
	double side = 0.0;
	bool valid;
	int scanf_val;
	char invalid_ch;

	do {
		valid = false;

		printf_s("Side %d: ", side_num);
		scanf_val = scanf_s("%lf", &side);

		if (scanf_val == 0) {
			printf("Error, input invalid. Input must be a decimal number.\n\n");

			while ((invalid_ch = getchar()) != '\n' && invalid_ch != EOF);
			continue;
		}

		if (MIN_SIDE_LENGTH > side || side > MAX_SIDE_LENGTH) {
			printf("Error, input must be between %.0lf and %.0lf.\n\n", MIN_SIDE_LENGTH, MAX_SIDE_LENGTH);

			side = 0.0;
			continue;
		}
		printf("\n");

		valid = true;
	} while (!valid);

	*out = side;
}

double* getTriangleSides(double* triangleSides) {
	printf_s("Enter triangle lengths:\n");

	for (int i = 0; i < 3; i++) {
		getTriangleSideInput(&triangleSides[i], i + 1);
	}
	return triangleSides;
}