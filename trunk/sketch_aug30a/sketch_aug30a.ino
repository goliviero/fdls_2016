
/*const int ledPin =  13;      // the number of the LED pin

// Variables will change:
int ledState = LOW;             // ledState used to set the LED
long previousMillis = 0;        // will store last time LED was updated

// the follow variables is a long because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long interval = 5000;           // interval at which to blink (milliseconds)

void setup() {
  // set the digital pin as output:
  pinMode(ledPin, OUTPUT);      
}

void loop()
{
  // here is where you'd put code that needs to be running all the time.

  // check to see if it's time to bl&ink the LED; that is, if the 
  // difference between the current time and last time you blinked 
  // the LED is bigger than the interval at which you want to 
  // blink the LED.
  unsigned long currentMillis = millis();
 
  if(currentMillis - previousMillis > interval) {
    // save the last time you blinked the LED 
    previousMillis = currentMillis;   

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW)
      ledState = HIGH;
    else
      ledState = LOW;

    // set the LED with the ledState of the variable:
    digitalWrite(ledPin, ledState);
  }
}*/

int valPot=0; //variable pour récupérer la tension aux bornes du potentiomètre traduite par le CAN . On l’initialise à 0.

int relay1 = 11;
int relay2 = 12;
int relay3 = 13;

int ledBlue = 2;
int ledRed1 = 3;
int ledRed2 = 4;


long interval = 500;
  
int maxValue = 1023;

void setup() {

  pinMode(relay1, OUTPUT);   
  pinMode(relay2, OUTPUT); 
  pinMode(relay3, OUTPUT);   
  
  pinMode(ledBlue, OUTPUT);
  pinMode(ledRed1, OUTPUT);
  pinMode(ledRed2, OUTPUT);
 // Serial.begin(9600); //Initialisation de la communication avec la console

}


void loop() {

  valPot=analogRead(A0); //lit la tension, la convertit en valeur numérique et la stocke dans valeurPot

  if ( valPot < (maxValue + 1) /8 ) {
         digitalWrite(relay1, LOW);
         digitalWrite(relay2, LOW);
         digitalWrite(relay3, LOW);
         
         digitalWrite(ledBlue, HIGH);
         digitalWrite(ledRed1, LOW);
         digitalWrite(ledRed2, LOW);
         
         }
  else if ( valPot < (maxValue + 1) * 2. / 4. ) {
         digitalWrite(relay1, HIGH);
         digitalWrite(relay2, LOW);
         digitalWrite(relay3, LOW);
         
         digitalWrite(ledBlue, HIGH);
         digitalWrite(ledRed1, HIGH);
         digitalWrite(ledRed2, LOW);         
         }
  else if ( valPot < (maxValue + 1) * 3. / 4. ) {
         digitalWrite(relay1, HIGH);
         digitalWrite(relay2, HIGH);
         digitalWrite(relay3, LOW);
         
         digitalWrite(ledBlue, LOW);
         digitalWrite(ledRed1, HIGH);
         digitalWrite(ledRed2, LOW); 
         }   
         
  else   {
         digitalWrite(relay1, HIGH);
         digitalWrite(relay2, HIGH);
         digitalWrite(relay3, HIGH);
        
         digitalWrite(ledBlue, LOW);
         digitalWrite(ledRed1, HIGH);
         digitalWrite(ledRed2, HIGH);                
         
         }      
         
  delay(interval);
}
