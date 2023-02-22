#define PIN_LED 33 //Pin para el led
#define PIN_BUTTON 34 //Pin donde colocamos el botón 

void setup() {
  
  pinMode(PIN_LED,OUTPUT);
  pinMode(PIN_BUTTON,INPUT); //denotamos como entrada al botón

}

void loop() {
  bool button_status = digitalRead(PIN_BUTTON);// booleano para saber el estado del botón 
  if (button_status){
    digitalWrite(PIN_LED,HIGH); // si el botón está presente, el led se prende
  }
  else{
    digitalWrite(PIN_LED,LOW); // si no se lee el botón, se apaga el led
  }
  delay(100);
}
