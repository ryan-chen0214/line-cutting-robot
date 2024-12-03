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

int length = 0;
int quantity = 0;
const int length_coefficient = 100;

void Roll_out();
void lcd_enter_length();
void lcd_enter_quantity();
void lcd_now_cutting();

void setup() {

  Serial.begin(9600);

  stepper.setMaxSpeed(500);  
  stepper.setAcceleration(20000); 
  pinMode(stepPin , OUTPUT);
  pinMode(dirPin , OUTPUT);

  lcd.init();
  lcd.backlight();

}

void loop() {
  lcd_enter_length();
  lcd_enter_quantity();
  Serial.println("quantity = ");
  Serial.println(quantity);
  for(int i = 0 ; i < quantity ; i++){
    lcd_now_cutting(quantity - i);
    Roll_out();
    delay(2000);
  }
}


void Roll_out(){
    stepper.move(length * length_coefficient);
    while(stepper.distanceToGo() != 0){
      stepper.run();
    }
}

void lcd_enter_length(){
  char len[10];
  int index = 0;
  while(1){
    char temp_key = keypad.getKey();
    lcd.setCursor(0 , 0);
    lcd.print("Enter Length :");
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
          for(int i = 0 ; i <= index ; i++){
            length = length * 10 + (int)(len[i] - '0');
          }
          return 0;
        }else if(temp_key == 'B'){
          if(index >= 0 ) index--;
          lcd.setCursor(index , 1);
          lcd.print("                 ");
          len[index] = '\0';
          Serial.println(len);
          lcd.print(len);
        }
    }
  }
}

void lcd_enter_quantity(){
  char len[10];
  int index = 0;
  while(1){
    char temp_key = keypad.getKey();
    lcd.setCursor(0 , 0);
    lcd.print("Enter Quantity :");
    lcd.setCursor(index , 1);
    lcd.print("                ");
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
          for(int i = 0 ; i <= index ; i++){
            quantity = quantity * 10 + (int)(len[i] - '0');
          }
          return 0;
        }else if(temp_key == 'B'){
          if(index >= 0 ) index--;
          lcd.setCursor(index , 1);
          lcd.print("                 ");
          len[index] = '\0';
          Serial.println(len);
          lcd.print(len);
        }
    }
  }
}

void lcd_now_cutting(int numbers_left){
  lcd.setCursor(0 , 0);
  lcd.print("# left :          ");
  lcd.setCursor(0 , 1);
  char quant[16] = "                ";
  int index = 0;
  Serial.println(numbers_left);
  while(numbers_left > 0){
    quant[index + 2] = '\0';
    quant[index + 1] = quant[index];
    quant[index] = (char)((numbers_left % 10) + '0');
    numbers_left = numbers_left / 10;
    index++;
  }
  lcd.print(quant);
}
