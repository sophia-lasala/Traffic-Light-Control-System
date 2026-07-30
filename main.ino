#include <LiquidCrystal.h>

#define NOTE_C4 262
#define NOTE_CS4 277
#define NOTE_D4 294
#define NOTE_DS4 311
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_FS4 370
#define NOTE_G4 392
#define NOTE_GS4 415
#define NOTE_A4 440
#define NOTE_AS4 466
#define NOTE_B4 494

LiquidCrystal lcd(5, 7, 8, 6, 9, 4);

int Buzz = 13;
int duration = 250;

int LED1 = 10; 
int LED2 = 11;
int LED3 = 12; 

int x = 0; //green light timer
int y = 3; //yellow light timer
int z = 15; //red light timer
int m = 1; //music counter

void setup() {
  pinMode(LED1, OUTPUT); //Green
  pinMode(LED2, OUTPUT); //Yellow
  pinMode(LED3, OUTPUT); //Red
  lcd.begin(16,2);
}

void loop() {
if (x == 0){ //allows for void loop() to reset itself after a cycle
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Traffic Moving");
  digitalWrite(LED1, HIGH);
  lcd.setCursor(0,1);
  lcd.print(x);
  x++;
  delay(1000);
  }
  
  lcd.setCursor(0,1);
  lcd.print(x);
  x++;
  delay(1000); 
  
  if (x == 30){
    
  	lcd.clear();
    lcd.setCursor(0,0);
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, HIGH);
    lcd.print("Ready to Stop");
    while (y >= 0){ //loop to count from 3 to 0 seconds
    lcd.setCursor(0,1);
  	lcd.print(y);
    y--;
  	delay(1000); 
      
      }
    
    lcd.clear();
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, HIGH);
      lcd.setCursor(0,0);
      lcd.print("Now Crossing");
      z = 15;
      lcd.setCursor(0,1);
      lcd.print(z);
      delay (1000);
      z--;
      lcd.setCursor(0,1);
      lcd.print(z);
      delay(1000);
      while (m <= 2) {     
        tone(Buzz, NOTE_C4, duration);
        lcd.setCursor(0,1);
        z--;
        lcd.setCursor(0,1);
        lcd.print(z);
    	delay(1000);
        
        
        z--;
        lcd.setCursor(0,1);
        lcd.print(z);
  		noTone(Buzz);
    	tone(Buzz, NOTE_D4, duration);
    	delay(250);
  		noTone(Buzz);
    	tone(Buzz, NOTE_E4, duration);
    	delay(500);
  		noTone(Buzz);
        tone(Buzz, NOTE_D4, duration);
    	delay(250);
        
        
        z--;
        lcd.setCursor(0,1);
        lcd.print(z);
        noTone(Buzz);  //to stop any static sound after the tone sequence
  		//where I found command: https://www.digitaltown.co.uk/funclesson4Tone.php
        tone(Buzz, NOTE_D4, duration);
    	delay(500);
        noTone(Buzz);
        tone(Buzz, NOTE_C4, duration);
    	delay(500);
        
        
        z--;
        lcd.setCursor(0,1);
        lcd.print(z);
  		noTone(Buzz);
        tone(Buzz, NOTE_E4, duration);
    	delay(1000);
        
        z--;
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Now Crossing");
        lcd.setCursor(0,1);
        lcd.print(z);
  		noTone(Buzz);      
        tone(Buzz, NOTE_G4, duration);
    	delay(500);
  		noTone(Buzz);
  		tone(Buzz, NOTE_F4, duration);
    	delay(250);
  		noTone(Buzz);
  		tone(Buzz, NOTE_E4, duration);
    	delay(250);
        
        
        z--;
        lcd.setCursor(0,1);
        lcd.print(z);
  		noTone(Buzz);
  		tone(Buzz, NOTE_D4, duration);
    	delay(500);
  		noTone(Buzz);
        tone(Buzz, NOTE_C4, duration);
    	delay(500);
        
        
        z--;
        lcd.setCursor(0,1);
        lcd.print(z);
  		noTone(Buzz);
   		m++;
        delay(1000);
}
      lcd.clear();
      y = 3;
    while (y > 0){
      lcd.setCursor(0,0);
      lcd.print("Stop Crossing");
      lcd.setCursor(0,1);
      lcd.print(y);
      y--;
      delay(1000);
    } 
    
    x = 0; //resets variables at end of cycle
    y = 3;
    z = 15;
    digitalWrite(LED3, LOW);
    
    
    }
  }
