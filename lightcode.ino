int servint = 7;
int counterint = 6;
int output = 13;
int manvar = 0;
int countvar = 0;
int aprev=LOW;
int bprev=LOW;
int a;
int b;

void setup() {
  // put your setup code here, to run once:
  pinMode(servint, INPUT);
  pinMode(counterint, INPUT);
  pinMode(output, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int x = analogRead(A1) - analogRead(A0);
  int y = analogRead(A4) - analogRead(A3);
  Serial.println(x);
  Serial.println(y);
  if(y>500)
  {
    //Serial.println("dimaag mat khatab kar");
    a=HIGH;
  }
  else if(y<100)
  {
    //Serial.println("dimaag mat khatab kar baar baar");
    a=LOW;
  }
  
  //Serial.println(y);
  if(x>800)
  {
    b=HIGH;
  }
  else if(x<200)
  {
    b=LOW;
  }
//  Serial.print("a: ");
//  Serial.println(a);
//  Serial.print("b: ");
//  Serial.println(b);
//  Serial.println(manvar); 
  if(a==LOW && b==LOW)
  {
    digitalWrite(output, LOW);
    countvar = 0;
    manvar = 0;
  }
  else if(a==HIGH && b==LOW)
  {
    if(bprev==HIGH)
    {
      digitalWrite(output, LOW);
      countvar = 1;
    }
    else if(countvar==1)
    {
      digitalWrite(output, LOW);
    }
    else
    {
      digitalWrite(output, HIGH);
      countvar = 0;
    }
  }
  else if(a==LOW && b==HIGH)
  {
    if(aprev == HIGH)
    {
      digitalWrite(output, LOW);
      manvar = 1;
    }
    else if(manvar==1)
    {
      digitalWrite(output, LOW);
    }
    else
    {
      digitalWrite(output, HIGH);
      manvar = 0;
    }
  }
  else
  {
    digitalWrite(output, HIGH);
    countvar = 0;
    manvar = 0;
  }
  aprev = a;
  bprev = b;
  delay(500);
}
