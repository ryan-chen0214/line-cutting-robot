
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

int length = 500;

void setup() {
  // Set maximum speed and acceleration
  stepper.setMaxSpeed(500);    // Maximum steps per second
  stepper.setAcceleration(300); // Steps per second squared
  pinMode(stepPin , OUTPUT);
  pinMode(dirPin , OUTPUT);

  // Set initial target position        // Move to 2000 steps forward
}

void loop() {
  
  // stepper.moveTo(2000);
  // stepper.run();

  // stepper.moveTo(length);
  // while(stepper.distanceToGo()!= 0){
  //   stepper.run();
  // }

  stepper.setSpeed(500);
  for(int i = 0 ; i < length ; i++){
    stepper.runSpeed();
  }
  

  /* if(Serial.available()){
    length = Serial.read();
    stepper.move(length);
    stepper.setSpeed(500);
    while(stepper.runSpeedToPosition()){}
  } */
}
/*
#include <Stepper.h>

const int dirPin = 45;  // 方向引脚
const int stepPin = 44; // 步进引脚
 
// 电机每圈步数
const int STEPS_PER_REV = 200;
 
void setup() {
  
  // Arduino控制A4988步进和方向的引脚为输出模式
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
}
void loop() {
  
  // 设置电机顺时针旋转
  digitalWrite(dirPin,LOW); 
  
  // 电机慢速旋转
  for(int x = 0; x < STEPS_PER_REV; x++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(5000); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(5000); 
  }
  
  // 等待一秒
  delay(1000); 
  
  // 设置电机逆时针旋转
  digitalWrite(dirPin,HIGH);
  
  // 电机快速旋转
  for(int x = 0; x < (STEPS_PER_REV * 2); x++) {
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(5000);
    digitalWrite(stepPin,LOW);
    delayMicroseconds(5000);
  }
  
  // 等待一秒
  delay(1000);
}                  // Wait 1 second 

*/