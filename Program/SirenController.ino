int pinSound = 6;
int pinLedAlarm = 10;

boolean ringing = false;
boolean intrusion = false;

void setUpSiren(){
   pinMode(pinSound, OUTPUT); 
   pinMode(pinLedAlarm, OUTPUT);
   interrupts();
   Timer1.initialize(2500000);         // Dispara cada 250 ms
   Timer1.attachInterrupt(ISR_Blink); // Activa la interrupcion y la asocia a ISR_Blink
}

void ISR_Blink(){
  if(intrusion){   
      if(ringing){
          digitalWrite(pinSound, LOW);
          digitalWrite(pinLedAlarm, LOW);
      }else{
          digitalWrite(pinSound, HIGH); 
          digitalWrite(pinLedAlarm, HIGH);
      }   
       ringing = !ringing ;
  }
}

void alarmOn(){
   intrusion = true;
}

void alarmOff(){
   intrusion = false;
   digitalWrite(pinLedAlarm, LOW); 
   digitalWrite(pinSound, LOW); 
}

void ledOn(){
  digitalWrite(pinLedAlarm, HIGH);
}

void ledOff(){
  digitalWrite(pinLedAlarm, LOW); 
}

void makeLongSound(){
  digitalWrite(pinSound, HIGH);
  delay(1000);
  digitalWrite(pinSound, LOW);
}

void makeShortSound(){
  digitalWrite(pinSound, HIGH);
  delay(250);
  digitalWrite(pinSound, LOW);
  delay(100);
  digitalWrite(pinSound, HIGH);
  delay(250);
  digitalWrite(pinSound, LOW);
}
