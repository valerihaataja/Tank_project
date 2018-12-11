
#include <SoftwareSerial.h>           
#include <AFMotor.h>
#include <Servo.h>
Servo servo;
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);
int bluetoothTx = 0;
int bluetoothRx = 1;
int input;
int sensorPin = A0;
int sensorValue = 0;
const int led1 = 13;
const int trigPin = 5;
const int echoPin = 10;
long kesto;
int etaisyys;

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

void ajovalot()
{
    sensorValue = analogRead(sensorPin);
    delay(5);
    if(sensorValue < 400)
{
    digitalWrite(led1, HIGH);
}
    else
{
    digitalWrite(led1, LOW);
    Serial.print("sensoriarvo:");
    Serial.println(sensorValue);
    delayMicroseconds(100);
}
}


/*void ultra()
{
    digitalWrite(trigPin, LOW);
    delayMicroseconds(20);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(100);
    digitalWrite(trigPin, LOW);
    kesto = pulseIn(echoPin, HIGH);
    etaisyys = kesto*0.034/2;
    if(etaisyys > 100)
    {
      etaisyys = 100;
    }
}
*/   
    

void eteen()
{
    motor3.setSpeed(255);
    motor3.run(FORWARD);
    motor4.setSpeed(255);
    motor4.run(BACKWARD);
}
void pysaytys()
{
    motor3.run(RELEASE);
    motor4.run(RELEASE);
}
void taakse()
{
    motor3.setSpeed(255);
    motor3.run(BACKWARD);
    motor4.setSpeed(255);
    motor4.run(FORWARD);
}
void oikealle()
{
    motor3.setSpeed(230);
    motor3.run(FORWARD);
    motor4.setSpeed(2
    30);
    motor4.run(FORWARD);
}
void vasemmalle()
{
    motor3.setSpeed(230);
    motor3.run(BACKWARD);
    motor4.setSpeed(230);
    motor4.run(BACKWARD);
}
  
void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  servo.attach(9);
  Serial.begin(57600);
  bluetooth.begin(57600);
  Serial.flush();
  input = 90;
  pinMode(led1, OUTPUT);
}

void loop()
{
    
    
    /*ultra();*/
    ajovalot();
    
    
  if (bluetooth.available() > 0)
  {
    
    input = bluetooth.read();
    delay(5);
    Serial.println(input);


    

 
  if (input <= 180)
  {
    servo.write(input);
  }

  if (input == 190)
  {
    pysaytys();
  }


  if (input == 186)
  {
    eteen();

  }
  if (input == 187)
  {
    taakse();
  }
  if (input == 188)
  {
    oikealle();
  }
  if (input == 189)
  {
    vasemmalle();
  }
  }
}







