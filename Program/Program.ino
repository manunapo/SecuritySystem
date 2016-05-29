#include <TimerOne.h>

boolean isAlarmActive = false;
boolean intrusionDetected = false;

unsigned long updateSignalTimer;
unsigned long updateSignalTime = 10000UL;

void setup(){
  Serial.begin(19200);
  setUpRemoteControl();
  setUpDoorSensor();
  setUpSiren();
  setUpEEPROM();
  setUpGprs();
  updateSignalTimer = millis();
}
boolean start = true;
void loop(){
  
  //Check remote controller
  checkKeys();

  //Check income SMS
  checkSMS();

  //Check shared state, if it was chaged by keys or sms then 
  //activate or desactivate the system.
  if(stateHasChanged()){
    if(stateIsActivated()){
      activate();
    }
    if(stateIsDesactivated()){
      desactivate();
    }
    stateRead();
    resetKeys();
  }

  if( millis() - updateSignalTimer > updateSignalTime){
  //Check signal of Gprs
    checkSignal();
    updateSignalTimer = millis();
  }
  
  //Check intrusion
  if(isAnyDoorOpen() && isAlarmActive){
    if(!intrusionDetected){
      intrusionDetected = true;
        //sendMessage();
        alarmOn();
      }  
  }

}

void activate(){
      Serial.println("Activate");
      updateSensors();
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
