
#include <AccelStepper.h>

// Define motor interface type
// Options: AccelStepper::DRIVER (for A4988/DRV8825)
// AccelStepper::FULL2WIRE, AccelStepper::FULL3WIRE, AccelStepper::FULL4WIRE, etc.
#define motorInterfaceType AccelStepper::DRIVER

// Define pins for motor driver
const int stepPin = 44;  // STEP pin
const int dirPin = 45;   // DIR pin

// Create an instance of AccelStepper
AccelStepper stepper(1, stepPin, dirPin);

int length = 200;

void setup() {
  // Set maximum speed and acceleration
  stepper.setMaxSpeed(800);    // Maximum steps per second
  stepper.setAcceleration(20000); // Steps per second squared
  Serial.begin(9600);
  pinMode(stepPin , OUTPUT);
  pinMode(dirPin , OUTPUT);

  // Set initial target position        // Move to 2000 steps forward

  //delay(1000);
  /*stepper.moveTo(400);
  while(stepper.distanceToGo() != 0){
    stepper.runSpeedToPosition();
  }/*

  /*stepper.setSpeed(500);
  int step_count = 0;
  int i;
  for(i = 0 ; i < 3000 ; i++){
    stepper.runSpeedTo();
    Serial.println(i);
  }
  Serial.println(i);/*
  /*while(step_count < 40000){
    stepper.runSpeed();
    step_count++;
    Serial.println(step_count);
  }*/
}

void loop() {
    stepper.setSpeed(800);
    stepper.move(400);
    while(stepper.distanceToGo() != 0){
      stepper.run();
    }
    stepper.move(-400);
    while(stepper.distanceToGo() != 0){
      stepper.run();
    }
  /*stepper.setSpeed(500);
  for(int i = 0 ; i < 400 ; i++){
      stepper.runSpeed();
    }
  */
}                  // Wait 1 second 
