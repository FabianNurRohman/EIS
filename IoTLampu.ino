#include <WiFi.h>
#include <HTTPClient.h>

// Deklarasi pin yang digunakan
const int sensorPin = 2;   // Pin untuk sensor PIR
const int relayPin = 4;    // Pin untuk modul relay

const char* ssid = "nama_wifi";
const char* password = "katasandi_wifi";
const char* botToken = "7024297178:AAFt-9OXakNIcJVAvaEbEcNU8IYOER27TAI";
const char* chatIds[] = {"1133812882", "2137249285"}; // Daftar chat ID yang ingin Anda kirim pesan
int numOfChatIds = sizeof(chatIds) / sizeof(chatIds[0]);

void setup() {
  pinMode(sensorPin, INPUT);   // Mengatur pin sensor sebagai input
  pinMode(relayPin, OUTPUT);  // Mengatur pin relay sebagai output
  digitalWrite(relayPin, LOW); // Matikan relay saat awal
  
  Serial.begin(115200); // Inisialisasi Serial Monitor
  WiFi.begin(ssid, password); // Mencoba untuk terhubung ke jaringan WiFi
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }
  Serial.println(" Connected!");
}

void sendTelegramMessage(const char* message, const char* chatIds[], int numOfChatIds) {
  HTTPClient http;
  for (int i = 0; i < numOfChatIds; i++) {
    String url = "https://api.telegram.org/bot" + String(botToken) + "/sendMessage?chat_id=" + String(chatIds[i]) + "&text=" + String(message);
    http.begin(url);
    int httpResponseCode = http.GET();
    if (httpResponseCode > 0) {
      Serial.println("Telegram notification sent to chat ID: " + String(chatIds[i]));
    } else {
      Serial.println("Error sending Telegram notification to chat ID: " + String(chatIds[i]));
    }
    http.end();
  }
}

void loop() {
  // Baca nilai sensor PIR
  int motionDetected = digitalRead(sensorPin);
  
  // Jika gerakan terdeteksi
  if (motionDetected == HIGH) {
    digitalWrite(relayPin, HIGH); // Hidupkan lampu
    
    // Kirim notifikasi ke Telegram
    sendTelegramMessage("Lampu dinyalakan!", chatIds, numOfChatIds);

    delay(5000);  // Tahan lampu menyala selama 5 detik
  } else {
    digitalWrite(relayPin, LOW); // Matikan lampu jika tidak ada gerakan
  }
}
