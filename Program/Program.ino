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
  
  checkSMS();
  if(didStateChanged()){
    if(getLastMsg().equals("Activar"))
      isAlarmActive = true;
    else if(getLastMsg().equals("Desactivar")){
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
