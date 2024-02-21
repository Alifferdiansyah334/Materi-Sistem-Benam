#include <Wire.h>
#include <PN532_I2C.h>
#include <PN532.h>
#include <NfcAdapter.h>

PN532_I2C pn532_i2c(Wire);
NfcAdapter nfc = NfcAdapter (pn532_i2c);
String tagId = "None";
byte nuidPICC[4];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("System Initialized");
  nfc.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  readNFC();
}


void readNFC() {
  if (nfc.tagPresent()) {
    NfcTag tag = nfc.read();
    tagId = tag.getUidString(); // Mendapatkan UID dan menyimpannya dalam variabel tagId
    Serial.println("UID: " + tagId);
  }
  delay(1000);
}