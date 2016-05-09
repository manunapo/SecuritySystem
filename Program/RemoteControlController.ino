int pinValidTrans = A3;
int pinActivate = 9;
int pinDesactivate = A4;
int pinAlert = 13;
int lastDetected = 0;

void setUpRemoteControl(){
    pinMode(pinValidTrans, INPUT);
    pinMode(pinActivate, INPUT);
    pinMode(pinDesactivate, INPUT);
    pinMode(pinAlert, INPUT);
}

//Return 0 if no action detected,
//1 if key A was pressed.
//2 if key D was pressed.
//3 if key B was pressed.
int checkKeys(){
    int toReturn = 0;
    if(digitalRead(pinValidTrans)){  
        if (digitalRead(pinActivate) && lastDetected != 1){
            toReturn = 1;
            lastDetected = 1;
        }
        if (digitalRead(pinDesactivate) && lastDetected != 2) {
            toReturn = 2;
            lastDetected = 2;            
        }
        if (digitalRead(pinAlert) && lastDetected != 3){
            toReturn = 3;
            lastDetected = 3;            
        }
     } 
     return toReturn;
}

