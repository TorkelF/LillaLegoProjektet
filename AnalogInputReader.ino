#include <Servo.h>

Servo myservo;

int servoDeg = 180; //start deg
int degTurn = 15;   //deg
int servoTurnSped = 500; // ms 
int darkLevel = 400; // upper val for closed

void setup() {
  Serial.begin(9600);
  myservo.attach(9);
}

void loop() {
  
  int analogValue = analogRead(A0);

  Serial.print("Analog reading: ");
  Serial.print(analogValue);  


  if (analogValue > darkLevel) {         // higer val of closed range
    Serial.println(" - close"); 
    Serial.println(servoDeg);
    servoDeg += degTurn; 
  } else {
    servoDeg -= degTurn;
  } 
  if (servoDeg >= 180) { // completly closed
   delay(5000);
   servoDeg = 180 - degTurn; //checking if lightlevel outside is dark
   Serial.println("completly closed");
  }
  if (servoDeg < 0) { // Completly open
    servoDeg = 0; // keeps servo deg +
    Serial.println("Completly open");
  }
  myservo.write(servoDeg);
  delay(servoTurnSped);
}