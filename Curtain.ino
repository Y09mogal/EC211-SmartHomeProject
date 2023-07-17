int R_PWM = 11;
int L_PWM = 10;
int input = 7;
int prevstate = 0;
int presentstate;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(R_PWM, OUTPUT);
  pinMode(L_PWM, OUTPUT);
  pinMode(input, INPUT);
}

void loop() {
  int b = analogRead(A0);
  int c = analogRead(A1);
  //Serial.println(b);
  //Serial.println(c);  
  int a = b-c;
  Serial.println(a);
  if(a > 500)
    presentstate = 1;
  else if(a < 100)
    presentstate = 0;

  //Serial.print("Present State: ");
  //Serial.println(presentstate);
//
//  Serial.print("Previous State: ");
//  Serial.println(prevstate);
  if(prevstate==1 && presentstate==0) {//TO CLOSE
          Serial.print("CLOSING\n");
          analogWrite(R_PWM, 0);
          analogWrite(L_PWM, 27);
          delay(7700);
          analogWrite(R_PWM, 0);
          analogWrite(L_PWM, 0);
    }

  else if(presentstate==1 && prevstate==0) {  //TO OPEN
          Serial.print("OPENING\n");
          analogWrite(R_PWM, 27);
          analogWrite(L_PWM, 0);
          delay(7700);
          analogWrite(R_PWM, 0);
          analogWrite(L_PWM, 0);
    }
  else{
      analogWrite(R_PWM, 0);
      analogWrite(L_PWM, 0);
      Serial.print("WAITING\n");
    }

    prevstate = presentstate;

//  Serial.print("a1 = ");
//  Serial.println(a1);
//  Serial.println("----");
//  Serial.print("a0 = ");
//  Serial.println(a0);
//  Serial.println("----");s
  delay(500);
 }
