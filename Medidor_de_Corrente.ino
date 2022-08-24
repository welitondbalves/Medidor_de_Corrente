#include <EmonLib.h>

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
//int val = 0;

EnergyMonitor emon1;

#define SAMPLING_TIME 0.0001668649
#define LINE_FREQUENCY 60

#define VOLTAGE_AC 127.00
#define ACS_MPY 15.41

double Irms = 0;

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  emon1.current(1,ACS_MPY);
  // initialize the LCD
  //lcd.begin();
  lcd.init();

  // Turn on the blacklight and print a message.
  lcd.backlight();
  //lcd.print("Hello, world!");
}

void loop()
{
 Irms = emon1.calcIrms(1996);
  // Do nothing here...
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("Cor.: ");
 lcd.print(Irms);
 lcd.print("A");
 lcd.setCursor(0,1);
 lcd.print("Pot. Ap.: ");
 lcd.print(Irms*127);
 lcd.print("VA");
 delay(3000);
lcd.clear();
}
