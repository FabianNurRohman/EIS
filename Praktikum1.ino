#include <NewPing.h> // Import library NewPing.h

#define TRIGGER_PIN 11 // mendefenisikan 
#define ECHO_PIN 12

#define MAX_DISTANCE 200

NewPing sonar (TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
delay (1000);

float distance = sonar.ping_cm();

Serial.print ("Range = ");
Serial.print (distance);
Serial.println (" cm");
Serial.print(distance/100);
Serial.println(" m");
}