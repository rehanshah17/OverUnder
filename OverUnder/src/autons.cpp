#include "main.h"

//negative -> left
//positive -> right
//1290 = one tile
void autonClose(bool isBlue)
{
 if(!isBlue)//isRed
 {
  pidTranslate(1290*1.5);
	pros::delay(500);
	pidTurnInertial(90);
	toggleTrap(false);
	pros::delay(500);
	translate(900,75*80);
	pros::delay(750);
	toggleTrap(true);
	pros::delay(500);
	translate(-250,50*80);
	pros::delay(250);
	pidTurnInertial(-160);
	toggleTrap(false);
	toggleWings(true);
	pros::delay(500);
	pidTranslate(1400);
 }else{
   pidTranslate(1290*1.5);
	pros::delay(500);
	pidTurnInertial(-90);
	toggleTrap(false);
	pros::delay(500);
	translate(900,75*80);
	pros::delay(750);
	toggleTrap(true);
	pros::delay(500);
	translate(-250,50*80);
	pros::delay(250);
	pidTurnInertial(160);
	toggleTrap(false);
	toggleWings(true);
	pros::delay(500);
	pidTranslate(1400);
    
 }   

}

void autonFar(bool isBlue) {
  if (!isBlue)//isRed
  {
	toggleTrap(true);
    translate(180,80*70);
	pros::delay(500);
	toggleWings(true);
	pros::delay(500);
	pidTurnInertial(-290);
	pros::delay(750);
	toggleWings(false);
	pidTranslate(2200);
	pros::delay(250);
	pidTurnInertial(-100);
	toggleTrap(false);
	pros::delay(500);
	translate(600,127*70);
	pros::delay(500);
	translate(-400,100*70);
	pros::delay(500);
	pidTurnInertial(-85);
	pidTranslate(2200);
	pros::delay(250);
	pidTurnInertial(-90);
	pidTranslate(2000);
	pidTurnInertial(-90);
	translate(300,50*70);
	toggleTrap(true);
  }
  else
  {
	translate(180,80*70);
	pros::delay(250);
	toggleWings(true);
	pros::delay(500);
	pidTurnInertial(-290);
	pros::delay(250);
	toggleWings(false);
	pidTranslate(2200);
	pros::delay(250);
	pidTurnInertial(-100);
	toggleTrap(false);
	pros::delay(500);
	translate(600,127*80);
	pros::delay(500);
	translate(-400,100*70);
	pros::delay(500);
	pidTurnInertial(-85);
	pidTranslate(2200);
	pros::delay(250);
	pidTurnInertial(-90);
	pidTranslate(2000);
	pidTurnInertial(-90);
	translate(650,50*70);
	toggleTrap(true);
  }
}

void progSkills()
{
	pidTranslate(1350);
    pros::delay(500);
    pidTurnInertial(-110);
	pros::delay(500);
	translate(600,40*80);
	pros::delay(500);
    leftCata.move_voltage(12000);
    rightCata.move_voltage(12000);
    pros::delay(40000);
    leftCata.move_voltage(0);
    rightCata.move_voltage(0);
	pros::delay(500);
	pidTranslate(200);
	pros::delay(500);
	pidTurnInertial(110);


}



