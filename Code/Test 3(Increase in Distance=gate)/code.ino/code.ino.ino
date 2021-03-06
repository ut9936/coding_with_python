  #include <NewPing.h>
int relay1=2;
int relay2=3;
int relay3=4;
int relay4=5;
int echo_front=6;
int trig_front=7;
int echo_left=8;
int trig_left=9;
int echo_right=10;
int trig_right=11;
NewPing front(trig_front, echo_front, 500);
NewPing left(trig_left, echo_left, 500);
NewPing right(trig_right, echo_right, 500);

long dFront,dLeft,dRight,dFrontOld,dLeftOld,dRightOld;
  
void setup()
{
  Serial.begin(115200);
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
    if(dFront-dFrontOld<=10 && dRight-dRightOld<=10 && dLeft-dLeftOld<=10)
    {
      
    if(dFront>5)
    {
      forward();
      delay(50);
    }
    else if (dLeft>5) 
    {
      stop1();
      delay(100);
      turnLeft();
      delay(50);
    }
     else if (dRight>5) 
    {
      stop1();
      delay(100);
      turnRight();
      delay(50);
    }

    }
    else if(dFront-dFrontOld>10)
    {
      forward();
      delay(50);
    }
     else if(dLeft-dLeftOld>10)
    {
      turnLeft();
      delay(50);
    }
     else if(dRight-dRightOld<=10)
    {
      turnRight();
      delay(50);
    }
    dFrontOld = dFront;
    dRightOld = dRight;
    dLeftOld = dLeft;
    
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
digitalWrite(relay1,HIGH); 
digitalWrite(relay2,LOW);
digitalWrite(relay3,LOW);
digitalWrite(relay4,HIGH);
Serial.println("Forward");

}

void stop1()
{
digitalWrite(relay1,LOW); 
digitalWrite(relay2,LOW);
digitalWrite(relay3,LOW);
digitalWrite(relay4,LOW);
Serial.println("stop");
}

void turnLeft()
{
digitalWrite(relay1,LOW); 
digitalWrite(relay2,HIGH);
digitalWrite(relay3,LOW);
digitalWrite(relay4,HIGH);
Serial.println("turnLeft");
}

void turnRight()
{
digitalWrite(relay1,HIGH); 
digitalWrite(relay2,LOW);
digitalWrite(relay3,HIGH);
digitalWrite(relay4,LOW);
Serial.println("turnRight");
}
