#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#define Password_Length 7

LiquidCrystal_I2C lcd(0x3F, 16, 2);


char input[Password_Length];
char password[Password_Length]="555555";
byte counter = 0;
byte master = 0;

const byte ROWS = 4;
const byte COLS = 4;

char tombol[ROWS][COLS]={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'},
};

byte pinbaris[ROWS] = {11,10,9,8};
byte pinkolom[COLS] = {7,6,5,4};

Keypad keypadCustom = Keypad(makeKeymap(tombol),pinbaris,pinkolom, ROWS, COLS);

int cursor;

void setup(){
  lcd.init();        // Inisialisasi LCD
  lcd.backlight();   // Menyalakan backlight (jika ada)
  Serial.begin(9600);
}

void loop(){
  char keyCustom = keypadCustom.getKey();
  lcd.setCursor(0,0);
  lcd.print("Insert Password");
  
  if(keyCustom != NO_KEY && keyCustom != '#' && keyCustom != '*'){
    input[counter] = keyCustom;
    lcd.setCursor(counter,1);
    lcd.print(input[counter]);
    counter++;
  }else if(keyCustom == '*'){
    reset();
  }else if(keyCustom == '#'){
    lcd.clear();
    lcd.setCursor(4,0);
    lcd.print("Password");
    confirm();
  }
}
           
void reset(){
  lcd.clear();
  clearInput();
  cursor = 0;
}
           
void clearInput(){
  while (counter != 0){
    input[counter--] = 0;
  }
}
           
void confirm(){
  if(!strcmp(input,password)){
    lcd.print("Benar");
    delay(1000);
    lcd.clear();
    for(float i = 1; i <= 16; i++){
      lcd.setCursor(0,1);
      float persen = i*100/16;
      lcd.print("Loading : ");
      lcd.print(persen,2);
      lcd.print("%");
      lcd.setCursor(i-1,0);
      lcd.print("=");
      delay(100);
    }
    lcd.clear();
    lcd.setCursor(4,1);
    lcd.print("Selesai");
  }else{
    lcd.setCursor(5,1);
    lcd.print("Salah");
  }
  delay(3000);
  lcd.clear();
  reset();
  
}