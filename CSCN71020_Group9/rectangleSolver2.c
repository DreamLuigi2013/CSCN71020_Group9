#define _USE_MATH_DEFINES

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "rectangleSolver.h"

#define SIDE_LEN_1 0
#define SIDE_LEN_2 1
#define SIDE_LEN_3 2

double* findTriangleLengthsFromRectanglePoints(double* points) {
	static double triangleSideLengthsArr[6] = { 0 };

	if (points == NULL) {
		return triangleSideLengthsArr;
	}

	// Calculate side lengths for two triangles formed by the 4 points (x1,y1)..(x4,y4)
	double x1 = points[0], y1 = points[1];
	double x2 = points[2], y2 = points[3];
	double x3 = points[4], y3 = points[5];
	double x4 = points[6], y4 = points[7];

	// Triangle 1: P1, P2, P3
	triangleSideLengthsArr[0] = hypot(x2 - x1, y2 - y1);
	triangleSideLengthsArr[1] = hypot(x3 - x2, y3 - y2);
	triangleSideLengthsArr[2] = hypot(x3 - x1, y3 - y1);

	// Triangle 2: P1, P3, P4
	triangleSideLengthsArr[3] = hypot(x3 - x1, y3 - y1);
	triangleSideLengthsArr[4] = hypot(x4 - x3, y4 - y3);
	triangleSideLengthsArr[5] = hypot(x4 - x1, y4 - y1);

	return triangleSideLengthsArr;
}

double findHypotenuse(double s1, double s2, double s3) {
	double max = s1;

	if (s2 > max) {
		max = s2;
	}
	if (s3 > max) {
		max = s3;
	}

	return max;
}

bool isARectangle(double* rectangleTriangleSideLengths) {
	if (rectangleTriangleSideLengths == NULL) {
		return false;
	}

	const double epsilon = 0.01;
	int validTriangles = 0;

	for (int tri = 0; tri < 2; tri++) {
		double s1 = rectangleTriangleSideLengths[tri * 3 + SIDE_LEN_1];
		double s2 = rectangleTriangleSideLengths[tri * 3 + SIDE_LEN_2];
		double s3 = rectangleTriangleSideLengths[tri * 3 + SIDE_LEN_3];

		if (s1 <= 0.0 || s2 <= 0.0 || s3 <= 0.0) {
			return false;
		}

		double hypo = findHypotenuse(s1, s2, s3);
		double sumOfSquares = (s1 * s1) + (s2 * s2) + (s3 * s3);
		double legsSquaredSum = sumOfSquares - (hypo * hypo);

		if (fabs(legsSquaredSum - (hypo * hypo)) <= epsilon) {
			validTriangles++;
		}
	}

	return validTriangles == 2;
}