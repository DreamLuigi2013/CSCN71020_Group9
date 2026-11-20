#pragma once

#ifdef __cplusplus
extern "C" {
#endif

void printWelcome();

void printShapeMenu();
int* getShapeMenuInput();

void printTriangleAngles(double* angles);

void exitMenuAction(bool* continueProgram);
void triangleMenuAction();
void quadrilateralMenuAction();

#ifdef __cplusplus
}
#endif