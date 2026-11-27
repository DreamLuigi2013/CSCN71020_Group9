#define _USE_MATH_DEFINES

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "rectangleSolver.h"

#define SIDE_LEN_1 0
#define SIDE_LEN_2 1
#define SIDE_LEN_3 2
#define NUM_OF_TRI_SIDES 3
#define NUM_OF_TRIANGLES 3

#define X_COORD 0
#define Y_COORD 1
#define SIZE_OF_POINT 2

double* findTriangleLengthsFromRectanglePoints(double* points) {
	double triangle1[NUM_OF_TRI_SIDES];
	double triangle2[NUM_OF_TRI_SIDES];
	double triangle3[NUM_OF_TRI_SIDES];

	//This finds AB, BC, CA
	for (int i = 0; i < NUM_OF_TRI_SIDES; i++) {
		int nextPoint = (i + 1) % 3;

		int x1 = points[i * SIZE_OF_POINT + X_COORD];
		int y1 = points[i * SIZE_OF_POINT + Y_COORD];

		printf("test x1 = %d \n", x1);
		printf("test y1 = %d \n", y1);

		int x2 = points[nextPoint * SIZE_OF_POINT + X_COORD];
		int y2 = points[nextPoint * SIZE_OF_POINT + Y_COORD];

		printf("test x2 = %d \n", x2);
		printf("test y2 = %d \n", y2);


		// triangle 1 side i+1 length = sqrt( (x2 - x1)^2 + (y2 - y1)^2 )
		triangle1[i] = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
		printf("%f \n", triangle1[i]);

	}
	printf("This is triangle 1\n\n");

	//This finds AB, BC, CA
	for (int i = 0; i < 3;i++)
	{
		int order[] = { 0, 1, 3, 0 };

		int currentPoint = order[i]; // 0 > 1 > 3 > 0
		int nextPoint = order[i + 1]; // 1 > 3 > 0 > 0
		int x1, x2, y1, y2;

		x1 = points[currentPoint * SIZE_OF_POINT + X_COORD];
		y1 = points[currentPoint * SIZE_OF_POINT + Y_COORD];
		printf("test x1 = %d \n", x1);
		printf("test y1 = %d \n", y1);


		x2 = points[nextPoint * SIZE_OF_POINT + X_COORD];
		y2 = points[nextPoint * SIZE_OF_POINT + Y_COORD];
		printf("test x2 = %d \n", x2);
		printf("test y2 = %d \n", y2);



		Triangle2[i] = sqrt((pow((x2 - x1), 2) + pow((y2 - y1), 2)));
		printf("%f \n", Triangle2[i]);

	}
	printf("This is triangle 2\n\n");


	for (int i = 0; i < 3;i++)
	{
		int order[] = { 0, 2, 3, 0 };

		int currentPoint = order[i]; // 0 > 2 > 3 > 0
		int nextPoint = order[i + 1]; // 2 > 3 > 0 > 0
		int x1, x2, y1, y2;

		x1 = points[currentPoint][0];
		y1 = points[currentPoint][1];
		printf("test x1 = %d \n", x1);
		printf("test y1 = %d \n", y1);


		x2 = points[nextPoint][0];
		y2 = points[nextPoint][1];
		printf("test x2 = %d \n", x2);
		printf("test y2 = %d \n", y2);



		Triangle3[i] = sqrt((pow((x2 - x1), 2) + pow((y2 - y1), 2)));
		printf("%f \n", Triangle3[i]);

	}
	printf("This is triangle 3\n\n");

	return 0;
}