// Percobaan 1 menggunakan button 
int led = 4; // INISIALISASI LED
int buzzer = 10; // inisialisasi buzzer 
int button = 6;
int buttonKey = 0;
int i = 0;
void setup()
{
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
  pinMode(buzzer, OUTPUT);
  digitalWrite(led,LOW);
  Serial.begin(9600);
}

void loop() // dilakukan berulang 
{
  buttonKey = digitalRead(button);
  
  if(buttonKey == HIGH){
    digitalWrite(led,HIGH); // lampu nyala 
    i+=1; // i nya ditambah 1
    Serial.println(i); 
  }
  
   if(i==1){ // jika i = 1, lampu dan buzzer nala mati nyala mati 
    digitalWrite(led,HIGH); // lampu nyala 
    delay(500); // delay 0.5 detik 
    digitalWrite(buzzer,HIGH); // BUZZER NYALA 
    delay(500); // delay 0.5 detik 
    digitalWrite(led, LOW); // lampu mati 
    delay(500); // delay 0.5 detik 
    digitalWrite(buzzer, LOW); // buzzer mati 
    delay(500); // delay 0.5 detik 
    
  }else if(i==2) { // jika i = 2 buzzer nyala 
    digitalWrite(led, LOW); // lampu mati
    digitalWrite(buzzer,HIGH); // buzzer nyala 
    delay(500); // delay 0.5 detik 
    digitalWrite(buzzer, LOW); // buzzer mati 
    //i=0; // i direset ke 0
  }

  else if(i==3) { // jika i = 3 
    digitalWrite(buzzer, LOW); // buzzer mati 
    digitalWrite(led, HIGH); // led nyala 
    delay(3000); // led nyala 3 detik 
    digitalWrite(led, LOW); // led mati 
    i=0; // i direset ke 0
  }


}

// Percobaan 2 menggunakan 
//sekali pencet buzzer led nyala mati 
// 2 kali buzzer nyala 
// 3 kali lampu nyala 3 detik terus mati 








