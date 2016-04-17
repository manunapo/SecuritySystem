int pinSound = 13;
int ledPin = 5;
boolean ringing = false;

void setUpSiren(){
   pinMode(pinSound, OUTPUT); 
   pinMode(ledPin, OUTPUT);
   
}

void ISR_Blink(){   
  if(ringing){
      digitalWrite(pinSound, LOW);
      digitalWrite(ledPin, LOW);
  }else{
      digitalWrite(pinSound, HIGH); 
            digitalWrite(ledPin, HIGH);
  }   
   ringing = !ringing ;
}

void alarmOn(){
 digitalWrite(pinSound, HIGH);
 digitalWrite(ledPin, HIGH); 
 Timer1.initialize(2500000);         // Dispara cada 250 ms
 Timer1.attachInterrupt(ISR_Blink); // Activa la interrupcion y la asocia a ISR_Blink
}

void alarmOff(){
   digitalWrite(ledPin, LOW); 
  digitalWrite(pinSound, LOW); 
 noInterrupts();
}
