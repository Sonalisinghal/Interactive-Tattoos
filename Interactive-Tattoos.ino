#include <CapacitiveSensor.h>
// declaring R,G,B pins
#define RED_PIN 9
#define GREEN_PIN 8
#define BLUE_PIN 10
int Brightness_R;
int Brightness_G;
int Brightness_B; 
const int buzzer = 11; //buzzer to arduino pin 9    
CapacitiveSensor   cs_2_3 = CapacitiveSensor(2,3);
CapacitiveSensor   cs_4_5 = CapacitiveSensor(4,5);
CapacitiveSensor   cs_6_7 = CapacitiveSensor(6,7);
void setup(){
  pinMode(buzzer, OUTPUT); // Set buzzer - pin 11 as an output
  // setting up R,G,B pins
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  //declaring maximum brightness levels
  Brightness_R = 255;
  Brightness_G = 255;
  Brightness_B = 255;
  //setting up touch sensors
  cs_2_3.set_CS_AutocaL_Millis(0xFFFFFFFF);
  Serial.begin(9600);
  cs_4_5.set_CS_AutocaL_Millis(0xFFFFFFFF);
  Serial.begin(9600);
  cs_6_7.set_CS_AutocaL_Millis(0xFFFFFFFF);
  Serial.begin(9600);
}

void loop(){
  // setting up sensor variables 
   long sensor2 =  cs_2_3.capacitiveSensor(50);
   long sensor3 =  cs_4_5.capacitiveSensor(50);
   long sensor4 =  cs_6_7.capacitiveSensor(50);
   if(sensor2 >= 50){
      tone(buzzer, 1500);  // playing the buzzer at 1500Hz frequency
      delay(500);
      noTone(buzzer);      // turning the tone of the buzzer off.
      // Setting up the lights
      analogWrite (RED_PIN, 0); 
      analogWrite (GREEN_PIN, 0);
      analogWrite (BLUE_PIN, Brightness_B);
      Serial.println("2");    
      delay(500);
   }
   else if(sensor3 >= 50){
      tone(buzzer, 1000); 
      delay(500);        
      noTone(buzzer);     
      delay(10);
      analogWrite (RED_PIN, 0); 
      analogWrite (GREEN_PIN, 0);
      analogWrite (BLUE_PIN, Brightness_B);
      Serial.println("3");
      delay(500);
   }
   else if(sensor4 >= 50){
      tone(buzzer, 500); 
      delay(500);        
      noTone(buzzer);     
      delay(10);
      Serial.println("4");      
      analogWrite (RED_PIN, 0); 
      analogWrite (GREEN_PIN, 0);
      analogWrite (BLUE_PIN, Brightness_B);
      delay(500); 
   }
   else{
    Serial.println("0");
    analogWrite (RED_PIN,0);
    analogWrite (GREEN_PIN, 0);
    analogWrite (BLUE_PIN, 0);
    delay(500);
   }
}
