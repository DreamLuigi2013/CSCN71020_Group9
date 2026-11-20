#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "main.h"

#include "triangle.h"
#include "triangleSolver.h"

#include "rectangle.h"
#include "rectangleSolver.h"

#define MIN_SHAPE_MENU_VALUE 0
#define MAX_SHAPE_MENU_VALUE 2

// ====================================== DISPLAY FUNCTIONS =======================================
void printWelcome() {
	printf_s("\n");
	printf_s("\t\t\t\t\t__________                            /\\\n");
	printf_s("\t\t\t\t\t|        |        Welcome to         /  \\\n");
	printf_s("\t\t\t\t\t|________|   The Polygon Checker!   /____\\\n");
	printf_s("\n");
}

// ===================== MENU INPUT GATHERING AND DISPLAY =====================
void printShapeMenu() {
	printf_s("Shape Menu:\n");
	printf_s("0. Exit\n");
	printf_s("1. Triangle\n");
	printf_s("2. Rectangle\n"); // Will change to quadrilateral later
}

int* getShapeMenuInput() {
	int menuChoice = -1;
	bool valid;
	int scanfValue;
	char invalidChar;

	do {
		valid = false;

		printf_s("Enter a number: ");
		scanfValue = scanf_s("%d", &menuChoice);

		if (scanfValue == 0) {
			printf("Error, input invalid. Input must be an integer.\n\n");

			while ((invalidChar = getchar()) != '\n' && invalidChar != EOF);
			continue;
		}

		if (MIN_SHAPE_MENU_VALUE > menuChoice || menuChoice > MAX_SHAPE_MENU_VALUE) {
			printf("Error, input must be between %d and %d.\n\n", MIN_SHAPE_MENU_VALUE, MAX_SHAPE_MENU_VALUE);

			menuChoice = -1;
			continue;
		}

		valid = true;
	} while (!valid);

	return (int*) &menuChoice;
}


// ========================== TRIANGLE ANGLE DISPLAY ==========================
void printTriangleAngles(double* angles) {
	printf("\nThe angles of the inputted triangle:\n");

	printf("Angle 1: %lf\n", angles[0]);
	printf("Angle 2: %lf\n", angles[1]);
	printf("Angle 3: %lf\n", angles[2]);
}

// ===================================== MENU DEPENDANT LOGIC =====================================
void exitMenuAction(bool* continueProgram) {
	*continueProgram = false;
}

void triangleMenuAction() {
	printf_s("Triangle selected.\n\n");

	double triangleSidesArr[3] = { 0, 0, 0 };
	double* triangleSides = getTriangleSides(triangleSidesArr);

	char* triangleSidesResult = analyzeTriangle(triangleSides[0], triangleSides[1], triangleSides[2]);

	printf_s("%s\n", triangleSidesResult);

	if (strcmp(triangleSidesResult, "Not a triangle") != 0) {
		double triangleAnglesArr[3] = { 0,0,0 };
		double* triangleAngles = triangleAnglesArr;

		triangleAngleFinder(triangleSides[0], triangleSides[1], triangleSides[2], triangleAngles);
		printTriangleAngles(triangleAngles);
	}
}

void quadrilateralMenuAction() {
	printf_s("Quadrilateral Selected.\n\n");

	double rectanglePointsArr[4][2] =
	{
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 }
	
	};

	double* rectanglePoints = pointsCoordinates(rectanglePointsArr);


	// TEMP ======================
	// Displays the filled rectangle point array
	int X = 0;
	int Y = 1;

	printf("\n{\n");
	for (int point = 0; point < 4; point++) {
		printf("    {%.2lf, %.2lf}%s\n", rectanglePoints[point * 2 + X], rectanglePoints[point * 2 + Y], (point != 3) ? ", " : "");
	}
	printf("}\n");
	// TEMP ======================
}

// ============================================= MAIN =============================================
int main() {
	bool continueProgram = true;
	int* shapeChoicePtr;
	int shapeChoice;
	
	while (continueProgram) {
		printWelcome();

		printShapeMenu();
		shapeChoicePtr = getShapeMenuInput();
		shapeChoice = *shapeChoicePtr;

		switch (shapeChoice) {
			case 0:
				exitMenuAction(&continueProgram);
				break;
			case 1:
				triangleMenuAction();
				break;
			case 2:
				quadrilateralMenuAction();
				break;
			default:
				printf_s("Invalid value entered.\n");
				break;
		}
	}

	printf("\n\n");
	return 0;
}