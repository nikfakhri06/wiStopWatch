#include <LiquidCrystal_I2C.h>

//#define button1 D7
const int button1 = D7;
int timerMode = 0;
unsigned long startTime, Sec, Min, Hour;
//String milliSec;

//set the LCD address to 0x27
LiquidCrystal_I2C lcd(0x27,16,2);

void setup()
{

  //Setup push button
  pinMode(button1, INPUT);

  //setup LCD
  lcd.init();
  lcd.clear();
  lcd.backlight();

  //write on LCD
  lcd.setCursor(0,0);
  lcd.print("Press to start");

  Serial.begin(9600);
  
}

void loop()
{
  stopWatch();

}  

void stopWatch() //function
{
      if (digitalRead(button1) == HIGH)
  {
    startTime = millis();
    timerMode++;
    delay(400);
  }
  if (timerMode == 1)
    {
      lcd.setCursor(0,0);
      lcd.print("Task In Progress");
      lcd.setCursor(0,1);

      //formula to change time format from milisec to hour
//      milliSec = String((millis() - startTime) % 1000);
      Sec = ((millis() - startTime) / 1000) % 60;
      Min = ((millis() - startTime) / 60000) % 60;
      Hour = ((millis() - startTime) / 3600000) % 60;

//print 00h:00m:00.00s to LCD
      if(Hour < 10)
    {
      lcd.print("0"); 
      lcd.print(Hour);
      lcd.print("h");
    }
    else 
    lcd.print(Hour);
    lcd.print(":");

      if(Min < 10)
    {
      lcd.print("0"); 
      lcd.print(Min);
      lcd.print("m");
    }
    else 
    lcd.print(Min);
    lcd.print(":");

      if (Sec < 10)
  {
    lcd.print("0");
    lcd.print(Sec);
  }
  else
  lcd.print(Sec);
//  lcd.print(".");
//  lcd.print(milliSec[0]); 
//  lcd.print(milliSec[1]);
  lcd.print(" s");
    }
    
    if (timerMode > 1)
        {
          delay(2000);
          timerMode = 0;
          lcd.clear();
          lcd.print("Press to Start");
        }
}
