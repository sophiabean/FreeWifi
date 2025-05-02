#pragma once

#include "components.hpp"



void skills() {

    conveyor.setInitColor(ConveyorNamespace::Color::RED);
    chassis.setPose(-62.5, 0, 90);

    conveyor.moveToState(ConveyorNamespace::State::FORWARDS, 2000);
    pros::delay(400);
    // conveyor.moveToState(ConveyorNamespace::State::FORWARDS, 1500);

    chassis.moveToPoint(-24, 24, 1500, {.maxSpeed = 80}, false);
    chassis.turnToHeading(90, 700, {.maxSpeed = 80}, false);
    chassis.moveToPoint(-50, 24, 2000, {.forwards = false, .maxSpeed =65});
    chassis.waitUntil(24);

    //first mobile goal grab

    holder.moveToState(HolderNamespace::State::HOLD);
    //pros::delay(100);
    conveyor.moveToState(ConveyorNamespace::State::FORWARDS);
    chassis.moveDistance(26, 800, {}, false);
    chassis.turnToPoint(-3, 57, 1000, {}, false);
    chassis.moveToPoint(-3, 57, 1500, {.maxSpeed = 80}, false);
    chassis.moveToPose(-62, 47, 270, 4300, {.maxSpeed = 80}, false);
    chassis.turnToHeading(26, 800, {.maxSpeed = 100}, false);
    chassis.moveDistance(15, 900, {.maxSpeed = 80}, false);
    chassis.turnToHeading(115, 1000, {.maxSpeed = 100}, false);
    holder.moveToState(HolderNamespace::State::RELEASE);
    //conveyor.moveToState(ConveyorNamespace::State::REVERSE, 300); 
    // First mobile goal drop

    chassis.moveDistance(-12, 700, {.forwards = false, .maxSpeed = 100}, false);
    chassis.moveToPoint(-48, 48, 1200, {.maxSpeed = 100}, false);
    chassis.turnToHeading(0, 1000, {}, false);
    chassis.correctAt0({"front", "left"});
    chassis.moveToPoint(-48, -7, 2500, {.forwards = false, .maxSpeed =80});
    chassis.turnToHeading(0, 500, {}, false);
    chassis.correctAt0({"left"});
    chassis.moveToPoint(-48, -24, 1500, {.forwards = false, .maxSpeed =65});
    chassis.waitUntil(13);

    //second mobile goal
    holder.moveToState(HolderNamespace::State::HOLD);
    pros::delay(100);
    conveyor.moveToState(ConveyorNamespace::State::FORWARDS);
    chassis.turnAndMoveToPoint(-24, -22, 1200, {.maxSpeed = 85}, false);
    chassis.turnAndMoveToPoint(2, -52, 1500, {.maxSpeed = 80}, false);
    //goes to the wrong ring?
    //chassis.moveToPose(-50, -58, 270, 3200, {.maxSpeed = 1 00}, false);
    chassis.moveToPose(-24, -50, 280, 2900, {.maxSpeed = 100}, false);
    chassis.moveDistance(40, 1800, {.maxSpeed = 80}, false);
    //chassis.correctAt270({"front", "left"});
    chassis.turnToPoint(-48, -58, 1000, {.maxSpeed = 90}, false);
    chassis.moveDistance(14, 1000, {.maxSpeed = 80}, false);
    chassis.turnToHeading(70, 1000, {.maxSpeed = 80}, false);

    // Second mobile goal drop
    holder.moveToState(HolderNamespace::State::RELEASE);
    chassis.moveDistance(-12, 500, {.forwards = false, .maxSpeed = 100}, false);
    conveyor.moveToState(ConveyorNamespace::State::REVERSE, 300); 

    //starts journey to third mobile goal
    chassis.moveToPoint(-48, -48, 1000, {.maxSpeed = 100}, false);
    chassis.turnToHeading(90, 800, {.maxSpeed = 100}, false);
    chassis.waitUntilDone();
    // use sensors to recalibrate location and angles
    chassis.correctAt90({"right"});
    conveyor.moveToState(ConveyorNamespace::State::FORWARDS, 2150);

    //first wasted ring
    chassis.moveToPoint(16, -48, 2000, {.maxSpeed = 70}, false);
    chassis.turnToPoint(16, -24, 1000, {.maxSpeed = 100}, false);
    conveyor.moveToState(ConveyorNamespace::State::INTAKE_FORWARD);
    chassis.moveToPoint(16, -24, 1000, {.maxSpeed = 80}, false);
    chassis.turnToPoint(48, 0, 800, {.forwards = false, .maxSpeed = 100}, false);
    chassis.moveDistance(-12, 800, {.forwards = false, .maxSpeed =100});
    chassis.moveDistance(-16, 1000, {.forwards = false, .maxSpeed =65},true);

    //mobile goal
    chassis.waitUntil(12);
    holder.moveToState(HolderNamespace::State::HOLD);
    conveyor.moveToState(ConveyorNamespace::State::FORWARDS);
    chassis.waitUntilDone();
    chassis.turnToHeading(0, 600, {}, false);
    chassis.correctAt0({"right"});
    chassis.turnAndMoveToPoint(22, 24, 900, {}, false);
    chassis.turnAndMoveToPoint(22, 48, 900, {}, false);
    chassis.turnToHeading(0, 600, {}, false);
    chassis.correctAt0({"front", "right"});
    chassis.turnToHeading(65, 600, {}, false);
    chassis.moveDistance(15, 900, {}, false);
    chassis.moveToPoint(60, 48, 1200, {}, false);
    chassis.turnToHeading(200, 600, {}, false);
    chassis.correctAt180({"left"});

    pros::delay(100);

    holder.moveToState(HolderNamespace::State::RELEASE);
    // conveyor.moveToState(ConveyorNamespace::State::REVERSE); //USELESS

    chassis.moveDistance(-15, 700, {.forwards = false, .minSpeed = 100}, false);
    chassis.moveToPoint(48, 30, 1500, {.minSpeed = 100}, false);
    chassis.turnToHeading(154, 800, {}, false); //used to be 160 instead of 154
    chassis.moveDistance(45, 1000, {}, false);
    chassis.turnToHeading(165, 700, {}, false);
    chassis.moveDistance(30, 1000, {}, false);

    intake_raiser.moveToState(HolderNamespace::State::HOLD); //why
    chassis.moveToPoint(38, -24, 1200, {.forwards = false, .maxSpeed =100}, false);
    chassis.turnToHeading(145, 700, {}, false);
    arm.moveToState(ArmNamespace::State::SCORE_UP);
    conveyor.moveToState(ConveyorNamespace::State::STOP);
    chassis.moveDistance(-55, 1200, {.forwards = false, .maxSpeed = 120}, false);
}