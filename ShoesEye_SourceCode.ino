const int trigPin = 2;
const int echoPin = 4;

void setup() {
  pinMode(9, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  long duration, inches, cm;

  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);


  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

  cm = microsecondsToCentimeters(duration);
  Serial.println(cm);
  if(cm <= 100) {
     beep(2 * cm, 31);
  }
  
  delay(100);
}

void beep(unsigned char delayms, int sound) {
  analogWrite(9, sound);     
                           
  delay(delayms);          
  analogWrite(9, 0);       
  delay(delayms);             
} 

long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}
