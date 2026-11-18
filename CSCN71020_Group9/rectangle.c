#include<stdio.h>
#include<stdbool.h>

#include "rectangle.h"

void pointsCoordinates(double* coordinates) {
	double point = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 2; j++) {
			
			
			if (j == 0) {
				printf("Please enter your x coordinate for point %d: ", i + 1);
				scanf_s("%lf", &point);
				*(coordinates +(i * 2) + j) = point;
			}
			else {
				printf("Please enter your y coordinate for point %d: ", i + 1);
				scanf_s("%lf", &point);
				*(coordinates + (i * 2) + j) = point;
			}
		}
	}
	// For checking if input entered (delete later).

	// int r = desired row (0,1,2,3)
	// int c = desired column (0,1)
	// To access points in a 2D array you are required to do *((coordinates + r) + c)

	for (int w = 0; w < 4; w++) {
		for (int k = 0; k < 2; k++) {
			if (k == 0) {
				printf("Point %d: x = %lf\n", w + 1, *(coordinates + (w * 2) + k));
			}
			else {
				printf("Point %d: y = %lf\n", w + 1, *(coordinates + (w * 2) + k));
			}
		}
	}
	
}