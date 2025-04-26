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
        chassis.moveDistance(5, 350, {.maxSpeed = 127}, true);
        arm.moveToState(ArmNamespace::State::UP);
        chassis.waitUntilDone();
        chassis.moveToPoint(-37.5, -17.5, 800, {.forwards = false, .maxSpeed = 127}, false);
        chassis.moveToPoint(-22, -24, 1100, {.forwards = false, .maxSpeed = 65}, true);
        arm.moveToState(ArmNamespace::State::DOWN);
        chassis.waitUntil(13);
        holder.moveToState(HolderNamespace::State::HOLD);
    
        
        conveyor.moveToState(ConveyorNamespace::State::FORWARDS);
        intake_raiser.moveToState(HolderNamespace::State::HOLD);
        chassis.turnToPoint(-40,-6, 600, {.maxSpeed = 127}, false);
        chassis.moveToPoint(-40, -6, 900, {.maxSpeed = 127}, false);
        intake_raiser.moveToState(HolderNamespace::State::RELEASE);
        chassis.moveDistance(-8,500, {.forwards = false, .maxSpeed = 127}, false);


    
        
    
       chassis.moveToPoint(-50,-60, 1200, {.maxSpeed = 127}, false);
       chassis.turnToHeading(225, 800, {.maxSpeed = 127}, false);
       chassis.moveDistance(40,1100, {.minSpeed = 127}, false);
       chassis.moveDistance(-15,600, {.forwards = false, .maxSpeed = 127}, false);
       chassis.moveDistance(11,600, {.maxSpeed = 127}, false);

       chassis.turnToHeading(180, 900, {.maxSpeed = 127}, true);
       chassis.correctAt180({"front","right"});
       chassis.turnToPoint(-24, -46, 1000, {.maxSpeed = 127}, false);

       chassis.moveDistance(35, 1000, {.maxSpeed = 100}, false);
       pros::delay(200);
       chassis.moveDistance(-40,700, {.forwards = false, .maxSpeed = 100}, false);
       holder.moveToState(HolderNamespace::State::RELEASE);
    
       
       conveyor.moveToState(ConveyorNamespace::State::STOP);
    
       chassis.moveToPoint(-16, -16, 3000, {.maxSpeed = 90}, false);
}