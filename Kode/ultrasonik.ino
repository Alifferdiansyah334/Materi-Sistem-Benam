// Sensor Ultrasonik

const int trigPin = 4;
const int echoPin = 3;

int durationPulse, distanceCm;
int pos=0;


void setup()
{
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop()
{
  digitalWrite(trigPin, HIGH);
  delay(100);
  digitalWrite(trigPin, LOW);

  durationPulse = pulseIn(echoPin, HIGH);
  distanceCm = 0.017 * durationPulse;

  Serial.print("Distance: ");
  Serial.print(distanceCm);
  Serial.println("cm");
  delay(100);
}
