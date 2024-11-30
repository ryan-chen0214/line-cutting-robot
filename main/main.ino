#include <AccelStepper.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h> 
#include <Keypad.h>


#define motorInterfaceType AccelStepper::DRIVER

LiquidCrystal_I2C lcd(0x27, 16, 2); 

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'0', '1', '2', '3'},
  {'4', '5', '6', '7'},
  {'8', '9', 'A', 'B'},
  {'C', 'D', 'E', 'F'}
};


byte rowPins[ROWS] = {11, 10, 9, 8};    
byte colPins[COLS] = {7, 6, 5, 4};   


Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);


const int stepPin = 44;  
const int dirPin = 45;
AccelStepper stepper(1, stepPin, dirPin); 
int length;

void Roll_out();
void enter_length();

void setup() {

  Serial.begin(9600);

  stepper.setMaxSpeed(500);  
  stepper.setAcceleration(300); 
  pinMode(stepPin , OUTPUT);
  pinMode(dirPin , OUTPUT);

  lcd.init();
  lcd.backlight();

}

void loop() {
  enter_length();
}


void Roll_out(){
    stepper.setSpeed(500);
    for(int i = 0 ; i < length ; i++){
        stepper.runSpeed();
    } 
}

void enter_length(){
    char len[4];
    int index = 0;
    while(1){
        char temp_key = keypad.getKey();
        lcd.setCursor(0 , 0);
        lcd.print("Enter Length : ");
        // lcd.setCursor(5 , 1);
        // lcd.print("A to confirm");
        if(temp_key){
            lcd.setCursor(0 , 1);
            Serial.println(temp_key);
            if(temp_key >= '0' && temp_key <= '9'){
                len[index] = temp_key;
                len[index + 1] = '\0';
                Serial.println(len);
                lcd.print(len);
                index++;
            }else if(temp_key == 'A'){
              break;
            }else if(temp_key == 'B'){
              index--;
              lcd.setCursor(index , 1);
              lcd.print("                 ");
              len[index] = '\0';
              Serial.println(len);
              lcd.print(len);
            }
        }
    }
}
