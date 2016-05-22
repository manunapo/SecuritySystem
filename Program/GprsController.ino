#include <SoftwareSerial.h>
//TX,RX
SoftwareSerial SIM900(7, 8);

String outMessage = "Se activo el sensor";
String destinationNumber = "298315550485";

String lastMsg = "";
boolean stateChanged = false;

char incomingChars = 0;

void setUpGprs(){
  SIM900.begin(19200);
  SIM900.print("AT+CMGF=1\r");  
  delay(1000);
  SIM900.print("AT+CNMI=1,2,0,0,0\r"); 
  delay(1000);
}

void sendMessage(){
  SIM900.print("AT+CMGF=1\r");
  delay(1000);
  SIM900.println("AT + CMGS = \"" + destinationNumber +"\"");
  delay(1000);
  SIM900.print(outMessage);
  delay(1000);
  SIM900.write((char)26); //ctrl+z
  delay(1000);
}

void makeCall(){
  SIM900.println("ATD" + destinationNumber + ";");
  delay(1000);
}

void hangUp(){
   SIM900.println("ATH");
   delay(1000);
}
/*
void checkSMS(){
  if(SIM900.available() >0){
  while(SIM900.available() >0){
      Serial.print(SIM900.read());
  }
  }
}
*/
void checkSMS(){
  
  int counter = 0;
  String msgBody = "";
  if(SIM900.available() >0){
    while(SIM900.available() >0){
      incomingChars = SIM900.read(); //Get the character from the cellular serial port.
      if(counter == 6){
        if(incomingChars == 'A' || incomingChars == 'c' || incomingChars == 't' || 
          incomingChars == 'i' || incomingChars == 'v' || incomingChars == 'a' || 
          incomingChars == 'r' || incomingChars == 'D'|| incomingChars == 'e' || 
          incomingChars == 's' || incomingChars == 'a' || incomingChars == 'd')
          msgBody += incomingChars;
          
          Serial.print("msh:");Serial.println(msgBody);
      }
      if( incomingChars == '"'){
       counter++; 
      }
      Serial.print(incomingChars); //Print the incoming character to the terminal.
    }/*
    if(msgBody.equals("Activar")){
      Serial.println("LLEGO ACTIVAR");
       lastMsg = "Activar"; 
       stateChanged = true;
    }else if(msgBody.equals("Desactivar")){
       lastMsg = "Desactivar";
       stateChanged = true; 
    }*/
  }
}

boolean didStateChanged(){
   return stateChanged; 
}

String getLastMsg(){
  stateChanged = false;
   return lastMsg;
}

void checkSignal(){
  SIM900.print("AT+CSQ\r");
  delay(1000);
  while(SIM900.available() > 0)
      Serial.write(SIM900.read());
}
