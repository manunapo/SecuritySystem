int pinValidTrans = A0;
int pinActivate = A1;
int pinDesactivate = A2;
int pinAlert = A3;

void setUpRemoteControl(){
    pinMode(A0, INPUT);
    pinMode(A1, INPUT);
    pinMode(A2, INPUT);
    pinMode(A3, INPUT);
}

//Return 0 if no action detected,
//1 if key A was pressed.
//2 if key D was pressed.
//3 if key B was pressed.
int checkKeys(){
    int toReturn = 0;
    if(digitalRead(A0)){  
 
        if (digitalRead(A1)) 
            toReturn = 1;
        if (digitalRead(A2)) 
            toReturn = 2;
        if (digitalRead(A3)) 
            toReturn = 3;
     } 
     return toReturn;
}

