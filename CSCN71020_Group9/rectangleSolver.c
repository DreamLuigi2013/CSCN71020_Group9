#include <stdio.h>
#include <math.h>


void findTriangleLengthsFromRectanglePoints(double points[4][2])
{

	double Triangle1[3];
	double Triangle2[3];
	double Triangle3[3];

	//This finds AB, BC, CA
	for (int i = 0; i < 3;i++)
	{
		int nextPoint = (i + 1) % 3;
		int x1, x2, y1, y2;

		x1 = points[i][0];
		y1 = points[i][1];
		printf("test x1 = %d \n", x1);
		printf("test y1 = %d \n", y1);

		x2 = points[nextPoint][0];
		y2 = points[nextPoint][1];
		printf("test x2 = %d \n", x2);
		printf("test y2 = %d \n", y2);



		Triangle1[i] = sqrt((pow((x2 - x1), 2) + pow((y2 - y1), 2)));
		printf("%f \n", Triangle1[i]);

	}
	printf("This is triangle 1\n\n");

	//This finds AB, BC, CA
	for (int i = 0; i < 3;i++)
	{
		int order[] = { 0, 1, 3, 0 };

		int currentPoint = order[i]; // 0 > 1 > 3 > 0
		int nextPoint = order[i + 1]; // 1 > 3 > 0 > 0
		int x1, x2, y1, y2;

		x1 = points[currentPoint][0];
		y1 = points[currentPoint][1];
		printf("test x1 = %d \n", x1);
		printf("test y1 = %d \n", y1);


		x2 = points[nextPoint][0];
		y2 = points[nextPoint][1];
		printf("test x2 = %d \n", x2);
		printf("test y2 = %d \n", y2);



		Triangle2[i] = sqrt((pow((x2 - x1), 2) + pow((y2 - y1), 2)));
		printf("%f \n", Triangle2[i]);

	}
	printf("This is triangle 2\n\n");


	for (int i = 0; i < 3;i++)
	{
		int order[] = { 0, 2, 3, 0 };

		int currentPoint = order[i]; // 0 > 2 > 3 > 0
		int nextPoint = order[i + 1]; // 2 > 3 > 0 > 0
		int x1, x2, y1, y2;

		x1 = points[currentPoint][0];
		y1 = points[currentPoint][1];
		printf("test x1 = %d \n", x1);
		printf("test y1 = %d \n", y1);


		x2 = points[nextPoint][0];
		y2 = points[nextPoint][1];
		printf("test x2 = %d \n", x2);
		printf("test y2 = %d \n", y2);



		Triangle3[i] = sqrt((pow((x2 - x1), 2) + pow((y2 - y1), 2)));
		printf("%f \n", Triangle3[i]);

	}
	printf("This is triangle 3\n\n");

	return 0;
}