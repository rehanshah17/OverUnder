//hella drivey
#include "main.h"

void setDrive(int left, int right) {
  bottomLeft.move_voltage(left * 70);
  bottomRight.move_voltage(right * 70);
  //topLeft.move_voltage(left * 70);
  //topRight.move_voltage(right * 70);
  frontLeft.move_voltage(left * 70);
  frontRight.move_voltage(right * 70);
}
//Sanjit setMotors

void setMotors()
{
  double left = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
  double right = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);

  setDrive(left,right);
}

/*
//Shaunak setMotors
void setMotors()
{
  double power = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
  double direction = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
  int left = (power + direction);
  int right = (power - direction);

  setDrive(left,right);
}
*/



void toggleCata(){
  //r2 cata
  bool isR2pressed = controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R2);

  if(isR2pressed)
  {
    cataOn = !cataOn;
  }
  
  if(cataOn)
  {
    leftCata.move_voltage(12000);
    rightCata.move_voltage(12000);
  }
  else{
    leftCata.move_voltage(0);
    rightCata.move_voltage(0);
  }
  wings.set_value(wingsOn);
}


void setWings() {
  bool isL2Pressed = controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L2);

  if(isL2Pressed)
  {
    wingsOn = !wingsOn;
  }

  wings.set_value(wingsOn);
}

void setTrap() {
  bool isAPressed = controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A);

  if(isAPressed)
  {
    trapOn = !trapOn;
  }

  trap.set_value(trapOn);
}