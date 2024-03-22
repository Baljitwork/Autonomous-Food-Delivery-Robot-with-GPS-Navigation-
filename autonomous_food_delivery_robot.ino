const int trigPin_1 = 7;
const int echoPin_1 = 6;
const int trigPin_2 = 5;
const int echoPin_2 = 4;
const int trigPin_3 = 3;
const int echoPin_3 = 2;
const int buzzer =8;
long duration;
int distance;
int safetyDistance;
int m1a = 9;
int m1b = 10;
int m2a = 11;
int m2b = 12;
char val;

void setup() 
{
pinMode(trigPin_1, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin_1, INPUT);// Sets the echoPin as an Input
pinMode(trigPin_2, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin_2, INPUT);// Sets the echoPin as an Input
pinMode(trigPin_3, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin_3, INPUT);// Sets the echoPin as an Input
pinMode(buzzer, OUTPUT);    
pinMode(m1a, OUTPUT);  // Digital pin 10 set as output Pin
pinMode(m1b, OUTPUT);  // Digital pin 11 set as output Pin
pinMode(m2a, OUTPUT);  // Digital pin 12 set as output Pin
pinMode(m2b, OUTPUT); // Digital pin 13 set as output Pin
Serial.begin(9600);
}

void loop()
{ 
  left();
  right();
  forward();
  while (Serial.available() > 0)
  {
  val = Serial.read();
  Serial.println(val);
  }

  if( val == 'F') // Forward
    {
      digitalWrite(m1a, HIGH);
      digitalWrite(m1b, LOW);
      digitalWrite(m2a, HIGH);
      digitalWrite(m2b, LOW);  
      Serial.println("F");
    }
  else if(val == 'B') // Backward
    {
      digitalWrite(m1a, LOW);
      digitalWrite(m1b, HIGH);
      digitalWrite(m2a, LOW);
      digitalWrite(m2b, HIGH); 
      Serial.println("B");
    }
  
    else if(val == 'L') //Left
    {
    digitalWrite(m1a, LOW);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, HIGH);
    digitalWrite(m2b, LOW);
     Serial.println("L");
    }
    else if(val == 'R') //Right
    {
    digitalWrite(m1a, HIGH);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, LOW);
    digitalWrite(m2b, LOW); 
     Serial.println("R");
    }
    
  else if(val == 'S') //Stop
    {
    digitalWrite(m1a, LOW);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, LOW);
    digitalWrite(m2b, LOW); 
    }
  else if(val == 'I') //Forward Right
    {
    digitalWrite(m1a, HIGH);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, LOW);
    digitalWrite(m2b, LOW);
    }
  else if(val == 'J') //Backward Right
    {
    digitalWrite(m1a, LOW);
    digitalWrite(m1b, HIGH);
    digitalWrite(m2a, LOW);
    digitalWrite(m2b, LOW);
    }
   else if(val == 'G') //Forward Left
    {
    digitalWrite(m1a, LOW);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, HIGH);     digitalWrite(m2b, LOW);
    }
  else if(val == 'H') //Backward Left
    {
    digitalWrite(m1a, LOW);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, LOW);
    digitalWrite(m2b, HIGH); 
    }
}
void left()
{
digitalWrite(trigPin_1, LOW);
delayMicroseconds(2);
 
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin_1, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin_1, LOW);
 
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin_1, HIGH);
 
// Calculating the distance
distance= duration*0.034/2;
 
safetyDistance = distance;
if (safetyDistance <= 20)   // You can change safe distance from here changing value Ex. 20 , 40 , 60 , 80 , 100, all in cm
{
  digitalWrite(buzzer, HIGH);
}
else{
  digitalWrite(buzzer, LOW);
}
 
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
    
}
void right()
{
digitalWrite(trigPin_2, LOW);
delayMicroseconds(2);
 
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin_2, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin_2, LOW);
 
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin_2, HIGH);
 
// Calculating the distance
distance= duration*0.034/2;
 
safetyDistance = distance;
if (safetyDistance <= 20)   // You can change safe distance from here changing value Ex. 20 , 40 , 60 , 80 , 100, all in cm
{
  digitalWrite(buzzer, HIGH);
}
else{
  digitalWrite(buzzer, LOW);
}
 
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
    
}
void forward()
{
digitalWrite(trigPin_3, LOW);
delayMicroseconds(2);
 
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin_3, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin_3, LOW);
 
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin_3, HIGH);
 
// Calculating the distance
distance= duration*0.034/2;
 
safetyDistance = distance;
if (safetyDistance <= 20)   // You can change safe distance from here changing value Ex. 20 , 40 , 60 , 80 , 100, all in cm
{
  digitalWrite(buzzer, HIGH);
}
else{
  digitalWrite(buzzer, LOW);
}
 
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
    
}
