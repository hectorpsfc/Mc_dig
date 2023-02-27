//Plotear la señal resultante de oscurecer el LDR y encender el led por debajo del umbral
#define PIN_LED 33 //pin de conexion del led
#define PIN_LDR 35 //pin de conexion del ldr
#define TRHLD 400

void setup() {
  pinMode(PIN_LED,OUTPUT);
  Serial.begin(115200);

}

void loop() {
   int ldr_signal = analogRead(PIN_LDR); //Lee la señal que capta el ldr
   if (ldr_signal>TRHLD){ // si la señal esta arriba del umbral, el led se mantiene apagado
     digitalWrite(PIN_LED,LOW);
   }

   else{
     digitalWrite(PIN_LED,HIGH);// señal debajo del umbral, se enciende el led
   }
  Serial.println(ldr_signal);// se manda al serial para plottear lo captado por el ldr
  delay(50);

}
