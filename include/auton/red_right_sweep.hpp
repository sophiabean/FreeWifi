#pragma once
#include "components.hpp"

void red_right_sweep() {
    // pros::delay(1000);

        arm.resetRotation(3500.0f);
        conveyor.setInitColor(ConveyorNamespace::Color::RED);
        chassis.setPose(-50.75, -11, 302);

        //pros::delay(2500);h
        //normal arm code
    
        //back up arm code
        // arm.moveToState(ArmNamespace::State::WAIT);
        // pros::delay(300);
        // conveyor.moveToState(ConveyorNamespace::State::FORWARDS, 500);
        chassis.moveDistance(5, 500, {.maxSpeed = 127}, false);
        arm.moveToState(ArmNamespace::State::UP);
        pros::delay(500);
        chassis.moveToPoint(-37.5, -17.5, 900, {.forwards = false, .maxSpeed = 127}, false);
        chassis.moveToPoint(-24, -24, 1000, {.forwards = false, .maxSpeed = 65}, true);
        arm.moveToState(ArmNamespace::State::DOWN);
        chassis.waitUntil(12);
        holder.moveToState(HolderNamespace::State::HOLD);
    
        
        conveyor.moveToState(ConveyorNamespace::State::FORWARDS);
        intake_raiser.moveToState(HolderNamespace::State::HOLD);
        chassis.turnToPoint(-41,-7, 800, {.maxSpeed = 127}, false);
        chassis.moveToPoint(-41, -7, 900, {.maxSpeed = 127}, false);
        intake_raiser.moveToState(HolderNamespace::State::RELEASE);
        chassis.moveDistance(-5,500, {.forwards = false, .maxSpeed = 127}, false);


    
        
    
       chassis.moveToPoint(-58,-58, 1200, {.maxSpeed = 127}, false);
       chassis.turnToHeading(210, 800, {.maxSpeed = 127}, false);
       chassis.moveDistance(20,900, {.maxSpeed = 127}, false);
       pros::delay(400);
       chassis.moveDistance(-10,600, {.forwards = false, .maxSpeed = 127}, false);
       doinker.moveToState(HolderNamespace::State::HOLD);
       pros::delay(100);
       chassis.moveDistance(10, 500, {.maxSpeed = 127}, false);
       chassis.turnToHeading(150, 900, {.maxSpeed = 127}, true);
       chassis.waitUntil(180);
       chassis.correctAt180({"front","right"});
       chassis.waitUntilDone();
       doinker.moveToState(HolderNamespace::State::RELEASE);
       chassis.moveDistance(30, 1000, {.maxSpeed = 80}, false);
       chassis.moveToPoint(-24, -48, 1500, {.maxSpeed = 127}, true);

       
       chassis.waitUntilDone();
       chassis.turnToHeading(90, 800, {.maxSpeed = 127}, false);
       

       holder.moveToState(HolderNamespace::State::RELEASE);
       //chassis.turnToHeading(270,800, {.maxSpeed = 127}, false);



}
