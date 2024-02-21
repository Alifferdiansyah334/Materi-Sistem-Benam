//code servo

#include <Servo.h> // LIBRARY ARDUINO 

Servo myservo; // INISIALISASI SERVO

int position; // INISIALISASI POSISI 


void setup()
{
  Serial.begin(9600);
  myservo.attach(5); // PIN 5 SESUAI DI ARDUINO 
}

void loop()
{
    if (position==0) { // JIKA POSISI NYA 0 MAKA 
    for(position=0; position<180; position+=15) { // JIKA POSISINYA 0 DERAJAT SAMPE POSISI KURANG DARI 180 DERAJAT MAKA BALING" BAKAL MUTER NAMBAH 15 KEATAS DARI 0
      myservo.write(position);
      delay(1000);
    }
  }
  else {
    for(position=165; position>=0; position-=15) {// JIKA POSISINYA BERADAP PADA 165 DERAJAT MAKA AKAN BERGERAK KEBAWAH SEBANYAK 15 HINGGA 0 
      myservo.write(position);
      delay(1000);
      // TAMBAHKAN SERIAL.PRINTLN UNTUK DITAMPILKAN PADA SERIAL MONITOR
      }
      position = 0; //reset
    }

    // KALO PAKE KODE INI, BALING" DARI 90 DERAJAT BAKAL LANGSUNG KE 0 DERAJAT TANPA ADA PERTAMBAHAN 15 SEPERTI KODE DIATAS
    // JIKA MAU PAKE KODE INI MAKA JANGAN GUNAKAN KODE LOOP DIATAS 
    myservo.write(90);
    delay(1000);
    myservo.write(0);
    delay(1000);
}