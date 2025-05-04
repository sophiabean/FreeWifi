#pragma once

// Arm
constexpr float MAX_DEGREES = 25000.0f; // 150 degrees
constexpr float WAIT_DEGREES = 3500.0f; // 35 degrees
constexpr float DOWN_DEGREES = 1500.0f; // 15 degrees
constexpr float VERTICAL_DEGREES = 11000; 
constexpr float DISCORE_DEGREES = 15000; // 150 degrees
constexpr float SCORE_DEGREES = 18000;

// Holder
constexpr int AUTO_HOLD_TIMEOUT = 1000; // 1 sec

// Odom
constexpr int MAX_DIST_INCHES = 48;
constexpr int MAX_DIST_MM = 1000;

constexpr double BACK_OFFSET_INCHES = 5;
constexpr double LEFT_OFFSET_INCHES = 5.75;
constexpr double RIGHT_OFFSET_INCHES = 5.375;
constexpr double FRONT_OFFSET_INCHES = 6;

constexpr double FEILD_SIZE = 71;

// Conveyor
constexpr double RED_HIGH_THRESHOLD = 330;
constexpr double RED_LOW_THRESHOLD = 15; // detect red (HIGH_THRESHOLD, 360) and (0, RED_THRESHOLD) used to be 30, just red
constexpr double BLUE_HIGH_THRESHOLD = 270; // detect blue (BLUE_THRESHOLD, HIGH_THRESHOLD) used to be 160, just blue
constexpr double BLUE_LOW_THRESHOLD = 180; // detect blue (BLUE_THRESHOLD, HIGH_THRESHOLD) used to be 160, just blue
constexpr int STUCK_CURRENT = 2000;
constexpr int STUCK_RPM = 50;

constexpr double SPEEDRATIO = 1.0;
constexpr double DIST_THRESHOLD = 55;

constexpr bool AUTO_STARTED = true;

constexpr bool RUN_SKILLS = false;
