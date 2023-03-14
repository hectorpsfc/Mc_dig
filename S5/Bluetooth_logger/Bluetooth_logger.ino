//Mandar estas lecturas por BT serial
//cada 100ms
#include "BluetoothSerial.h"
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run "make menuconfig" to and enable it
#endif

#if !defined(CONFIG_BT_SSP_ENABLED)
#error Serial Bluetooth not enabled! not available or not enabled. It is only available for the ESP32
#endif

#include "Adafruit_BMP280.h"

Adafruit_BMP280 bmp; //objeto bmp
BluetoothSerial SerialBT; // objeto BT

#define LED_PIN 33
#define LDR_PIN 35


char payload[80]; //payload de lecturas

void setup(){
  pinMode(LED_PIN,OUTPUT);
  Serial.begin(115200);
  bmp.begin(0x76);
  SerialBT.begin("Kamakot");
  Serial.println("Ora si we, aviéntale");
}

void loop() {

  //hacer payload
  sprintf(payload, "%6.2f, %3.2f, %d",
  bmp.readPressure()/100,
  bmp.readTemperature(),
  analogRead(LDR_PIN));

  digitalWrite(LED_PIN,HIGH);
    SerialBT.println(payload);
    Serial.println(payload);
  digitalWrite(LED_PIN,LOW);

  delay(100);

}
