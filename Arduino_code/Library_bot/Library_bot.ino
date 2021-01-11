/**************Laibrary Book Maneger************/
//H bridge code for controlling motor
//H Motor code pin config
#define h1 2
#define h2 3
#define h3 4
#define h4 5
//L Motor code pin config
#define l1 6
#define l2 7
#define l3 8
#define l4 9
#define Bump 11
//servo pin
#define SERVO_PIN 10
//int pin = 12;
int pos=0,button=1;
int color;
void forward();
void backward();
void motorStop();
void servoAngle();
void setup() {
// put your setup code here, to run once:
Serial.begin(9600);
Serial.println("Strat");
pinMode(h1,OUTPUT);
pinMode(h2,OUTPUT);
pinMode(h3,OUTPUT);
pinMode(h4,OUTPUT);
pinMode(l1,OUTPUT);
pinMode(l2,OUTPUT);
pinMode(l3,OUTPUT);
pinMode(l4,OUTPUT);
pinMode(10,OUTPUT);
pinMode(Bump,INPUT);
//pullup
digitalWrite(h1,HIGH);
digitalWrite(h2,HIGH);
digitalWrite(h3,HIGH);
digitalWrite(h4,HIGH);
digitalWrite(l1,HIGH);
digitalWrite(l2,HIGH);
digitalWrite(l3,HIGH);
digitalWrite(l4,HIGH);
//pinMode(pin, OUTPUT);
//attachInterrupt(digitalPinToInterrupt(pin), allstop, LOW);
//servo pin
//myservo.attach(SERVO_PIN);
//interupt to save the overflow
//attachInterrupt(0,allstop,LOW);
//Serial.begin(9600);
}
/************************Main
Loop****************************/
void loop() {
//readColor();
//servoAngle(20);
//analogWrite(SERVO_PIN,20);
//testing
button=digitalRead(Bump);
if(button==0)
{
readColor();
//Serial.println(color);
if(color==2)
{
delay(3000);
Serial.println("1st");
analogWrite(SERVO_PIN,20);
forwardl();
delay(3000);
motorStopl();
delay(1000);
//lose
delay(500);
//pull
analogWrite(SERVO_PIN,200);
backwardl();
delay(3000);
motorStopl();
delay(1000);
color=0;
button=1;
//return;
}
if(color==3)
{
delay(3000);
Serial.println("2st");
forwardh();
delay(2200);
motorStoph();
delay(1000);
//grip
analogWrite(SERVO_PIN,20);
delay(500);
//push
forwardl();
delay(3000);
motorStopl();
delay(1000);
//lose
analogWrite(SERVO_PIN,200);
delay(500);
//pull
backwardl();
delay(3000);
motorStopl();
delay(1000);
//down
backwardh();
delay(1300);
motorStoph();
delay(1000);
color=0;
button=1;
// return;
}
if(color==1)
{
delay(3000);
Serial.println("3st");
forwardh();
delay(4000);
motorStoph();
delay(1000);
//grip
analogWrite(SERVO_PIN,20);
delay(500);
//push
forwardl();
delay(3000);
motorStopl();
delay(1000);
//lose
analogWrite(SERVO_PIN,200);
delay(500);
//pull
backwardl();
delay(3000);
motorStopl();
delay(1000);
//down
backwardh();
delay(2250);
motorStoph();
delay(1000);
color=0;
button=1;
//return;
}
/************Testing***************
//Servo
servoAngle(150);
/***Height****
forwardh();
delay(3000);
motorStoph();
delay(1000);
//backwardh();
delay(1000);
motorStoph();
delay(1000);
/****Length
forwardl();
delay(2000);
motorStopl();
delay(1000);
backwardl();
delay(2000);
motorStopl();
delay(1000);
**/
}
else
{
Serial.println("No BOOK");
}
}//Loop ends here
/********FUNCTIONS**********/
//**********Hight
void forwardh()
{
digitalWrite(h3,HIGH);
digitalWrite(h2,HIGH);
digitalWrite(h1,LOW);
digitalWrite(h4,LOW);
}
void backwardh()
{
digitalWrite(h1,HIGH);
digitalWrite(h4,HIGH);
digitalWrite(h3,LOW);
digitalWrite(h2,LOW);
}
void motorStoph()
{
digitalWrite(h1,HIGH);
digitalWrite(h2,HIGH);
digitalWrite(h3,HIGH);
digitalWrite(h4,HIGH);
}
//********************length
void forwardl()
{
digitalWrite(l3,HIGH);
digitalWrite(l2,HIGH);
digitalWrite(l1,LOW);
digitalWrite(l4,LOW);
}
void backwardl()
{
digitalWrite(l1,HIGH);
digitalWrite(l4,HIGH);
digitalWrite(l3,LOW);
digitalWrite(l2,LOW);
}
void motorStopl()
{
digitalWrite(l1,HIGH);
digitalWrite(l2,HIGH);
digitalWrite(l3,HIGH);
digitalWrite(l4,HIGH);
}
//*****************servo
void servoAngle(int pos)
{
//myservo.write(pos); // tell servo to go to position in variable 'pos'
delay(100); // waits 15ms for the servo to reach the position
}
//************Read Color
void readColor()
{
int x=analogRead(A0);
Serial.print("\t\t");
Serial.println(x);
if(x<805 && x>750)
{
Serial.println("White ");
color=1;
}
else if(x<735 && x>710)
{
Serial.println("red");
color=2;
}
else if(x<690)
{
Serial.println("Black");
color=3;
}
}
void allstop()
{
Serial.println("all stop");
while(1);
}
