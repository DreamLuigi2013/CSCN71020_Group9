#include <stdio.h>
#include <stdbool.h>

#include "main.h"

#include "triangle.h"
#include "triangleSolver.h"

#include "rectangle.h"
#include "rectangleSolver.h"

// ============================================= MENU =============================================
void exitMenuAction(bool* continueProgram) {
	*continueProgram = false;
}

void triangleMenuAction() {
	printf_s("Triangle selected.\n\n");

	double triangleSidesArr[3] = { 0, 0, 0 };
	double* triangleSides = getTriangleSides(triangleSidesArr);

	char* result = analyzeTriangle(triangleSides[0], triangleSides[1], triangleSides[2]);

	printf_s("%s\n", result);
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
		printf_s("\n");
		printf_s("\t\t\t\t\t__________                            /\\\n");
		printf_s("\t\t\t\t\t|        |        Welcome to         /  \\\n");
		printf_s("\t\t\t\t\t|________|   The Polygon Checker!   /____\\\n");
		printf_s("\n");

		shapeChoice = -1;

		printf_s("Shape Menu:\n");
		printf_s("0. Exit\n");
		printf_s("1. Triangle\n");
		printf_s("2. Rectangle\n"); // Will change to quadrilateral later

		printf_s("Enter number: ");
		scanf_s("%1d", &shapeChoice);

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