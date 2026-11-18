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

double* triangleAngleFinder(double side1, double side2, double side3) {
	// Make empty arrray for the angles
	double anglesArr[3] = { 0,0,0 };

	// c^2 = a^2 + b^2 - 2ab*cos(C)
	// C = arccos( (a^2 + b^2 - c^2) / (2ab) )

	// a^2 = b^2 + c^2 - 2bc*cos(A)
	// A = arccos( (b^2 + c^2 - a^2) / (2bc) )

	// b^2 = a^2 + c^2 - 2ac*cos(B)
	// B = arccos( (a^2 + c^2 - b^2) / (2ac) )

	// 180/pi = math to convert radians into angles
	double angle1 = acos((side2 * side2 + side3 * side3 - side1 * side1) / (2.0 * side2 * side3)) * (180.0 / M_PI);
	double angle2 = acos((side1 * side1 + side3 * side3 - side2 * side2) / (2.0 * side1 * side3)) * (180.0 / M_PI);
	double angle3 = 180.0 - angle1 - angle2;

	// Set angles to the memory address of the angles array
	double* angles = anglesArr;
	
	// Fill the "array"
	angles[0] = angle1;
	angles[1] = angle2;
	angles[2] = angle3;
	
	// Return the memory address so it can still be use
	// and persists after function call
	return angles;
}
