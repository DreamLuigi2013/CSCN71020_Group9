#include <stdio.h>
#include <stdbool.h>

#define MIN_TRIANGLE_SIDE_LENGTH 0
#define MAX_TRIANGLE_SIDE_LENGTH 100000

void getTriangleSideInput(double* out) {
	double value = 0.0;
	bool valid;
	int scanf_val;

	do {
		valid = false;
		scanf_val = scanf_s("%lf", &value);

		if (scanf_val == 0) {
			printf("Error, input invalid\n");
		}

		valid = true;
	} while (!valid);

	*out = value;
}

double* getTriangleSides(double* triangleSides) {
	printf_s("Enter triangle lengths:\n");

	for (int i = 0; i < 3; i++) {
		printf_s("Side %d: ", i + 1);

		getTriangleSideInput(&triangleSides[i]);
	}
	return triangleSides;
}