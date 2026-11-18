#pragma once

#ifdef __cplusplus
extern "C" {
#endif

void printWelcome();
int printShapeMenu();

void exitMenuAction(bool* continueProgram);
void triangleMenuAction();
void quadrilateralMenuAction();

#ifdef __cplusplus
}
#endif