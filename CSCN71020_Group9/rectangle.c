#include<stdio.h>
#include<stdbool.h>

#include "rectangle.h"

double* pointsCoordinates(double* points) {
	double point = 0;
	int check;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 2; j++) {
			if (j == 0) {
				printf("Please enter your x coordinate for point %d: ", i + 1);

				while (scanf_s("%lf", &point) != 1) {
					printf("Invalid Input! Please try again.\n");

					printf("Please enter your x coordinate for point %d: ", i + 1);

					while ((check = getchar()) != '\n' && check != EOF);
				}
				*(points + (i * 2) + j) = point;
			}
			else {
				printf("Please enter your y coordinate for point %d: ", i + 1);

				while (scanf_s("%lf", &point) != 1) {
					printf("Invalid Input! Please try again.\n");

					printf("Please enter your y coordinate for point %d: ", i + 1);

					while ((check = getchar()) != '\n' && check != EOF);
				}
				*(points + (i * 2) + j) = point;
			}
		}
	}

	return points;
}

/*
#define X_OFFSET 0
#define Y_OFFSET 1
#define SIZE_OF_POINT 2

double* pointsCoordinates(double* points) {
	double x_val = 0;
	double y_val = 0;
	int invalidChar;

	for (int r = 0; r < 4; r++) {
		bool valid;
		int scanf_val;

		// X VALUE
		do {
			valid = false;

			printf("Please enter your x coordinate for point %d: ", r + 1);
			scanf_val = scanf_s("%lf", &x_val);

			if (scanf_val != 1) {
				printf("Error! Invalid Input! Input must be a nunumber. Please try again.\n\n");

				while ((invalidChar = getchar()) != '\n' && invalidChar != EOF);
				continue;
			}
			printf("\n");

			valid = true;
		} while (!valid);

		points[(r * SIZE_OF_POINT) + X_OFFSET] = x_val;
		
		// Y VALUE
		do {
			valid = false;

			printf("Please enter your y coordinate for point %d: ", r + 1);
			scanf_val = scanf_s("%lf", &y_val);

			if (scanf_val != 1) {
				printf("Error! Invalid Input! Input must be a nunumber. Please try again.\n\n");

				while ((invalidChar = getchar()) != '\n' && invalidChar != EOF);
				continue;
			}
			printf("\n");

			valid = true;
		} while (!valid);

		points[(r * SIZE_OF_POINT) + Y_OFFSET] = y_val;
			
	}
	return points;
}
*/