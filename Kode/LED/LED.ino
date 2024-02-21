// Percobaan LED
int LED = 12; // Inisialisasi pin LED

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWwrite(LED, HIGH);
  delay(1000);
  digitalWrite(LED, LOW);
  delay(1000);
}
