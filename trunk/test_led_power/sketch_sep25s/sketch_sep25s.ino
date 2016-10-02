#include <PWM.h>

int test = 7;
int test2 = 8;

int pwm1 = 10;
int pwm2 = 9;

int min_pwm = 0;
int max_pwm = 254;

const int frequency_1 = 3000; // 32500
const int frequency_2 = 3000;

int input_pwm = 0;

//the setup routine runs once when you press reset:
void setup() {                
  Serial.begin(9600);
  InitTimersSafe();
  pinMode(test, OUTPUT);
  pinMode(test2, OUTPUT);
  // initialize the digital pin as an output.
  pinMode(pwm1, OUTPUT);
  pinMode(pwm2, OUTPUT);
  //analogWrite(pwm1, min_pwm);
  //analogWrite(pwm2, min_pwm);
    
  pwmWrite(pwm1, max_pwm);
  pwmWrite(pwm2, min_pwm);
}

// the loop routine runs over and over again forever:
void loop() {
  /*analogWrite(pwm1, max_pwm);
  analogWrite(pwm2, min_pwm);
  delay(1000); 
  analogWrite(pwm1, min_pwm);
  analogWrite(pwm2, max_pwm);
  delay(1000);*/
  
  bool successA = SetPinFrequencySafe(pwm1, frequency_1);
  bool successB = SetPinFrequencySafe(pwm2, frequency_2);  
  
  input_pwm = analogRead(A0);
  Serial.println(input_pwm);
  delay(1000);
  /*
  for (int i = 0; i < 512; i++)
  {
    
    if (i < 170)
    {
      pwmWrite(pwm1, max_pwm -i);
      pwmWrite(pwm2, min_pwm);
    }
    else if (i >= 170 && i < 255)
    {
      pwmWrite(pwm1, max_pwm - i);
      pwmWrite(pwm2, min_pwm - 170 + i);
    }
    else if (i >= 255 && i < 425)
    {
      pwmWrite(pwm2, min_pwm - 170 + i);
      pwmWrite(pwm1, min_pwm);
    }
    else if (i >= 425)
    {
      pwmWrite(pwm1, min_pwm);
      pwmWrite(pwm2, 127);  
      bool success = SetPinFrequencySafe(pwm2, 4 + ((i - 425)/5));
    }
    
    delay(15);
    // Serial.println(i);
  }
  */
}
