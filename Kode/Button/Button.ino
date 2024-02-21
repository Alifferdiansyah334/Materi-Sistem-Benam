// Percobaan Button 
int button = 6;
int  buttonKey = 0;
int i = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(button, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonKey = digitalRead(button);
  
  if(buttonKey == HIGH){
    i+=1; // i nya ditambah 1
    Serial.println(i); 
  }
