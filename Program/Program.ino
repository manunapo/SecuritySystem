#include <TimerOne.h>

boolean isAlarmActive = false;
boolean intrusionDetected = false;

void setup(){
  Serial.begin(19200);
  //setUpRemoteControl();
  //setUpDoorSensor();
  //setUpSiren();
  //setUpEEPROM();
  setUpGprs();
}
boolean start = true;
void loop(){
  /*
  //Check remote controller
  int key = checkKeys();
  if(key != 0) {
    if( key == 1){
      Serial.println("Llego activar desde CR");
      activate();
    }else if(key == 2){
      Serial.println("Llego desactivar desde CR");
      desactivate();
    }else if(key == 3){
      
    }
  }
/*
  unsigned long Timer;
  if(start){
    Timer = millis ();
    start = false;
  }
  if( millis() - Timer > 5000UL){
  //Check signal of Gprs
  //checkSignal();
    start = true;
  }
  */
  //Check income SMS
  checkSMS();
  /*if(didStateChanged()){
    if(getLastMsg().equals("Activar")){
      Serial.println("Llego activar desde SMS");
      activate();
    }else if(getLastMsg().equals("Desactivar")){
      Serial.println("Llego desactivar desde SMS");
      desactivate();
    }
  }
  
  //Check intrusion
  if(isDoorOpen() && isAlarmActive){
    if(!intrusionDetected){
      intrusionDetected = true;
        //sendMessage();
        alarmOn();
      }  
  }
  */
}

void activate(){
      Serial.println("Activate");
      isAlarmActive = true;
      ledOn();
      makeLongSound();
}
void desactivate(){
      Serial.println("Desactivate");
      isAlarmActive = false;
      alarmOff();
      makeShortSound();
      intrusionDetected = false;
}
