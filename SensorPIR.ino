int PIR = 2;
int statusPin = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(PIR, INPUT);
}

void loop()
{
  delay (650);
  statusPin = digitalRead(PIR);
  if(statusPin == HIGH)
  {
    Serial.print("Gerakan Terdeteksi");
    Serial.print('\n');
  }
  else
  {
    Serial.print("Tidak ada Gerakan");
    Serial.print('\n');
  }
}
