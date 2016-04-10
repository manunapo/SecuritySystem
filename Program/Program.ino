// Pin analogico de entrada para el LDR
int pinLDR = 0;
 
// Variable donde se almacena el valor del LDR
int valorLDR = 0; 

boolean messageSent = false;

void setup(){
  Serial.begin(19200);
  setUpGprs();
  setUpSiren();
}
void loop(){
  
  valorLDR= analogRead(pinLDR);
  checkSMS();
  if(valorLDR > 700){
    if(!messageSent){
       sendMessage();
       messageSent = true;
       delay(5000);
       alarmOn();
    }
  }else{
     messageSent = false;
     alarmOff(); 
  }
  // Esperar unos milisegundos antes de actualizar
  delay(200);
}
