#pragma once

#ifdef __cplusplus
extern "C" {
#endif

char* analyzeTriangle(double side1, double side2, double side3);

double convertToDegrees(double rad);
double convertToRadians(double deg);

void triangleAngleFinder(double side1, double side2, double side3, double* angles);

#ifdef __cplusplus
}
#endif