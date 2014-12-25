#include <NewPing.h>

/*
PIN2 enable always keep high
PIN4 to motor drive input
PIN7 Another motor drive input
PIN4, PIN7 =(1,0) IN deck
PIN4, PIN7 =(0,1) OUT Deck
*/

#define TRIGGER_PIN 12
#define ECHO_PIN    11
#define MAX_DISTANCE 200

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup(){
Serial.begin(9600); //For debuggin 

pinMode(2,OUTPUT);
pinMode(4,OUTPUT);
pinMode(7,OUTPUT);
digitalWrite(2,1);
}

void loop(){

delay(50);
unsigned int uS=sonar.ping();
unsigned dist = uS /US_ROUNDTRIP_CM;
Serial.println(dist); //Debug em all 
if(dist >= 6 && dist < 20 ){
out();
}else if (dist < 4 && dist > 0.1 ){
  in();
}
else{
//This is Safe Zone
}
}

void in(){
digitalWrite(7,0);
digitalWrite(4,1);
delay(350);
digitalWrite(4,0);
}
void out(){
digitalWrite(7,1);
digitalWrite(4,0);
delay(350);
digitalWrite(7,0);

}
