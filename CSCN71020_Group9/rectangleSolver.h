#pragma once

#ifdef __cplusplus
extern "C" {
#endif

double* findTriangleLengthsFromRectanglePoints(double* points);
double findHypotenuse(double s1, double s2, double s3);
bool isARectangle(double* rectangleTriangleSideLengths);

#ifdef __cplusplus
}
#endif