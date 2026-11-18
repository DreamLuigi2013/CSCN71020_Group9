#include <stdio.h>
#include <stdbool.h>

#include "main.h"
#include "triangleSolver.h"
#include "rectangle.h"

#define MIN_TRIANGLE_SIDE_LENGTH 0
#define MAX_TRIANGLE_SIDE_LENGTH 100000

// =========================================== TRIANGLE ===========================================
void getTriangleSideInput(double* out) {
	double value = 0.0;
	bool valid;
	int scanf_val;

	do {
		valid = false;
		scanf_val = scanf_s("%lf", &value);

		if (scanf_val == 0) {
			printf("Error, input invalid\n");
		}

		valid = true;
	} while (!valid);

	*out = value;
}

double* getTriangleSides(double* triangleSides) {
	printf_s("Enter triangle lengths:\n");

	for (int i = 0; i < 3; i++) {
		printf_s("Side %d: ", i + 1);

		getTriangleSideInput(&triangleSides[i]);
	}
	return triangleSides;
}

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