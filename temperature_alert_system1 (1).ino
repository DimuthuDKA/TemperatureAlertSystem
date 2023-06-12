#include<SoftwareSerial.h>

#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2); //connecting the pins rs,en,d4,d5,d6,d7 to the arduino at pin 12 11 5 4 3 2

int celsius; //declare a function celsius as an integer

void setup()
{
  pinMode(A0,INPUT)
  pinMode(7,OUTPUT)
  Serial.begin(9600); //set the baud rate at 9600 bits per secon
  lcd.begin(16,2); //lcd size is 16x2 // Print a message to the LCD
  lcd.print("Temp Display");
  Serial.println("Temp Display"); //print the message at the serial monitor
}

void loop()
{
  celsius = map(((analogRead(A0)—20) * 3.04), 0, 1023, -40, 125); //map to obtain temperature mathematically.Meaning 0 = -40degrees and 1023 = 125degrees

  lcd.setCursor(0,0); //cursor set to the first pixel of the lcd.

  lcd.print("Temp Display"); //print message to lcd

  lcd.setCursor(0, 1); //cursor set to the second line first pixel

  lcd.print(celsius); //prints the celsius output from the analog read onto the lcd at 0,1

  lcd.print("C"); //print alphabet “c”

  Serial.println(celsius); //output shown in the serial monitor

  delay(1000); //reading refreshes every 1 second

  lcd.clear(); //clears the lcd

  if (celsius > 50)
  {
    digitalWrite(7, 1);
    tone (7, 250, 100);
    delay(100);
    lcd.setCursor(8, 1);
    lcd.print("Too HOT");
  }
  else if (celsius < 50 && celsius >= 15)
  {
    digitalWrite(7, 0);
    lcd.setCursor(8, 1);
    lcd.print("Normal");
  }
  else if (celsius < 15)
  {
    digitalWrite(7, 0);
    lcd.setCursor(8, 1);
    lcd.print("Cold");
  }

}