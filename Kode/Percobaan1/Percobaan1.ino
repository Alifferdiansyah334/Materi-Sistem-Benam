int Buzzer = 10; // inisialisasi buzzer jadi 10 dimana 10 merupakan jalur arduino
int LED = 12; // inisialisasi buat LED di Arduino 

// bukan main code, kalo disini led nyala sekali 
void setup() { 
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT); 
  pinMode(Buzzer, OUTPUT);

}

//main code, kalo disini led nyala berulang kali
void loop() {
  // put your main code here, to run repeatedly: kode bakal berulang ulang 
  digitalWrite(LED,HIGH); // jalur LED bakal nyala 
  digitalWrite(Buzzer, HIGH); // jalur buzzer bakal nyala 
  delay(1000); // bakal nge delay 1 detik 
  digitalWrite(Buzzer, LOW); // jalur buzzer bakal mati, akhirnya LED bakal nyala terus 
                            //dan Buzzer kedap kedip
  delay(1000);

}

// Caranya sambungin ke arduino dan protobot, lalu pasang kabel panjang plus pendek minus
// di run dulu terus pilih board maka akan berfungsi pada protobot 
