
// IR Sensor Pins
int leftSensor = 2;
int rightSensor = 3;

// Motor Driver Pins
int ENA = 5;
int IN1 = 8;
int IN2 = 9;

int ENB = 6;
int IN3 = 10;
int IN4 = 11;

void setup() {

  pinMode(leftSensor, INPUT);
  pinMode(rightSensor, INPUT);

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  analogWrite(ENA, 150);
  analogWrite(ENB, 150);
}

void loop() {

  int left = digitalRead(leftSensor);
  int right = digitalRead(rightSensor);

  // Both sensors on white line
  if(left == 0 && right == 0) {
    forward();
  }

  // Left sensor detects black line
  else if(left == 1 && right == 0) {
    turnLeft();
  }

  // Right sensor detects black line
  else if(left == 0 && right == 1) {
    turnRight();
  }

  // Both sensors detect black
  else {
    stopRobot();
  }
}

void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stopRobot() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
