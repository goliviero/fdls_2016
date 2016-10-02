
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
#include <PWM.h>

#define I2C_ADDR    0x3F // <<----- Add your address here.  Find it from I2C Scanner
#define BACKLIGHT_PIN     3
#define En_pin  2
#define Rw_pin  1
#define Rs_pin  0
#define D4_pin  4
#define D5_pin  5
#define D6_pin  6
#define D7_pin  7

int n = 1;
int valpot = 0;

int valpot_min = 0;
int valpot_max = 1023;

int temp_min = 20;
int temp_max = 1500;

int temp = 600;

int output_pin = 3;

LiquidCrystal_I2C	lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);

const int frequency_pwm_output = 20000000;

void setup()
{
  pinMode(output_pin, OUTPUT);
  bool success = SetPinFrequencySafe(output_pin, frequency_pwm_output);
  lcd.begin (16,2); //  <<----- My LCD was 16x2

 
// Switch on the backlight
lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
lcd.setBacklight(HIGH);
lcd.home (); // go home

 lcd.print("Barres :    "); 
  lcd.setCursor(0,1);   
 lcd.print("TEMP   :"); 
}

void loop()
{
 valpot = analogRead(A0);
 if (temp >= temp_min && temp <= temp_max){
    if (valpot < valpot_max / 3) {
     temp -= 6 - valpot/68;
     if (temp < temp_min) {
   temp = temp_min;
   } 
    }
    else if (valpot >= valpot_max / 3 && valpot < 2*valpot_max/3) {
    }
    else if (valpot >= 2*valpot_max / 3) {
      temp += 1 + (valpot-2*valpot_max/3)/68;
      if (temp > temp_max) {
   temp = temp_max;
   } 
    }
   }
    

 
 // Backlight on/off every 3 seconds
 lcd.setCursor(9,0);        // go to start of 2nd line
 lcd.print("       ");
 lcd.setCursor(9,0);
 lcd.print(valpot*100./valpot_max);
 lcd.setCursor(14,0);
 lcd.print("%  ");  
 
 lcd.setCursor(9,1);        // go to start of 2nd line
 lcd.print("         ");
 lcd.setCursor(9,1);
 lcd.print(temp);
 
 analogWrite(output_pin,255.*(temp-temp_min)/(temp_max-temp_min));
 //lcd.print(n++,DEC);
 delay(200);
}






/*int minValue = 0;  
int maxValue = 1023;

int valPot = 0;

void setup() {
  
  Serial.begin(9600);
  
}
void loop() {

  valPot=analogRead(A0); //lit la tension, la convertit en valeur numérique et la stocke dans valeurPot

  Serial.println(valPot);
  
}*/
