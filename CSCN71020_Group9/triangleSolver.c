#define _USE_MATH_DEFINES

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "triangleSolver.h"

char* analyzeTriangle(double side1, double side2, double side3) {
	char* result = "";

	if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
		result = "Not a triangle";
	}
	else if (side1 == side2 && side1 == side3) {
		result = "Equilateral Triangle";
	}
	else if ((side1 == side2 && side3 < (side1 + side2)) ||
		(side1 == side3 && side2 < (side1 + side3)) ||
		(side2 == side3 && side1 < (side2 + side3))) 
	{
		result = "Isosceles Triangle";
	}
	else if ((side1 + side2 > side3) && (side2 + side3 > side1) && (side3 + side1 > side2)) {
		result = "Scalene Triangle";
	}
	else {
		result = "Not a triangle";
	}

	return result;
}

double convertToDegrees(double rad) {
	return rad * (180.0 / M_PI);
}

double convertToRadians(double deg) {
	return deg * (M_PI / 180.0);
}

void triangleAngleFinder(double side1, double side2, double side3, double* angles) {
	// c^2 = a^2 + b^2 - 2ab*cos(C)
	// C = arccos( (a^2 + b^2 - c^2) / (2ab) )

	// a^2 = b^2 + c^2 - 2bc*cos(A)
	// A = arccos( (b^2 + c^2 - a^2) / (2bc) )

	// b^2 = a^2 + c^2 - 2ac*cos(B)
	// B = arccos( (a^2 + c^2 - b^2) / (2ac) )

	// 180/pi = math to convert radians into degrees
	angles[0] = convertToDegrees(acos((side2 * side2 + side3 * side3 - side1 * side1) / (2.0 * side2 * side3)));
	angles[1] = convertToDegrees(acos((side1 * side1 + side3 * side3 - side2 * side2) / (2.0 * side1 * side3)));
	angles[2] = 180.0 - angles[0] - angles[1];
}
