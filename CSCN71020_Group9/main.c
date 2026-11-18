#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "main.h"

#include "triangle.h"
#include "triangleSolver.h"

#include "rectangle.h"
#include "rectangleSolver.h"

// ====================================== DISPLAY FUNCTIONS =======================================
void printWelcome() {
	printf_s("\n");
	printf_s("\t\t\t\t\t__________                            /\\\n");
	printf_s("\t\t\t\t\t|        |        Welcome to         /  \\\n");
	printf_s("\t\t\t\t\t|________|   The Polygon Checker!   /____\\\n");
	printf_s("\n");
}

// ===================== MENU INPUT GATHERING AND DISPLAY =====================
int printShapeMenu() {
	int shapeChoice = -1;

	printf_s("Shape Menu:\n");
	printf_s("0. Exit\n");
	printf_s("1. Triangle\n");
	printf_s("2. Rectangle\n"); // Will change to quadrilateral later

	printf_s("Enter number: ");
	scanf_s("%1d", &shapeChoice);

	return shapeChoice;
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

	if (!(strcmp(triangleSidesResult, "Not a triangle") == 0)) {
		double* triangleAngles = triangleAngleFinder(triangleSides[0], triangleSides[1], triangleSides[2]);
		printTriangleAngles(triangleAngles);
	}
}

void quadrilateralMenuAction() {
	printf_s("Quatralateral Selected.\n");

	double coordinates[4][2] =
	{
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 }
	};

	// Add quadrilateral input function

	pointsCoordinates(coordinates);
}

// ============================================= MAIN =============================================
int main() {
	bool continueProgram = true;
	int side = 0;
	int shapeChoice;
	
	while (continueProgram) {
		printWelcome();

		shapeChoice = printShapeMenu();

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