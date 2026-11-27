#define _USE_MATH_DEFINES

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "rectangleSolver.h"

#define SIDE_LEN_1 0
#define SIDE_LEN_2 1
#define SIDE_LEN_3 2

double* findTriangleLengthsFromRectanglePoints(double* points) {
	double triangleSideLengthsArr[2][3] =
	{
		{0,0,0},
		{0,0,0}
	};
	double* triangleSideLengths = triangleSideLengthsArr;

	return triangleSideLengths;
}

double findHypotenuse(double s1, double s2, double s3) {
	double sidesArr[3] = {s1, s2, s3};
	double* sides = sidesArr;

	double max = sides[0];
	
	for (int i = 0; i < 3; i++) {
		if (max < sides[i]) max = sides[i];
	}

	return max;
}

bool isARectangle(double* rectangleTriangleSideLengths) {
	double s1;
	double s2;
	double s3;
	double hypo;
	bool isRectangle = false;

	for (int tri = 0; tri < 2; tri++) {
		s1 = rectangleTriangleSideLengths[tri * 3 + SIDE_LEN_1];
		s2 = rectangleTriangleSideLengths[tri * 3 + SIDE_LEN_2];
		s3 = rectangleTriangleSideLengths[tri * 3 + SIDE_LEN_3];

		hypo = findHypotenuse(s1, s2, s3);

	}

	return isRectangle;
}