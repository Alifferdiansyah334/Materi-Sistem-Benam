// Percobaan Buzzer
int Buzzer = 10; // Inisialisasi pin 10 

void setup() {
  // put your setup code here, to run once:
  pinMode(Buzzer, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(Buzzer, HIGH);
  delay(1000);
  digitalWrite(Buzzer, LOW);
  delay(1000);

}
