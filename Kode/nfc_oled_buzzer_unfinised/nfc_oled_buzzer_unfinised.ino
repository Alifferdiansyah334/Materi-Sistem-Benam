//nfc
#include <Wire.h>
#include <PN532_I2C.h>
#include <PN532.h>
#include <NfcAdapter.h>
//oled
#include <Wire.h> 
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64
//buzzer
int Buzzer = 10;
//nfc
PN532_I2C pn532_i2c(Wire);
NfcAdapter nfc = NfcAdapter (pn532_i2c);
String tagId = "None";
byte nuidPICC[4];
//oled
Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
void setup() {
//nfc
Serial.begin(115200);
Serial.println("System Initialized");
nfc.begin();
//oled
oled.begin(SSD1306_SWITCHCAPVCC, 0x3C);
oled.setTextSize(2);// text size 1 paling kecil bisa sampe 3 
oled.setTextColor(WHITE); // Buat nampilin warna, bebas warna apa saja 
delay(2000);
oled.clearDisplay();
//buzzer
 pinMode(Buzzer, OUTPUT);
}


void loop(){
  if (nfc.tagPresent()) {
    NfcTag tag = nfc.read();
    tagId = tag.getUidString(); // Mendapatkan UID dan menyimpannya dalam variabel tagId
    Serial.println("UID: " + tagId);
  }
  delay(1000);
  if (tagId == "EA 81 29 2E"){
  digitalWrite(Buzzer, HIGH);
  delay(500);
  digitalWrite(Buzzer, LOW);
  delay(500);

  oled.clearDisplay(); //clear display agar tidak ada text yang tertinggal di kode sebelumnya 
  oled.setCursor(0, 30); //nentuin text bakal tampil dimana 
  oled.println("Shabira"); // nampilin kata 
  oled.display(); // kalo gapake oled display maka kata ga bakal tampil
  delay(2000);

  oled.clearDisplay(); // setiap kode baru pakaikan clear display buat clear kode sebelumnya 
  oled.setCursor(20, 30);
  oled.println("Perempuan");
  oled.display();
  delay(2000);

  oled.clearDisplay();

  oled.clearDisplay();
  oled.setCursor(50, 30);
  oled.println("20");
  oled.display();
  delay(2000);

  oled.clearDisplay();
  oled.setCursor(80, 30);
  oled.println("Mahasiswi");
  oled.display();
  delay(2000);
  }
else if (tagId = "16 47 82 73"){
  digitalWrite(Buzzer, HIGH);
  delay(500);
  digitalWrite(Buzzer, LOW);
  delay(500);
  digitalWrite(Buzzer, LOW);

  oled.clearDisplay(); //clear display agar tidak ada text yang tertinggal di kode sebelumnya 
  oled.setCursor(0, 30); //nentuin text bakal tampil dimana 
  oled.println("Haruto"); // nampilin kata 
  oled.display(); // kalo gapake oled display maka kata ga bakal tampil
  delay(2000);

  oled.clearDisplay(); // setiap kode baru pakaikan clear display buat clear kode sebelumnya 
  oled.setCursor(20, 30);
  oled.println("Laki-laki");
  oled.display();
  delay(2000);

  oled.clearDisplay();

  oled.clearDisplay();
  oled.setCursor(50, 30);
  oled.println("19");
  oled.display();
  delay(2000);

  oled.clearDisplay();
  oled.setCursor(80, 30);
  oled.println("Mahasiswa");
  oled.display();
  delay(2000);
}
else{
  digitalWrite(Buzzer, HIGH);
  delay(500);
  digitalWrite(Buzzer, LOW);
  delay(500);
  digitalWrite(Buzzer, HIGH);
  delay(500);
  digitalWrite(Buzzer, LOW);
  delay(500);
  digitalWrite(Buzzer, LOW);
}
}
