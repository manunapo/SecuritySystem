#include <EEPROM.h>

#define MAX_NUMBERS 4
//298315550485
#define STRING_LENGTH 12

#define STORAGE_START 0
#define STORAGE_SLOT_ADDRESSES 24

String numbers[MAX_NUMBERS];

int totalNumbers = 0;

void setUpEEPROM(){
  loadStorage();
}

void loadStorage(){
  totalNumbers = 0;
  for(int i = STORAGE_START; i < MAX_NUMBERS * STORAGE_SLOT_ADDRESSES; i += STORAGE_SLOT_ADDRESSES){
    int j = 0;
    boolean finish = EEPROM.read(i) != 's';
    String number = "";
    while(!finish && j < STORAGE_SLOT_ADDRESSES - 2){
      char temp = EEPROM.read( i + j + 1);
      number += temp;
      if( EEPROM.read( i + j + 2) == 'f'){
        finish = true;
        numbers[totalNumbers++] = number;
      }
      j++;
    }
  }
}
  
//return false if not more space por controller number
//true if could save new controller number
boolean saveNewNumber( String num){
  loadStorage();
	if(totalNumbers < MAX_NUMBERS){
    int offset = STORAGE_START + totalNumbers * STORAGE_SLOT_ADDRESSES;
    EEPROM.put( offset, 's');
    int i = 1;
    while( i < STORAGE_SLOT_ADDRESSES - 1 && i <= num.length()){
      EEPROM.put( offset + i, num.charAt( i - 1));  
      i++;
    }
		EEPROM.put(offset + i, 'f');
		return true;
	}else{
		return false;
	}
}

String getNumber( int num){
	if(num < totalNumbers){
		return numbers[num];
	}
	return "";
}

boolean isSavedNumber( String num){
	boolean is = false;
	int i = 0;
	while(!is && i < totalNumbers){
		is = num.equals(numbers[i]);
		i++;
	}
	return is;
}

int getTotalNumbers(){
  return totalNumbers;
}

String getAllNumbers(){
  loadStorage();
	String toR = "";
	for(int i = 0; i < MAX_NUMBERS; i ++){
		toR += numbers[i] + "-";
	}
	return toR;
}

void EEPROMclear(){
  for (int i = 0 ; i < EEPROM.length() ; i++) {
    EEPROM.write(i, 0);
  }
}

