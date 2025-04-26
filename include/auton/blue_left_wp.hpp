#pragma once
#include "components.hpp"

void blue_left_wp() {
    arm.resetRotation(3500.0f);
    conveyor.setInitColor(ConveyorNamespace::Color::BLUE);
    chassis.setPose(51.25, -11, 60);

    //pros::delay(2500);
    //normal arm code

    //back up arm code
    // arm.moveToState(ArmNamespace::State::WAIT);
    // pros::delay(300);
    // conveyor.moveToState(ConveyorNamespace::State::FORWARDS, 500);
    chassis.moveDistance(5, 350, {.maxSpeed = 127}, true);
    arm.moveToState(ArmNamespace::State::UP);
    chassis.waitUntilDone();
    chassis.moveToPoint(37.5, -17.5, 700, {.forwards = false, .maxSpeed = 127}, false);
    chassis.moveToPoint(24, -24, 1100, {.forwards = false, .maxSpeed = 65}, true);
    arm.moveToState(ArmNamespace::State::DOWN);
    chassis.waitUntil(12);
    holder.moveToState(HolderNamespace::State::HOLD);

    
    conveyor.moveToState(ConveyorNamespace::State::FORWARDS);
    intake_raiser.moveToState(HolderNamespace::State::HOLD);
    chassis.turnToPoint(41,-7, 500, {.maxSpeed = 127}, false);
    chassis.moveToPoint(41, -7, 900, {.maxSpeed = 127}, false);
    intake_raiser.moveToState(HolderNamespace::State::RELEASE);
    chassis.moveDistance(-8,500, {.forwards = false, .maxSpeed = 127}, false);



    

   chassis.moveToPoint(59,-59, 1200, {.maxSpeed = 127}, false);

   chassis.turnToHeading(125, 1000, {.maxSpeed = 127}, false);

   chassis.moveDistance(40,1000, {.maxSpeed = 127}, false);
   chassis.moveDistance(-15,600, {.forwards = false, .maxSpeed = 127}, false);
   chassis.moveDistance(10, 600, {.maxSpeed = 127}, false);


   chassis.turnToHeading(180, 900, {.maxSpeed = 127}, false);
   chassis.correctAt180({"front","left"});
   chassis.turnToPoint(24, -53.5, 1000, {.maxSpeed = 127}, false);
   chassis.moveDistance(35,900, {.maxSpeed = 127}, false);

   pros::delay(200);
   chassis.moveDistance(-35,700, {.forwards = false, .maxSpeed = 100}, false);
   holder.moveToState(HolderNamespace::State::RELEASE);

   
   chassis.turnToPoint(0, -24, 500, {.maxSpeed = 127}, false);
   conveyor.moveToState(ConveyorNamespace::State::STOP);

   chassis.moveToPoint(18, -18, 2000, {.maxSpeed = 47}, false);
   

}