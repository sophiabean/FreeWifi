#pragma once
#include "components.hpp"

void red_positive(){

        arm.resetRotation(3500.0f);
        conveyor.setInitColor(ConveyorNamespace::Color::RED);
        chassis.setPose(-50.75, -11, 302);

        //pros::delay(2500);h
        //normal arm code

        //back up arm code
        // arm.moveToState(ArmNamespace::State::WAIT);
        // pros::delay(300);
        // conveyor.moveToState(ConveyorNamespace::State::FORWARDS, 500);


        // alliance stake ring
        chassis.moveDistance(5, 350, {.maxSpeed = 127}, true); //used to be 5
        arm.moveToState(ArmNamespace::State::UP);
        chassis.waitUntilDone();
        // backwards pick up moblie goal
        chassis.moveToPoint(-28, -24, 800, {.forwards = false, .maxSpeed = 90}, false); //used to be -37.5, -17.5
        chassis.moveToPoint(-24, -24, 1100, {.forwards = false, .maxSpeed = 65}, true); //used to be -24, -24
        arm.moveToState(ArmNamespace::State::DOWN);
        holder.moveToState(HolderNamespace::State::HOLD);
        chassis.waitUntil(17);

        // is holding moblie goal, turns toward stack
        conveyor.moveToState(ConveyorNamespace::State::FORWARDS);
        intake_raiser.moveToState(HolderNamespace::State::HOLD);
        chassis.turnToPoint(-46, 0, 900, {.maxSpeed = 90}, false); //used to be -40, -3
        // move to stack
        chassis.moveToPoint(-48, 0, 1000, {.maxSpeed = 127}, false); //same
        chassis.waitUntilDone();
        intake_raiser.moveToState(HolderNamespace::State::RELEASE);
        chassis.moveDistance(-8,500, {.forwards = false, .maxSpeed = 90}, false);
        pros::delay(300);


        // go toward corner
        chassis.moveToPoint(-60,-70, 2000, {.maxSpeed = 90}, false); //used to be -50, -70
        chassis.waitUntilDone();
        // goes in at 55 degrees
        chassis.turnToHeading(235, 800, {.maxSpeed = 90}, false);
        // nudge the corner stack with the intake raiser while ramming
        chassis.moveDistance(40,1100, {.minSpeed = 127}, true);
        pros::delay(200);
        intake_raiser.moveToState(HolderNamespace::State::HOLD);
        pros::delay(600);
        intake_raiser.moveToState(HolderNamespace::State::RELEASE);
        chassis.waitUntilDone();
        // bot out of corner abit
        chassis.moveDistance(-15,600, {.forwards = false, .maxSpeed = 90}, false);
        // bot goes back for 2nd ring from stack
        chassis.moveDistance(11,600, {.maxSpeed = 90}, false);

        chassis.turnToHeading(90, 900, {.maxSpeed = 127}, true); //used to be 90
        chassis.correctAt90({"right"});
        chassis.turnToPoint(-24, -48, 1000, {.maxSpeed = 90}, false);
        chassis.moveDistance(35, 900, {.maxSpeed = 90}, false);

        pros::delay(200);
        chassis.moveDistance(-40,700, {.forwards = false, .maxSpeed = 100}, false);
        holder.moveToState(HolderNamespace::State::RELEASE);

        chassis.turnToPoint(0, -24, 500, {.maxSpeed = 90}, false);
        conveyor.moveToState(ConveyorNamespace::State::STOP);

        chassis.moveToPoint(-12, -24, 3000, {.maxSpeed = 90}, false);
}