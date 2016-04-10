#include <SoftwareSerial.h>

SoftwareSerial SIM900(7, 8);

String outMessage = "Se activo el sensor";
String destinationNumber = "298315550485";

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

boolean checkSMS() // Receiving the SMS and extracting the Sender Mobile number & Message Text
{
  // Now we simply display any text that the GSM shield sends out on the serial monitor
  if(SIM900.available() >0)
  {
    incomingChars=SIM900.read(); //Get the character from the cellular serial port.
    Serial.print(incomingChars); //Print the incoming character to the terminal.
  }
}

