#include <TimerOne.h>

boolean isAlarmActive = false;
boolean intrusionDetected = false;

void setup(){
  Serial.begin(19200);
  setUpRemoteControl();
  setUpSiren();
  setUpDoorSensor();
  setUpEEPROM();
  delay(1000);
}

void loop(){
  
  //Check remote controller
  int key = checkKeys();
  if(key != 0) {
    if( key == 1){
      activate();
    }else if(key == 2){
      desactivate();
    }else if(key == 3){
      
    }
    
  }
  
  //Check signal of Gprs
  checkSignal();
  
  //Check income SMS
  checkSMS();
  if(didStateChanged()){
    if(getLastMsg().equals("Activar")){
      activate();
    }else if(getLastMsg().equals("Desactivar")){
      desactivate();
    }
  }
  
  //Check intrusion
  if(isDoorOpen() && isAlarmActive){
    if(!intrusionDetected){
      intrusionDetected = true;
        //sendMessage();
        delay(5000);
        
        alarmOn();
      }  
  }
  
  delay(200);
}

void activate(){
      isAlarmActive = true;
      ledOn();
      makeLongSound();
}
void desactivate(){
      isAlarmActive = false;
      makeShortSound();
      intrusionDetected = false;
      alarmOff();
}
