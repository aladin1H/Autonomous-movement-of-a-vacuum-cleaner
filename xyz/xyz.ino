#include <NewPing.h>
NewPing eye(11, 12, 30); //(Trig, echo, max) 

const int ENA = 3;
const int ENB = 5;

const int IN1 = 6;
const int IN2 = 7;
const int IN3 = 8;
const int IN4 = 9;

const int IR = 10;
const int IR2 = 4;

int NowhereToGo = 0;

const int biggerMovingTime = 1000; //in ms
const int movingTime = 750;    //in ms
const int backTime = 300;      //in ms 
const int Dist = 12;           //in cm
const int walk = 70;          //PWM speed
const int xtra = 15;          //for balance to make straight
const int turnHigh = 130;
const int turnLow = 20;        //PWM speed



void goForward() {
  analogWrite(ENA, walk);
  analogWrite(ENB, walk+xtra);
  
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}





void There() {

     delay(500);
     //get_back
     analogWrite(ENA, 90);
     analogWrite(ENB, 90);
      
     digitalWrite(IN1, LOW);
     digitalWrite(IN2, HIGH);
     digitalWrite(IN3, LOW);
     digitalWrite(IN4, HIGH);
     delay(backTime);
     
     delay(500);
     //turn_left
     analogWrite(ENA, turnLow);
     analogWrite(ENB, turnHigh);
      
     digitalWrite(IN1, LOW);
     digitalWrite(IN2, HIGH);
     digitalWrite(IN3, HIGH);
     digitalWrite(IN4, LOW);
     delay(movingTime);
     
     analogWrite(ENA, 0);
     analogWrite(ENB, 0);

     int distance = eye.ping_cm();
     Serial.println(distance);
     if(distance > Dist || distance == 0) {
        return;
     }
     
     delay(500);
     //turn_right
     analogWrite(ENA, turnHigh);
     analogWrite(ENB, turnLow);
      
     digitalWrite(IN1, LOW);
     digitalWrite(IN2, HIGH);
     digitalWrite(IN3, LOW);
     digitalWrite(IN4, HIGH);
     delay(biggerMovingTime);

     analogWrite(ENA, 0);
     analogWrite(ENB, 0);
     
    distance = eye.ping_cm();
    Serial.println(distance);
    if(distance > Dist || distance == 0 ) {
      return;
    }
    
    else {
      NowhereToGo = 1;
    } 
}







void setup() {
  Serial.begin(9600);

  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);
  pinMode (ENA, OUTPUT);
  pinMode (ENB, OUTPUT);

  pinMode(IR, INPUT);
  pinMode(IR2, INPUT);

}


void downfall() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  delay(1000);

  analogWrite(ENA, walk);
  analogWrite(ENB, walk);
  delay(500);
      
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(2*movingTime);

  analogWrite(ENA, 0);
  analogWrite(ENB, 0); 
}




void loop() {

  NowhereToGo = 0;
  
  int distance = eye.ping_cm();
  Serial.println(distance);
  
  if(distance > 0 && distance <= Dist){
     analogWrite(ENA, 0);
     analogWrite(ENB, 0);
     Serial.println("Warning");

     There();
  }

  

  else if (1) {
    int IRStatus = digitalRead(IR);
     if (IRStatus == 0) {            //0 means obstacle
        analogWrite(ENA, 0);
        analogWrite(ENB, 0);
        Serial.println("Obstacle");

        There();
     }
     else {
        Serial.println("No Obstacle");
     }
  }



  if(1) {
    int IRStatus2 = digitalRead(IR2);
     if (IRStatus2 == 1) {            //1 means no obstacle
        Serial.println("Obstacle");
        downfall();
     }
     else {
        Serial.println("No Obstacle");
     }
  }

  
  
  if(!NowhereToGo) {
    Serial.println("Go");
    goForward();
  }
  else {
     Serial.println("Nowhere to go");
     analogWrite(ENA, 0);
     analogWrite(ENB, 0);
  }
}
