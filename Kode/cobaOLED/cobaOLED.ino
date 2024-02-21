/*********
  Rui Santos
  Complete project details at https://randomnerdtutorials.com  
*********/

// Library yang digunakan 
#include <Wire.h> 
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
Serial.begin(9600);
  oled.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  oled.setTextSize(2);// text size 1 paling kecil bisa sampe 3 
  oled.setTextColor(WHITE); // Buat nampilin warna, bebas warna apa saja 
  delay(2000);
  oled.clearDisplay();
 
}

void loop() {
  oled.clearDisplay(); //clear display agar tidak ada text yang tertinggal di kode sebelumnya 
  oled.setCursor(0, 30); //nentuin text bakal tampil dimana 
  oled.println("HAIII"); // nampilin kata 
  oled.display(); // kalo gapake oled display maka kata ga bakal tampil
  delay(2000);

  oled.clearDisplay(); // setiap kode baru pakaikan clear display buat clear kode sebelumnya 
  oled.setCursor(20, 30);
  oled.println("NAMA");
  oled.display();
  delay(2000);

  oled.clearDisplay();

  oled.clearDisplay();
  oled.setCursor(50, 30);
  oled.println("SAYA");
  oled.display();
  delay(2000);

  oled.clearDisplay();
  oled.setCursor(80, 30);
  oled.println("Shabira");
  oled.display();
  delay(2000);
}