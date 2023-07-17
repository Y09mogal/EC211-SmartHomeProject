int butt1 = 6;
int butt2 = 7;
const int buzz = 9;
int led = 13;
int a;
int b;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(buzz, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 a = digitalRead(butt1);
 b = digitalRead(butt2);

 if(a==HIGH || b==HIGH)
 {
  int count = 0;
  while(a==HIGH || b==HIGH)
  {
    digitalWrite(13, LOW);
    a=digitalRead(butt1);
    b=digitalRead(butt2);
    delay(100);
    count++;
    Serial.println(count);
    if(count>=200)
    {
      tone(buzz,2000);//buzzer goes off    
    }
    else
    {
      continue;
    }
    if(a==LOW && b==LOW)
    {
      noTone(buzz);
    }
  }
 }
 else
 {
  digitalWrite(13, HIGH);
  noTone(buzz);
 }
 delay(100);
} 
