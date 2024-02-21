//Rotary Encoder
#define CLK 2
#define DT 3
#define SW 4

//buzzer
int Buzzer = 10;

int counter = 0;
int currentStateCLK;
int lastStateCLK;
String currentDir ="";
unsigned long lastButtonPress = 0;

//Servo
#include <Servo.h> // LIBRARY ARDUINO 
Servo myservo; // INISIALISASI SERVO
int position; // INISIALISASI POSISI 

void setup() {
  
  // Set encoder pins as inputs
  pinMode(CLK,INPUT);
  pinMode(DT,INPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(SW, INPUT_PULLUP);

  // Setup Serial Monitor
  Serial.begin(9600);

  // Read the initial state of CLK
  lastStateCLK = digitalRead(CLK);

  // Servo
  myservo.attach(5); // PIN 5 SESUAI DI ARDUINO 

}

void loop() {
  
  // Rotary
  // Read the current state of CLK
  currentStateCLK = digitalRead(CLK);

  // If last and current state of CLK are different, then pulse occurred
  // React to only 1 state change to avoid double count
  if (currentStateCLK != lastStateCLK  && currentStateCLK == 1){

    // If the DT state is different than the CLK state then
    // the encoder is rotating CCW so decrement
    if (digitalRead(DT) != currentStateCLK) {
      counter --;
      currentDir ="CCW";
    } else {
      // Encoder is rotating CW so increment
      counter ++;
      currentDir ="CW";
    }

    Serial.print("Direction: ");
    Serial.print(currentDir);
    Serial.print(" | Counter: ");
    Serial.println(counter);
  }

   // Remember last CLK state
  lastStateCLK = currentStateCLK;
  delay(1);

  //Servo
    position = currentStateCLK;
    myservo.write(position);
    delay(10);

    if(currenStateCLK == 180){
       digitalWrite(Buzzer, HIGH);
       delay(1000);
       digitalWrite(Buzzer, LOW);
       delay(1000);   
    }
    else if(currenStateCLK == -180){
       digitalWrite(Buzzer, HIGH);
       delay(1000);
       digitalWrite(Buzzer, LOW);
       delay(1000);   
    }
    else{
      Serial.println(currentStateCLK)
    }
}
}
