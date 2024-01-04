#include "main.h"

void resetMotorEncoders();
double getRightEncoder();
double getLeftEncoder();
double getAvgEncoder();

void translate(int units, int voltage);
void turn(int units, int voltage);
void pointTurn(int units, int voltage);
void swingLeft(int units, int voltage);
void swingRight(int units, int voltage);

void toggleWings(bool val);
void toggleTrap(bool val);
