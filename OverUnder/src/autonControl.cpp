#include "main.h"


//reset encoder
void resetMotorEncoders()
{
  bottomLeft.tare_position();
  bottomRight.tare_position();
  frontRight.tare_position();
  frontLeft.tare_position();
  topLeft.tare_position();
  topRight.tare_position(); 
}

double getRightEncoder(){
  return (fabs(bottomRight.get_position()) + fabs(frontRight.get_position()) + fabs(topRight.get_position()));
}

double getLeftEncoder(){
  return (fabs(bottomLeft.get_position()) + fabs(frontLeft.get_position()) + fabs(topLeft.get_position()));
}

double getAvgEncoder() {
  return (fabs(bottomRight.get_position()) + fabs(bottomLeft.get_position()) + fabs(topLeft.get_position()) + fabs(topRight.get_position()) + fabs(frontRight.get_position()) + fabs(frontLeft.get_position())) / 6;
}

void translate(int units, int voltage) {
   int direction = abs(units) / units;

   resetMotorEncoders();

   while(getAvgEncoder() < abs(units)) {
       setDrive(voltage * direction, voltage * direction);
       pros::delay(10);
   }

   setDrive(-10 * direction, -10 * direction);
   pros::delay(10);

   setDrive(0, 0);
}

void swingLeft(int units, int voltage) {
   resetMotorEncoders();

   while(getLeftEncoder() < abs(units)) {
       setDrive(voltage, 0);
       pros::delay(10);
   }

   setDrive(-10, 0);
   pros::delay(10);

   setDrive(0, 0);
}


void swingRight(int units, int voltage) {
   resetMotorEncoders();

   while(getRightEncoder() < abs(units)) {
       setDrive(0, voltage);
       pros::delay(10);
   }

   setDrive(0, -10);
   pros::delay(10);

   setDrive(0, 0);
}

// TURN W/O PID
void turn(int units, int voltage) {
  int direction = abs(units) / units;

  resetMotorEncoders();

  while (getRightEncoder() < abs(units)) {
    setDrive(0, voltage * direction);
    pros::delay(10);
  }

  setDrive(0, 0);
  pros::delay(100);
}

void pointTurn(int units, int voltage) {
  int direction = abs(units) / units;

  resetMotorEncoders();

  while (getRightEncoder() < abs(units)) {
    setDrive(-(voltage * direction), voltage * direction);
    pros::delay(10);
  }

  setDrive(0, 0);
  pros::delay(100);
}

void toggleWings(bool val)
{
  wings.set_value(val);
}
void toggleTrap(bool val)
{
  trap.set_value(!val);
}


