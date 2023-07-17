int count = 0;

int sensor1[] = {10, 9}; //echo, trig
int sensor2[] = {2, 3};
int sensor1_init;
int sensor2_init;
int output = 13;

String sequence = "";

int timeoutCounter = 0;

void setup() {
  Serial.begin(9600);
  pinMode(output, OUTPUT);
  delay(500);
  sensor1_init = measureDistance(sensor1);
  sensor2_init = measureDistance(sensor2);
}

void loop() {
  delay(100);
  int sensor1_val = measureDistance(sensor1);
  int sensor2_val = measureDistance(sensor2);
  
  if(sensor1_val < sensor1_init - 30 && sequence.charAt(0) != '1') {
    sequence += "1";
  }
  else if(sensor2_val < sensor2_init - 30 && sequence.charAt(0) != '2') {
    sequence += "2";
  }
  
  if(sequence.equals("12")) {
    count++;  
    sequence = "";
    delay(550);
  }
  else if(sequence.equals("21") && count > 0) {
    count--;  
    sequence = "";
    delay(550);
  }

  //conditions to reset the sequence
  if(sequence.length() > 2 || sequence.equals("11") || sequence.equals("22") || timeoutCounter > 200) {
    sequence = "";  
  }

  if(sequence.length() == 1)
    timeoutCounter++;
  else
    timeoutCounter = 0;

  Serial.print(" Count: ");
  Serial.println(count);

  if(count > 0)
    digitalWrite(output, HIGH);
  else
    digitalWrite(output, LOW);
}

//a[0] = echo, a[1] = trig
int measureDistance(int a[]) {
  pinMode(a[1], OUTPUT);
  digitalWrite(a[1], LOW);
  delayMicroseconds(2);
  digitalWrite(a[1], HIGH);
  delayMicroseconds(10);
  digitalWrite(a[1], LOW);
  pinMode(a[0], INPUT);
  long duration = pulseIn(a[0], HIGH, 100000);
  return duration / 29 / 2;
}
