#include <stdio.h>
#include <stdbool.h>

#include "main.h"
#include "triangleSolver.h"

void printWelcome() {
	printf_s("\n");
	printf_s(" **********************\n");
	printf_s("**     Welcome to     **\n");
	printf_s("**   Polygon Checker  **\n");
	printf_s(" **********************\n");
}

int printShapeMenu() {
	printf_s("1. Triangle\n");
	printf_s("0. Exit\n");

	int shapeChoice;

	printf_s("Enter number: ");
	scanf_s("%1o", &shapeChoice);

	return shapeChoice;
}

double* getTriangleSides(double* triangleSides) {
	for (int i = 0; i < 3; i++) {
		printf_s("Enter the length of the triangle\'s side %d: ", i + 1);
		scanf_s("%lf", &triangleSides[i]);
	}
	return triangleSides;
}

int side = 0;

int main() {
	bool continueProgram = true;
	
	while (continueProgram) {
		printWelcome();

		int shapeChoice = printShapeMenu();

		switch (shapeChoice) {
			case 1:
				printf_s("Triangle selected.\n\n");

				double triangleSides[3] = { 0, 0, 0 };
				double* triangleSidesPtr = getTriangleSides(triangleSides);

				//printf_s("! %d\n", triangleSidesPtr[0]);

				char* result = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);

				printf_s("%s\n", result);
				break;

			case 2:
				printf("Quatralateral Selected.\n");

				double x1 = 0, x2 = 0, x3 = 0, x4 = 0;
				double y1 = 0, y2 = 0, y3 = 0, y4 = 0;

				double coordinates[4][2] = 
					{ 
						{x1, y1},
						{x2, y2},
						{x3, y3},
						{x4, y4}
					};


				

			case 0:
				continueProgram = false;
				break;
			default:
				printf_s("Invalid value entered.\n");
				break;
		}
	}


	return 0;
}