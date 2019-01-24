#include <NewPing.h>
int relay1=3;
int relay2=2;
int relay3=5;
int relay4=4;
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

  pinMode(trig_front,OUTPUT);
  pinMode(echo_front,INPUT);
  pinMode(trig_left,OUTPUT);
  pinMode(echo_left,INPUT);
  pinMode(trig_right,OUTPUT);
  pinMode(echo_right,INPUT);
  pinMode(relay1,OUTPUT);
  pinMode(relay2,OUTPUT);
  pinMode(relay3,OUTPUT);
  pinMode(relay4,OUTPUT);
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
      delay(20);
    }
    else if (dLeft>20) 
    {
      stop1();
      delay(20);
      turnLeft();
      delay(20);
    }
     else if (dRight>20) 
    {
       stop1();
      delay(20);
      turnRight();
      delay(20);
    }

    }
    else if(dFront>200)
    {
      forward();
      delay(20);
    }
     else if(dLeft>200)
    {
      stop1();
      delay(20);
      turnLeft();
      delay(20);
    }
     else if(dRight>200)
    {
    stop1();
      delay(20);
      turnRight();
      delay(20);
    }
}

void sensor_front()
{
dFront=front.ping_cm();
  
}

void sensor_left()
{
dLeft=left.ping_cm();
}

void sensor_right()
{
dRight=right.ping_cm();
}

void forward()
{
digitalWrite(relay1,HIGH); 
digitalWrite(relay2,LOW);
digitalWrite(relay3,LOW);
digitalWrite(relay4,HIGH);

}

void stop1()
{
digitalWrite(relay1,LOW); 
digitalWrite(relay2,LOW);
digitalWrite(relay3,LOW);
digitalWrite(relay4,LOW);
}

void turnLeft()
{
digitalWrite(relay1,LOW); 
digitalWrite(relay2,HIGH);
digitalWrite(relay3,LOW);
digitalWrite(relay4,HIGH);
}

void turnRight()
{
digitalWrite(relay1,HIGH); 
digitalWrite(relay2,LOW);
digitalWrite(relay3,HIGH);
digitalWrite(relay4,LOW);
}
