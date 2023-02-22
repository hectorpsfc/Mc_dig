//Encender el led usando el potenciometro
#define PIN_LED 33 //pin conectado al led(es el mismo para los sketch anteriores)
#define PIN_PTM 32 //pin al que está conectado el potenciometro
#define TRHLD 2047.5

void setup() {
  pinMode(PIN_LED,OUTPUT);
  Serial.begin(115200);//para poder visualizar en el plotter

}

void loop() {
   int ptm_signal = analogRead(PIN_PTM);//lee los valores del potenciometro
   if (ptm_signal>TRHLD){//condicion para que el led se mantenga apagado arriba del treshold
     digitalWrite(PIN_LED,LOW);
   }

   else{
     digitalWrite(PIN_LED,HIGH);//enciende el led al estar debajo del treshold
   }
  Serial.println(ptm_signal);//podemos ver el valor del potenciometro en el plotter
  
  delay(50);

}