#include<Servo.h> 
int servoPin = 10;
Servo servo;
void setup() {
  pinMode(servoPin , OUTPUT);
  
  servo.attach(servoPin);
  Serial.begin(9600);
  servo.write(45);
  delay(1000);

}

// fr : A0
// webLock : A1
// GND : A2
int fr , wl , frP , wlP;
//frP = 0;
//wlP = 0;
int aprev;
int bprev;
int state = 1; //lock : 0 , unlock : 1
void loop() {
  int a = analogRead(A1) - analogRead(A2);
  int b = analogRead(A0) - analogRead(A2);
  Serial.println(a);
  Serial.println(b);
  if (state == 0)
  {
    if(b>450 && bprev<100)
    {
      servo.write(45);
      //delay(2000);
      state = 1;
    }
    if(a < 100)
    {
      servo.write(45);
      //delay(2000);
      state = 1;
    }
  }
  else if (state == 1)
  {
    
    if (aprev<100 && a>450)
    // Lock
    {
      servo.write(125);
      //delay(2000);
      state = 0;
    }
    
    
  }

  aprev = a;
  bprev = b;
  Serial.println(state);
  //delay(500);


  

}
