
int valPot=0; //variable pour récupérer la tension aux bornes du potentiomètre traduite par le CAN . On l’initialise à 0.

int relay1 = 2;
int relay2 = 3;
int relay3 = 4;

int ledBlue = 9;
int ledRed1 = 10;
int ledRed2 = 11;

int redT = 200;
int blueT = 220;

long interval = 100;
  
int minValue = 60;  
int maxValue = 1023;


void color(int ratio_){

  if ( ratio_ <  redT) {
  analogWrite(ledRed1, LOW);
  analogWrite(ledRed2, LOW);
  }  
  else {
  analogWrite(ledRed1, 255. * (ratio_ - redT) / (maxValue - redT));
  analogWrite(ledRed2, 255. * (ratio_ - redT) / (maxValue - redT));
  }
  
  if (ratio_ < blueT) {
  
    analogWrite(ledBlue, 255. * (1. - 1. * ratio_ / blueT));
  }
  else { 
  analogWrite(ledBlue, LOW); 
  }
 /* if ( ratio_ < 0,5 * maxValue) {         
  analogWrite(ledBlue, 255. - 255*(double)ratio_ / (0.5 * maxValue));
  }  
  else {
  analogWrite(ledBlue, LOW);  
  }*/
  
  return;   
};

void setup() {
  
  Serial.begin(9600);

  pinMode(relay1, OUTPUT);   
  pinMode(relay2, OUTPUT); 
  pinMode(relay3, OUTPUT);   
  
  pinMode(ledBlue, OUTPUT);
  pinMode(ledRed1, OUTPUT);
  pinMode(ledRed2, OUTPUT);
  
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH);
  
 // Serial.begin(9600); //Initialisation de la communication avec la console

}


void loop() {

  valPot=analogRead(A0); //lit la tension, la convertit en valeur numérique et la stocke dans valeurPot

  Serial.println(valPot);
  
  int relayT1 = 255 + minValue;
  int relayT2 = 511 + minValue;
  int relayT3 = 767 + minValue;
  
  if ( valPot > relayT3) {
         digitalWrite(relay1, LOW);
         digitalWrite(relay2, LOW);
         digitalWrite(relay3, LOW);
         Serial.println("yolo");
         }
  if ( valPot > relayT2 && valPot <= relayT3 ) {
         digitalWrite(relay1, LOW);
         digitalWrite(relay2, LOW);
         digitalWrite(relay3, HIGH);       
         }
  if ( valPot > relayT1 && valPot <= relayT2) {
         digitalWrite(relay1, LOW);
         digitalWrite(relay2, HIGH);
         digitalWrite(relay3, HIGH);
         }   
  if ( valPot <= relayT1)  {
         digitalWrite(relay1, HIGH);
         digitalWrite(relay2, HIGH);
         digitalWrite(relay3, HIGH);
         }
   
  if ( valPot < 950 ){
      color(valPot); 
      delay(interval);
  }
  else {
    analogWrite(ledBlue, LOW);   
    analogWrite(ledRed1, HIGH);
    analogWrite(ledRed2, HIGH); 
    bool state = true;
    
    for (int t = 0 ; t < interval ; t += 50) {
      if (state == true) {
        analogWrite(ledRed1, 0);
        analogWrite(ledRed2, 0);
        state = false; 
      }   
      else {
        analogWrite(ledRed1, 255);
        analogWrite(ledRed2, 255);
        state = true;
      }
      delay(50);
    }  
  }  
         

}
