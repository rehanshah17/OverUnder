#include "main.h"

// 1: Ports    2: Gearset (Red 36, Green 18, Blue6) 3: Asks if reversed or not (true if reversed)   4. Encode units to degrees
pros::Motor frontRight(1, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor frontLeft(10, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_DEGREES);

pros::Motor bottomLeft(8, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor bottomRight(3, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_DEGREES);

pros::Motor topLeft(9, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor topRight(2, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_DEGREES);

pros::Motor leftCata(20, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor rightCata(11, pros::E_MOTOR_GEARSET_36, true, pros::E_MOTOR_ENCODER_DEGREES);

//Pneumatics
pros::ADIDigitalOut wings('A',false);
pros::ADIDigitalOut trap('D', true);

//Sensors
pros::Imu imu(15);

//CONTROLLER
pros::Controller controller(pros::E_CONTROLLER_MASTER);

bool wingsOn = false;
bool trapOn = false;
bool cataOn = false;

