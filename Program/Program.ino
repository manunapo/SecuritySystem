#include <TimerOne.h>

boolean isAlarmActive = false;
boolean intrusionDetected = false;

void setup(){
  Serial.begin(19200);
  setUpGprs();
  setUpSiren();
  setUpDoorSensor();
  delay(1000);
}
void loop(){
  int valor = analogRead(0); // Leemos el valor de A0.
  Serial.print ("Valor de entrada: ");
  Serial.println(valor); // Valor de entrada de A0.
  
  if(valor > 950) {
    
      isAlarmActive = true;
      ledOn();
    
    
  }
  
  
  
  checkSMS();
  if(didStateChanged()){
    if(getLastMsg().equals("Activar")){
      ledOn();
      isAlarmActive = true;
    }else if(getLastMsg().equals("Desactivar")){
      ledOff();
      Serial.print("a off");
      isAlarmActive = false;
      intrusionDetected = false;
      alarmOff();
    }
  }
  
        
  if(isDoorOpen() && isAlarmActive){
        
    if(!intrusionDetected){
      Serial.print("a on");  
      intrusionDetected = true;
        //sendMessage();
        delay(5000);
        alarmOn();
      }  
  }
  
  delay(200);
}
