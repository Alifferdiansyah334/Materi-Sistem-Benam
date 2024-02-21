#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Alamat I2C dan ukuran layar, kalau eror ganti jadi (0x27), 16 karekter ke samping, 2 ke bawah, tidak bisa lebih dari 16  berdasarkan array jadi 16 = 0 - 15, 2 = 0 dan 1

void setup() {
  lcd.init();        // Inisialisasi LCD, ini harus ada jika menggunakan lcd 
  lcd.backlight();   // Menyalakan backlight (jika ada)
  lcd.setCursor(6, 1);  // Kembali ke awal

}

void loop() {
  lcd.clear();           // digunakan untuk Hapus layar
  lcd.print("This is a long text that will scroll left.");  // digunakan untuk mencetak teks Teks yang akan digulirkan
  delay(1000);

  // Menggulirkan terus menerus
  // for (int i = 0; i < 16; i++) {
  //   delay(500); // Tunggu sebentar setiap kali menggulirkan
  //   lcd.scrollDisplayLeft();
  // }
}
