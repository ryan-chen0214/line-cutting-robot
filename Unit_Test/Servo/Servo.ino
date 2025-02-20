#include<Servo.h>
const int BUTTON_PIN = 53;  // 按鍵的接腳
//const int LED_PIN =  3;   // LED燈的接腳

int buttonState = 0;   // 按鈕的狀態
Servo servo;

void setup() {
  pinMode(BUTTON_PIN, INPUT);   //設定LED的PIN腳為輸出
  servo.attach(9);
  servo.write(0);
  Serial.begin(9600);
  //pinMode(BUTTON_PIN, INPUT); //設定按鈕的接腳為輸入，因為我們要讀取它的狀態
}

void loop() {
  buttonState = digitalRead(BUTTON_PIN);  //讀取按鍵的狀態

  // if(buttonState == LOW){  
  //   Serial.println("buttonlow");        //如果按鍵按了
  //   servo.write(150);   //LED就亮了 
  // }else{                           //如果按鍵是未按下
  //   servo.write(120);  //LED就不亮
  // }

  servo.write(0);
  delay(1000);
  servo.write(45);
  delay(1000);
}