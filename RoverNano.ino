int APWM = 6;
int A1Out = 7;
int A2Out = 4;

int BPWM = 5;
int B1Out = 2;
int B2Out = 3;

enum DirectionEnum {
  NAPRED,
  NAZAD
};

enum MotorEnum {
  MOTOR1,
  MOTOR2
};

void setup() {
  Serial.begin(9600);
}

void loop() {
}

void SerialEvent() {
  Serial
}

void initMotors() {
  pinMode(APWM, OUTPUT);
  pinMode(A1Out, OUTPUT);
  pinMode(A2Out, OUTPUT);
  //  pinMode(BPWM, OUTPUT);
  //  pinMode(B1Out, OUTPUT);
  //  pinMode(B2Out, OUTPUT);
}

void driveMotor() {
  digitalWrite(A1Out, LOW);
  digitalWrite(A2Out, HIGH);
  for (int i = 125; i < 256; i++) - {
    analogWrite(APWM, i);
    delay(100);
  }
}

void MotorDirection(MotorEnum motor, DirectionEnum dir) {
  if (dir == NAPRED) {

  };
  if (dir == NAZAD) {

  };
}
void xxx() {
  //  analogWrite(APWM, 125);
  //  analogWrite(BPWM, 125);
  //  digitalWrite(A1Out, LOW);
  //  digitalWrite(A2Out, HIGH);
  //  digitalWrite(B1Out, LOW);
  //  digitalWrite(B2Out, HIGH);
  //  delay(2000);
  //  digitalWrite(A1Out, LOW);
  //  digitalWrite(A2Out, LOW);
  //  digitalWrite(B1Out, LOW);
  //  digitalWrite(B2Out, LOW);
  //  delay(1000);
  //  digitalWrite(A1Out, HIGH);
  //  digitalWrite(A2Out, LOW);
  //  digitalWrite(B1Out, HIGH);
  //  digitalWrite(B2Out, LOW);
  //  delay(2000);
  //  digitalWrite(A1Out, LOW);
  //  digitalWrite(A2Out, LOW);
  //  digitalWrite(B1Out, LOW);
  //  digitalWrite(B2Out, LOW);
  //  delay(1000);
}
