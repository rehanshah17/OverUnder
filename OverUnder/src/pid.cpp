#include "main.h"
#define DRIVE_KP 0.2; 
#define DRIVE_KI 0.0; 
#define DRIVE_KD 0.1;

// THRESHOLD CONSTANTS
double translate_threshold = 300;
double inertial_threshold = 5;
double power_threshold = 35;

// DRIVE PID CONSTANTS
double drive_kP = DRIVE_KP;
double drive_kI = DRIVE_KI;
double drive_kD = DRIVE_KD;

//inertial constants
double turn_kP_inert = 0.19;
double turn_kI_inert = 0.0;
double turn_kD_inert = 0.1;

// DRIVING STRAIGHT WITH PID
void pidTranslate(double units) { 
  double direction = abs(units) / units;

  double lastErr = 0.0;
  double err = 0.0;

  double proportion = 0.0;
  double integral = 0.0;
  double derivative = 0.0;

  resetMotorEncoders();

  while (abs(getAvgEncoder()) < (abs(units) - translate_threshold)) {
    err = units - getAvgEncoder();

    proportion = err;
    integral += err;
    derivative = err - lastErr;

    double power = (proportion * drive_kP) + (integral * drive_kI) +
                   (derivative * drive_kD);
    setDrive(power * direction, power * direction);

    if (abs(power) < abs(power_threshold))
      break;
    pros::lcd::set_text(2, std::to_string(power));

    lastErr = err;
    pros::delay(10);
  }

  setDrive(0, 0);
  pros::delay(10);
}

void pidTurnInertial(double units) {
  double direction = abs(units) / units;

  double lastErr = 0.0;
  double err = 100.0;

  double proportion = 0.0;
  double integral = 0.0;
  double derivative = 0.0;

  while (imu.is_calibrating()) {
    pros::delay(10);
  }
  imu.tare_rotation();

  double sensorValue = imu.get_rotation();

  
  
  while (fabs(err) > .5) {

    double sensorValue = imu.get_rotation();
    pros::lcd::set_text(2, std::to_string(sensorValue));
    pros::lcd::set_text(3, std::to_string(sensorValue));
    // pros::lcd::set_text(4, "in loop");
    pros::lcd::set_text(5, std::to_string(units));
    

    
    err = units - sensorValue;

    proportion = err;
    integral += err;
    derivative = err - lastErr;

    double power = (proportion * turn_kP_inert) + (integral * turn_kI_inert) +
                   (derivative * turn_kD_inert);

    power *= 15;

    if(abs(power) < 30)
    {
      power = 30*(abs(power)/power);
    }

    pros::lcd::set_text(5, std::to_string(power));

    setDrive(power, -power);

    // if (abs(power) < abs(inertial_threshold))
    //   break;

    lastErr = err;
    pros::delay(10);
    integral = integral*.95;
  }

  setDrive(0, 0);
  pros::delay(150);
}

void setPid(double kP, double kI, double kD) {
  drive_kP = kP;
  drive_kI = kI;
  drive_kD = kD;
}

void resetPid() {
  drive_kP = DRIVE_KP;
  drive_kI = DRIVE_KI;
  drive_kD = DRIVE_KD;
}