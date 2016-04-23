int pinSound = 13;
int pinLedAlarm = 6;
boolean ringing = false;

void setUpSiren(){
   pinMode(pinSound, OUTPUT); 
   pinMode(pinLedAlarm, OUTPUT);
   
}

void ISR_Blink(){   
  if(ringing){
      digitalWrite(pinSound, LOW);
      digitalWrite(pinLedAlarm, LOW);
  }else{
      digitalWrite(pinSound, HIGH); 
            digitalWrite(pinLedAlarm, HIGH);
  }   
   ringing = !ringing ;
}

void alarmOn(){
 digitalWrite(pinSound, HIGH);
 digitalWrite(pinLedAlarm, HIGH); 
 Timer1.initialize(2500000);         // Dispara cada 250 ms
 Timer1.attachInterrupt(ISR_Blink); // Activa la interrupcion y la asocia a ISR_Blink
}

void alarmOff(){
   digitalWrite(pinLedAlarm, LOW); 
   digitalWrite(pinSound, LOW); 
   noInterrupts();
}

void ledOn(){
  digitalWrite(pinLedAlarm, HIGH); 
  delay(2000);
}

void ledOff(){
  digitalWrite(pinLedAlarm, LOW); 
}
