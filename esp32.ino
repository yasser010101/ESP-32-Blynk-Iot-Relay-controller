//Include the library files
#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "............."
#define BLYNK_TEMPLATE_NAME "............."
#define BLYNK_AUTH_TOKEN ".............................."
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>


const int irReceiverPin = 5;

// Enter your Auth token
char auth[] = "........................";

//Enter your WIFI SSID and password
char ssid[] = ".............";
char pass[] = ".............";

void setup(){
  // Debug console
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
    IrReceiver.begin(irReceiverPin , ENABLE_LED_FEEDBACK);  

}

void loop(){
  Blynk.run();
  if (IrReceiver.decode()) {
    IrReceiver.printIRResultShort(&Serial);
    IrReceiver.resume();
  }
}