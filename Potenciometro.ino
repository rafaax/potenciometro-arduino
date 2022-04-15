 #include <ArduinoJson.h> 
 #include <IOXhop_FirebaseESP32.h> 
 #include <WiFi.h>
 #define FIREBASE_AUTH "AIzaSyBdfY7ekYrvm1Bi8QmlndDFUxpJ9Jc09MI"
 #define FIREBASE_HOST "https://senaitcc-dbfc1-default-rtdb.firebaseio.com/" 

 String fireStatus = "";

 int LED_BUILTIN = 13;
 const char* usuario = "gabigato";
 const char* senha = "gamagato";

 void setup()
 {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);

  WiFi.begin(usuario, senha);

  while (WiFi.status() !=WL_CONNECTED)
  {
    delay(500);
    Serial.println("Conectando ao wifi...");
  }
  Serial.print("Conectado");
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH); 
 }
void loop()
 {
  fireStatus = (Firebase.getString("/Morpheuszada/LED"));
  Serial.print(Firebase.getString("/Morpheuszada/LED"));
  Serial.println();

  if (fireStatus == "1")
  {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);       
  }
  else (fireStatus == "0");
  {
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);   
  }
 }
