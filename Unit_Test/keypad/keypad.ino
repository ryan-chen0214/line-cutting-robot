#include <Keypad.h>

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

void setup() {
  Serial.begin(9600); 
  Serial.println("Keypad Ready! Press any key...");
}

void loop() {
  char key = keypad.getKey(); 

  if (key) { 
    Serial.print("Key Pressed: ");
    Serial.println(key);
  }
}
