// Motor control pins
const int ENA = 5;
const int IN1 = 8;
const int IN2 = 9;
const int ENB = 6;
const int IN3 = 10;
const int IN4 = 11;

// IR sensors
const int LEFT = 2;
const int RIGHT = 3;

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(LEFT, INPUT);
  pinMode(RIGHT, INPUT);
}

void loop() {
  int left = digitalRead(LEFT);
  int right = digitalRead(RIGHT);

  if (left == LOW && right == LOW) {
    // Both sensors on line
    forward(180, 180);
  } else if (left == LOW && right == HIGH) {
    // Left sensor on line
    forward(100, 180);
  } else if (left == HIGH && right == LOW) {
    // Right sensor on line
    forward(180, 100);
  } else {
    // No line
    stopMotors();
  }
}

void forward(int leftSpeed, int rightSpeed) {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, leftSpeed);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, rightSpeed);
}

void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 0);
}