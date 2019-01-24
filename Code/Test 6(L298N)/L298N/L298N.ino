#include <NewPing.h>
const int LeftMotorForward = 2;
const int LeftMotorBackward = 3;
const int RightMotorForward = 4;
const int RightMotorBackward = 5;
int echo_front=6;
int trig_front=7;
int echo_left=8;
int trig_left=9;
int echo_right=10;
int trig_right=11;
NewPing front(trig_front, echo_front, 500);
NewPing left(trig_left, echo_left, 500);
NewPing right(trig_right, echo_right, 500);

long dFront,dLeft,dRight;
  
void setup()
{
  Serial.begin(115200);
  pinMode(trig_front,OUTPUT);
  pinMode(echo_front,INPUT);
  pinMode(trig_left,OUTPUT);
  pinMode(echo_left,INPUT);
  pinMode(trig_right,OUTPUT);
  pinMode(echo_right,INPUT);
  pinMode(LeftMotorForward, OUTPUT);
  pinMode(LeftMotorBackward, OUTPUT);
  pinMode(RightMotorForward, OUTPUT);
  pinMode(RightMotorBackward, OUTPUT);
}

void loop() 
{
      
    sensor_front();
    sensor_left();
    sensor_right();
    if(dFront<=200 && dRight<=200 && dLeft<=200)
    {
      
    if(dFront>20)
    {
      forward();
      delay(5);
    }
    else if (dLeft>20) 
    {
      turnLeft();
      delay(5);
    }
     else if (dRight>20) 
    {
      turnRight();
      delay(5);
    }

    }
    else if(dFront>200)
    {
      forward();
      delay(5);
    }
     else if(dLeft>200)
    {
      turnLeft();
      delay(5);
    }
     else if(dRight>200)
    {
      turnRight();
      delay(5);
    }
}

void sensor_front()
{
dFront=front.ping_cm();
Serial.println(dFront);
  
}

void sensor_left()
{
dLeft=left.ping_cm();
Serial.println(dLeft);
}

void sensor_right()
{
dRight=right.ping_cm();
Serial.println(dRight);
}

void forward()
{
  digitalWrite(RightMotorForward, HIGH);
  digitalWrite(RightMotorBackward, LOW);
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(LeftMotorBackward, LOW);
}

void stop1()
{
  digitalWrite(RightMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(LeftMotorBackward, LOW);
}

void turnLeft()
{
  digitalWrite(RightMotorForward, HIGH);
  digitalWrite(RightMotorBackward, LOW);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(LeftMotorBackward, HIGH);
}

void turnRight()
{
  digitalWrite(RightMotorForward, LOW);
  digitalWrite(RightMotorBackward, HIGH);
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(LeftMotorBackward, LOW);
}
