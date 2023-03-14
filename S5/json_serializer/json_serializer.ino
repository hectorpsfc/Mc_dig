// Leer Json desde Serial, SD o SPIFFS 
// Serializar un Json e imprimirlo por serial

#include <Adafruit_BMP280.h>
#include <ArduinoJson.h>
#include <SPIFFS.h>
<<<<<<< HEAD
//#include <Credentials.h> //para evitar hardcodear claves

//Payload creado con sprintf
=======
//#include <Credentials.h>

//Payload creado con snprintf
>>>>>>> f13862cfc57168e38c06a9b16dc044e937d95ddb
#define BUFFER_LEN  256
char payload[BUFFER_LEN]; //Payload Serializado
String json_string;

//Payload crearon con Json parser
//Doc: https://arduinojson.org/
//Ticket: Usar reservación de memoria en stack
//Usar el json assistant para calcular el LEN necesario para cada documento
#define JSON_BUFFER_INCOMING_LEN 200
#define JSON_BUFFER_OUTGOING_LEN 200
DynamicJsonDocument payload_in(JSON_BUFFER_INCOMING_LEN); //Json desde SPIFFS,SD,Serial o MQTT (Stream)
DynamicJsonDocument payload_out(JSON_BUFFER_OUTGOING_LEN);//Json hacia SPIFFS,SD,Serial o MQTT (Stream)

//Configuración de BMP y LED
<<<<<<< HEAD
#define PIN_LED 33
=======
#define PIN_LED 32
>>>>>>> f13862cfc57168e38c06a9b16dc044e937d95ddb
Adafruit_BMP280 bmp;

void setup() {
  
  //Inicializar perifericos
  Serial.begin(115200);
  bmp.begin(0x76); 
  pinMode(PIN_LED,OUTPUT);
  SPIFFS.begin(true);
  File file_json;

  //Leer el archivo con Json desde SPIFFS.
  file_json = SPIFFS.open("/json_file.txt", FILE_READ);

  //Guardar Json en variable
  while (file_json.available()) {
    json_string = file_json.readString();
  }   
  file_json.close(); 

<<<<<<< HEAD
  //Serial.println("Contenido del archivo");
  //Serial.println(json_string);
  //Serial.println("Está bueno imprimirlo por Serial, pero\n"
  //               "necesitamos extraer los atributos.\n"
  //               "A mano sería muy complicado.");  

  //Json parser deserializer
  //Parseo desde el archivo 
  //file_json = SPIFFS.open("/json_file.txt", FILE_READ);
 // deserializeJson(payload_in,file_json);
  //file_json.close(); 

  //Extracción de atributos
  //const char* message = payload_in["message"];
  //const char* origen = payload_in["origen"];

  //Serial.println("Atributos:");
  //Serial.println(message);Serial.println(origen);
=======
  Serial.println("Contenido del archivo");
  Serial.println(json_string);
  Serial.println("Está bueno imprimirlo por Serial, pero\n"
                 "necesitamos extraer los atributos.\n"
                 "A mano sería muy complicado.");  

  //Json parser deserializer
  //Parseo desde el archivo 
  file_json = SPIFFS.open("/json_file.txt", FILE_READ);
  deserializeJson(payload_in,file_json);
  file_json.close(); 

  //Extracción de atributos
  const char* message = payload_in["message"];
  const char* origen = payload_in["origen"];

  Serial.println("Atributos:");
  Serial.println(message);Serial.println(origen);
>>>>>>> f13862cfc57168e38c06a9b16dc044e937d95ddb


}


void loop() {

<<<<<<< HEAD
    //Para hacer payloads con jsons, es una solución Ok.
    //sprintf(payload,"{\"origen\" : \"sprintf\","
=======
    // //Para hacer payloads con jsons, es una solución Ok.
    // sprintf(payload,"{\"origen\" : \"sprintf\","
>>>>>>> f13862cfc57168e38c06a9b16dc044e937d95ddb
    //                   "\"temp_C\" : \"%.2f\"," 
    //                   "\"press_hPa\" : \"%.2f\"}",                      
    //                   bmp.readTemperature(),
    //                   bmp.readPressure()/100);

    // Serial.print("Publicando mensaje: ");
    // Serial.println(payload);
                
<<<<<<< HEAD
    //Json Serializer
    // Guardar
    payload_out["origen"] = "json_serializer";
    payload_out["temp_C"] = String(bmp.readTemperature(),2);
    payload_out["press_hPa"] = String(bmp.readPressure()/100,2);

    
     serializeJson(payload_out, payload);
    
    digitalWrite(PIN_LED,HIGH);      
    Serial.print("Publicando mensaje: ");
    Serial.println(payload);
    digitalWrite(PIN_LED,LOW);          
    
    delay(1000);
=======
    // //Json Serializer
    // // Guardar
    // payload_out["origen"] = "json_serializer";
    // payload_out["temp_C"] = String(bmp.readTemperature(),2);
    // payload_out["press_hPa"] = String(bmp.readPressure()/100,2);


    // serializeJson(payload_out, payload);
          
    // Serial.print("Publicando mensaje: ");
    // Serial.println(payload);
    // delay(5000);
>>>>>>> f13862cfc57168e38c06a9b16dc044e937d95ddb
                      
}
