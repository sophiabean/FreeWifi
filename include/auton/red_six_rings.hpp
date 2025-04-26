#pragma once
#include "components.hpp"

void red_six_rings() {
    arm.resetRotation(3500.0f);
    conveyor.setInitColor(ConveyorNamespace::Color::RED);
    chassis.setPose(-51.25, 11, 238);
    //normal arm codeb

    //back up arm code
    // arm.moveToState(ArmNamespace::State::WAIT);
    // pros::delay(300);
    // conveyor.moveToState(ConveyorNamespace::State::FORWARDS, 500);
    //remove 3 lines below for 6 ring, put ring in the conveyor
    chassis.moveDistance(5, 350, {.maxSpeed = 127}, true);
    arm.moveToState(ArmNamespace::State::UP);
    chassis.waitUntilDone();

    chassis.moveToPoint(-37.5, 17.5, 600, {.forwards = false, .maxSpeed = 127}, false);
    chassis.moveToPoint(-24, 24, 1100, {.forwards = false, .maxSpeed = 65}, true);
    arm.moveToState(ArmNamespace::State::DOWN);
    chassis.waitUntil(13);
    holder.moveToState(HolderNamespace::State::HOLD);

    
    conveyor.moveToState(ConveyorNamespace::State::FORWARDS);
    chassis.turnToHeading(26, 800, {.maxSpeed = 127}, false); 
    chassis.waitUntilDone();
 
    chassis.moveDistance(20, 800, {.maxSpeed = 127}, false);
    chassis.moveToPoint(-26, 24, 800, {.forwards = false, .maxSpeed = 100}, false);
    chassis.turnToHeading(0, 500, {.maxSpeed = 127}, false);
    chassis.moveDistance(20, 600, {.maxSpeed = 127}, false);
    chassis.correctAt0({"front"});
    chassis.turnToHeading(90, 1000, {.maxSpeed = 127}, false);
    //chassis.correctAt90({"left"});
    chassis.moveDistance(16, 800, {.maxSpeed = 127}, false);
    chassis.moveDistance(-36, 800, {.forwards = false, .maxSpeed = 80}, false);
    chassis.turnToHeading(310, 900, {.maxSpeed = 100}, false);


    chassis.moveDistance(40, 1000, {.minSpeed = 127}, false);
    chassis.moveDistance(-15, 500, {.forwards = false, .maxSpeed = 80}, false);

    chassis.moveDistance(12, 500, {.maxSpeed = 80}, false);



    chassis.turnToHeading(-90, 500, {.maxSpeed = 127}, false);

    
    chassis.correctAt270({"front", "right"});

    chassis.moveToPoint(-48, 10, 2000, {.maxSpeed = 100}, true);
    chassis.waitUntil(30);
    intake_raiser.moveToState(HolderNamespace::State::HOLD);
    chassis.waitUntilDone();
    intake_raiser.moveToState(HolderNamespace::State::RELEASE);
    chassis.moveDistance(40, 600, {.maxSpeed = 127}, false);

    //chassis.moveToPoint(-28, 24, 1100, {.forwards = false,  .maxSpeed = 127}, false);
    //chassis.turnToPoint(-26, 0, 700, {.maxSpeed = 127}, false);
    //chassis.moveToPoint(-24, 0, 1800, { .maxSpeed = 37}, false);
    // the last three lines(above) are for qual

    // chassis.turnToPoint(-15, 36.5, 800, {.maxSpeed = 100}, false);
    // chassis.moveDistance(15, 1000, {.maxSpeed = 127}, false);
    // chassis.swingToHeading(0, lemlib::DriveSide::LEFT, 500, {}, false);
    // chassis.moveDistance(7, 600, {.maxSpeed = 127}, false);
    
    // chassis.moveToPoint(-24, 24, 1300, {.forwards = false, .maxSpeed = 100}, false);
    // conveyor.moveToState(ConveyorNamespace::State::FORWARDS);
    // chassis.turnToHeading(0, 600, {.maxSpeed = 127}, false);
    // chassis.correctAt0({"left"});

    // chassis.moveDistance(20, 600, {.maxSpeed = 127}, false);
    // chassis.correctAt0({"front"});
    // chassis.turnToPoint(-46, 9, 800, {.maxSpeed = 127}, false);
    // intake_raiser.moveToState(HolderNamespace::State::HOLD);

    // chassis.moveToPoint(-42, 9, 1500, {.maxSpeed = 127}, false);

    // intake_raiser.moveToState(HolderNamespace::State::RELEASE);
    // chassis.moveDistance(-5, 500, {.forwards = false, .maxSpeed = 127}, false);
    // chassis.turnToPoint(-24, 0, 800, {.maxSpeed = 127}, false);
    // chassis.moveDistance(25, 3000, {.maxSpeed = 37}, false);



}
