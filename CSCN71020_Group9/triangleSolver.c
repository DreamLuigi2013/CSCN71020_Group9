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
		result = "Isosceles triangle";
	}
	else if ((side1 + side2 > side3) && (side2 + side3 > side1) && (side3 + side1 > side2)) {
		result = "Scalene triangle";
	}
	else {
		result = "Not a triangle";
	}

	return result;
}

void AngleFinder(double side1, double side2, double side3) {
	
	// cos(a) = (b^2 + c^2 - a^2)/2bc
	// 180/pi = math to convert radians into angles

	double Angle1 = acos((side2 * side2 + side3 * side3 - side1 * side1) / (2.0 * side2 * side3)) * (180.0 / M_PI);
	double Angle2 = acos((side1 * side1 + side3 * side3 - side2 * side2) / (2.0 * side1 * side3)) * (180.0 / M_PI);
	double Angle3 = 180.0 - Angle1 - Angle2;

	// Prints angles matching to side lengths
	printf("This is the angle of the first side %.2lf", Angle1);
	printf("This is the angle of the second side %.2lf", Angle2);
	printf("This is the angle of the third side %.2lf", Angle3);

}