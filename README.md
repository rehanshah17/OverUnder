# VEX VRC Robotics Project

This repository contains the code for our VEX VRC robotics team, written in C++. The project includes advanced control mechanisms such as full PID control, joystick curves, and slew constants, which significantly enhance the robot's performance in both autonomous and teleoperated modes.

## Features

- **PID Control:** Implemented Proportional-Integral-Derivative (PID) control for precise motor movement. This has led to a 93% improvement in efficiency during our autonomous routine.
- **Joystick Curves:** Customized joystick input curves for smoother and more responsive control.
- **Slew Rate Control:** Managed motor acceleration and deceleration through slew rate constants to prevent sudden jerks and ensure smoother movements.

## Code Structure

- `src/`: Contains all the C++ source files.
- `include/`: Header files and constants used across the project.
- `main.cpp`: The main file that initializes the robot and runs the control loops.

### Installation

1. Clone this repository:
    ```bash
    git clone https://github.com/yourusername/vex-vrc-project.git
    ```
2. Open the project in VEXcode V5.
3. Compile and deploy the code to the VEX V5 Robot Brain.

### Usage

- **Autonomous Mode:** The robot executes the pre-programmed routine with precise movements thanks to PID control.
- **Driver Control Mode:** Experience smooth and responsive control using customized joystick curves.

## Acknowledgments

Special thanks to our robotics team for their dedication and hard work. The implementation of PID control was a team effort and has drastically improved our performance on the field.

