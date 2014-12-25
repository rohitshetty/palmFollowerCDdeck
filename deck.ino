#include <NewPing.h>



#define TRIGGER_PIN 12
#define ECHO_PIN    11
#define MAX_DISTANCE 200

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup(){
Serial.begin(9600);

pinMode(2,OUTPUT);
pinMode(4,OUTPUT);
pinMode(7,OUTPUT);
digitalWrite(2,1);
}

void loop(){

delay(50);
unsigned int uS=sonar.ping();
unsigned dist = uS /US_ROUNDTRIP_CM;
Serial.println(dist);
if(dist >= 3 && dist < 20 ){
out();

}else if (dist < 3){
  in();
  
}
else{

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
