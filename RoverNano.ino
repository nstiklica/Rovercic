int APWM = 6;
int A1Out = 7;
int A2Out = 4;

int BPWM = 5;
int B1Out = 2;
int B2Out = 3;

byte commandId;
byte const motorCommandId = 0x00;
byte const servoCommandId = 0x01;

struct Motor {
  byte leftMotorDir;
  byte leftMotorSpeed;
  byte rightMotorDir;
  byte rightMotorSpeed;
};

// current motor state
Motor cMS = { 0x00, 0x00, 0x00, 0x00 };
// new motor state
Motor nMS = { 0x00, 0x00, 0x00, 0x00 };

void setup() {
  initMotors();
  Serial.begin(9600);
}

void loop() {

}

void serialEvent() {
  delay(5);
  commandId = Serial.read();

  HandleCommand();
}

void HandleCommand() {
  switch (commandId) {
    case motorCommandId:
      HandleMotorsCommand();
      break;
    case servoCommandId:
      Serial.println("servo command");
      break;
    default:
      Serial.println("Unknown command");
  }
}

void HandleMotorsCommand() {
  nMS.leftMotorDir = Serial.read();
  nMS.leftMotorSpeed = Serial.read();
  nMS.rightMotorDir = Serial.read();
  nMS.rightMotorSpeed = Serial.read();

  setMotors();
}

void setMotors() {

  if (cMS.leftMotorDir != nMS.leftMotorDir) { //change dir of left track
    SetLeftMotorDirection();
    cMS.leftMotorDir = nMS.leftMotorDir;
  }
  if (cMS.rightMotorDir != nMS.rightMotorDir) {
    SetRightMotorDirection();
    cMS.rightMotorDir = nMS.rightMotorDir;
  }

  analogWrite(APWM, nMS.rightMotorSpeed);
  analogWrite(BPWM, nMS.leftMotorSpeed);

}

void SetLeftMotorDirection() {
  if (nMS.leftMotorDir == 1) //forward
  {
    Serial.println("LEFT FORWARD");
    digitalWrite(A1Out, 1);
    digitalWrite(A2Out, 0);
  }
  if (nMS.leftMotorDir == 0) { //backward
    Serial.println("LEFT LEFT BACKWARD");
    digitalWrite(A1Out, 0);
    digitalWrite(A2Out, 1);
  }
}

void SetRightMotorDirection() {
  if (nMS.rightMotorDir == 1) //forward
  {
    Serial.println("RIGHT FORWARD");
    digitalWrite(B1Out, 1);
    digitalWrite(B2Out, 0);
  }
  if (nMS.rightMotorDir == 0) { //backward
    Serial.println("RIGHT BACKWARD");
    digitalWrite(B1Out, 0);
    digitalWrite(B2Out, 1);
  }
}


void initMotors() {
  pinMode(APWM, OUTPUT);
  pinMode(A1Out, OUTPUT);
  pinMode(A2Out, OUTPUT);
  pinMode(BPWM, OUTPUT);
  pinMode(B1Out, OUTPUT);
  pinMode(B2Out, OUTPUT);

  digitalWrite(A1Out, 1);
  digitalWrite(A2Out, 0);

  digitalWrite(B1Out, 1);
  digitalWrite(B2Out, 0);
}

void driveMotor() {

  //  digitalWrite(A1Out, !digitalRead(A1Out));
  //  digitalWrite(A2Out, !digitalRead(A2Out));
  //
  //  digitalWrite(B1Out, !digitalRead(B1Out));
  //  digitalWrite(B2Out, !digitalRead(B2Out));

  for (int i = 100; i < 200; i++) {
    analogWrite(APWM, i);
    analogWrite(BPWM, i);
    delay(100);
  }
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
