//Presión en una columna, temperatura en otra
//Ejemplo
// 70000, 23.5

#include "Adafruit_BMP280.h"

Adafruit_BMP280 bmp; // objeto bmp
char payload[80]; // payload de lecturas

void setup() {
  bmp.begin(0x76); // inicializa bmp
  Serial.begin(115200);

}

void loop() {
  sprintf(payload, "%8.2f,%3.2f",
  bmp.readPressure()/1000,
  bmp.readTemperature());

  Serial.println(payload);

  //mandar_a_sd(payload);
  //mandar_a_aws(payload);



  /* ok pero no es escalable
  Serial.print(bmp.readPressure()/1000);
  Serial.print(", ");
  Serial.println(bmp.readTemperature());
  */

  
  delay(200);  

}

