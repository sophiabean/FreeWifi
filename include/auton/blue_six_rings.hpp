#pragma once
#include "components.hpp"

void blue_six_rings() {
    arm.resetRotation(3500.0f);
    conveyor.setInitColor(ConveyorNamespace::Color::BLUE);
    chassis.setPose(50.75, 11, 122);
    //normal arm code

    //back up arm code
    // arm.moveToState(ArmNamespace::State::WAIT);
    // pros::delay(300);
    // conveyor.moveToState(ConveyorNamespace::State::FORWARDS, 500);
    //remove 3 lines below for 6 ring, put ring in the conveyor
    chassis.moveDistance(5, 300, {.maxSpeed = 127}, true);
    arm.moveToState(ArmNamespace::State::UP);
    chassis.waitUntilDone();

    chassis.moveToPoint(37.5, 17.5, 600, {.forwards = false, .maxSpeed = 127}, false);
    chassis.moveToPoint(24, 24, 1100, {.forwards = false, .maxSpeed = 65}, true);
    arm.moveToState(ArmNamespace::State::DOWN);
    chassis.waitUntil(12);
    holder.moveToState(HolderNamespace::State::HOLD);

    
    conveyor.moveToState(ConveyorNamespace::State::FORWARDS);
    chassis.turnToHeading(330, 800, {.maxSpeed = 127}, false); 
    chassis.waitUntilDone();
 
    chassis.moveDistance(21.5, 1000, {.maxSpeed = 127}, false);
    chassis.moveToPoint(10, 26, 900, {.forwards = false, .maxSpeed = 100}, false);
    chassis.turnToHeading(0, 600, {.maxSpeed = 127}, false);
    chassis.moveDistance(22, 500, {.maxSpeed = 127}, false);
    chassis.correctAt0({"front"});
    chassis.turnToHeading(-90, 800, {.maxSpeed = 127}, false);
    //chassis.correctAt90({"left"});
    chassis.moveDistance(12.5, 800, {.maxSpeed = 127}, false);
    chassis.moveDistance(-35, 800, {.forwards = false, .maxSpeed = 80}, false);
    chassis.turnToHeading(45, 800, {.maxSpeed = 127}, false);
    chassis.moveDistance(40, 1100, {.minSpeed = 127}, false);
    chassis.moveDistance(-15, 500, {.forwards = false, .maxSpeed = 80}, false);
    chassis.moveDistance(12, 500, {.maxSpeed = 80}, false);
    chassis.turnToHeading(90, 500, {.maxSpeed = 127}, false);
    chassis.correctAt90({"front", "left"});


    //chassis.moveToPoint(24, 24, 1100, {.forwards = false,  .maxSpeed = 127}, false);
    //chassis.turnToPoint(28, 0, 700, {.maxSpeed = 127}, false);
    //chassis.moveToPoint(24, 0, 1800, { .maxSpeed = 37}, false);
    chassis.moveToPoint(53, 2, 2000, {.maxSpeed = 100}, true);
    chassis.waitUntil(20);
    intake_raiser.moveToState(HolderNamespace::State::HOLD);
    chassis.waitUntilDone();
    intake_raiser.moveToState(HolderNamespace::State::RELEASE);
    chassis.moveDistance(-6, 300, {.forwards = false, .maxSpeed = 127}, false);

}
