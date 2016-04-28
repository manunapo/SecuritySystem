// Pin analogico de entrada para el sensor de la puerta
int doorSensorPin = 2;

void setUpDoorSensor(){
  pinMode(doorSensorPin, INPUT_PULLUP); 
}

boolean isDoorOpen(){
 return (digitalRead(doorSensorPin) == HIGH); 
}
