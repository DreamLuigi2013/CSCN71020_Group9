#include<stdio.h>
#include<stdbool.h>

#include "rectangle.h"

void pointsCoordinates(double* coordinates) {
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
				*(coordinates +(i * 2) + j) = point;
			}
			else {
				printf("Please enter your y coordinate for point %d: ", i + 1);

				while (scanf_s("%lf", &point) != 1) {
					printf("Invalid Input! Please try again.\n");

					printf("Please enter your y coordinate for point %d: ", i + 1);

					while ((check = getchar()) != '\n' && check != EOF);
				}
				*(coordinates + (i * 2) + j) = point;
			}
		}
	}
	
}