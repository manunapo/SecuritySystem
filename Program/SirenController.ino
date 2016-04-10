int pinSound = 13;

void setUpSiren(){
   pinMode(pinSound, OUTPUT); 
}

void alarmOn(){
 digitalWrite(pinSound, HIGH); 
}

void alarmOff(){
 digitalWrite(pinSound, LOW); 
}
