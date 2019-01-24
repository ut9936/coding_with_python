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

long time_front,distance_front,minimum_front,distance_left,minimum_left,time_left,distance_right,minimum_right,time_right;
  
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
    forward_robot();
    Serial.println("Robot Forward");
    
    
    if(distance_front<=minimum_front)
    {
      tern_left();
      
    }
    if(distance_front<=minimum_front && distance_left<=minimum_left)
    {
       tern_right();
    
    }
    if(distance_front<=minimum_front && distance_right<=minimum_right)
    {
      tern_left();
    }
    if(distance_front<=minimum_front && distance_left<=minimum_left && distance_right<=minimum_right)
    {
      stop_robot();
    }
    delay(50);
}

void sensor_front()
{
distance_front=front.ping_cm();
minimum_front=20;
Serial.println(distance_front);
  
}

void sensor_left()
{
distance_left=left.ping_cm();
Serial.println(distance_left);
minimum_left=20; 
}

void sensor_right()
{
distance_right=right.ping_cm();
minimum_right=20; 
Serial.println(distance_right);
}

void forward_robot()
{
 digitalWrite(relay1,HIGH); 
 digitalWrite(relay2,LOW);
 digitalWrite(relay3,LOW);
 digitalWrite(relay4,HIGH);

}

void stop_robot()
{
 digitalWrite(relay1,LOW); 
 digitalWrite(relay2,LOW);
 digitalWrite(relay3,LOW);
 digitalWrite(relay4,LOW);
 
}

void tern_left()
{
 digitalWrite(relay1,LOW); 
 digitalWrite(relay2,HIGH);
 digitalWrite(relay3,LOW);
 digitalWrite(relay4,HIGH);
 
}

void tern_right()
{
 digitalWrite(relay1,HIGH); 
 digitalWrite(relay2,LOW);
 digitalWrite(relay3,HIGH);
 digitalWrite(relay4,LOW);
 
}
