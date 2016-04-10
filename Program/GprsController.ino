#include <SoftwareSerial.h>

SoftwareSerial SIM900(7, 8);

String outMessage = "Se activo el sensor";
String destinationNumber = "298315550485";

void setUpGprs(){
  SIM900.begin(19200); 
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
