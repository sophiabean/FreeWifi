#pragma once
#include "components.hpp"

void blue_positive() {
    arm.resetRotation(3500.0f); // code was commented
    conveyor.setInitColor(ConveyorNamespace::Color::BLUE);
    chassis.setPose(51.25, -11, 60);

    //pros::delay(2500);
    //normal arm code
    //code was commented
    //back up arm code
    //arm.moveToState(ArmNamespace::State::WAIT);
    //pros::delay(300);
    //conveyor.moveToState(ConveyorNamespace::State::FORWARDS, 500);

    //go forwards and score alliance steak
    chassis.moveDistance(5, 350, {.maxSpeed = 127}, true);
    arm.moveToState(ArmNamespace::State::UP);
    chassis.waitUntilDone();
    //code was commented
    // goes backwards towards mobile goal
    chassis.moveToPoint(37.5, -17.5, 700, {.forwards = false, .maxSpeed = 70}, false);
    chassis.moveToPoint(24, -24, 1100, {.forwards = false, .maxSpeed = 65}, true);
    arm.moveToState(ArmNamespace::State::DOWN); //code was commented
    chassis.waitUntil(12);
    holder.moveToState(HolderNamespace::State::HOLD);
    chassis.waitUntil(17);

    // first stack
    conveyor.moveToState(ConveyorNamespace::State::FORWARDS);
    intake_raiser.moveToState(HolderNamespace::State::HOLD);
    chassis.turnToPoint(41,-7, 500, {.maxSpeed = 127}, false);
    chassis.moveToPoint(41, -7, 900, {.maxSpeed = 127}, false);
    chassis.waitUntilDone();
    intake_raiser.moveToState(HolderNamespace::State::RELEASE);
    chassis.moveDistance(-8,500, {.forwards = false, .maxSpeed = 127}, false);
    pros::delay(300);

    // go for the corner stack
    chassis.moveToPoint(54,-30, 400, {.maxSpeed = 100}, false);
    chassis.moveToPoint(56,-44, 1200, {.maxSpeed = 100}, false);
    // chassis.waitUntilDone();
    //goes into corner at 55 degrees
    chassis.turnToHeading(135, 500, {.maxSpeed = 127}, false);
    //rams into corner, should also lift intake
    chassis.moveDistance(40, 800, {.maxSpeed = 127}, false);
    // pros::delay(600);
    // chassis.waitUntilDone();
    //moves back
    chassis.moveDistance(-15,800, {.forwards = false, .maxSpeed = 127}, false);
    //goes back in (all the way) for second ring
    chassis.moveDistance(15, 600, {.maxSpeed = 127}, false); //used to be (10, 600,

    //blue on bottom stack
    chassis.turnToHeading(180, 900, {.maxSpeed = 127}, false);
    chassis.correctAt180({"front","left"});
    chassis.turnToPoint(24, -56, 1000, {.maxSpeed = 127}, false);
    chassis.moveDistance(35 ,900, {.maxSpeed = 127}, false);

    pros::delay(200);
    chassis.moveDistance(-30,700, {.forwards = false, .maxSpeed = 100}, false);
    pros::delay(300);
    holder.moveToState(HolderNamespace::State::RELEASE);

    //ladder
    chassis.turnToPoint(0, -24, 500, {.maxSpeed = 127}, false);
    conveyor.moveToState(ConveyorNamespace::State::STOP);

    chassis.moveToPoint(4, -22, 2000, {.maxSpeed = 55}, false);


}