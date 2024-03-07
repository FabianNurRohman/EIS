int rainPin = A1;
int keringMinimal = 800;

void setup(){
  Serial.begin(9600);
}

void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(rainPin);
  Serial.print(sensorValue);
  if(sensorValue < keringMinimal){
    Serial.println(" - Tidak perlu disiram, sudah lembab/basah");
  }
  else {
    Serial.println(" - Perlu disiram");
  }
  delay(2000);
}