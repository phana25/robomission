void setupMotor() {
  pinMode(pwmPinL, OUTPUT);
  pinMode(dirPin1_L, OUTPUT);
  pinMode(dirPin2_L, OUTPUT);
  pinMode(pwmPinR, OUTPUT);
  pinMode(dirPin1_R, OUTPUT);
  pinMode(dirPin2_R, OUTPUT);
}

void setMotorSpeedLeft(float speed) {
  speed = constrain(speed, -200, 200);
  if (speed > 0) {
    digitalWrite(dirPin1_L, HIGH);
    digitalWrite(dirPin2_L, LOW);
    analogWrite(pwmPinL, (int)speed);
  } else if (speed < 0) {
    digitalWrite(dirPin1_L, LOW);
    digitalWrite(dirPin2_L, HIGH);
    analogWrite(pwmPinL, (int)(-speed));
  } else {
    analogWrite(pwmPinL, 0);
  }
}

void setMotorSpeedRight(float speed) {
  speed = constrain(speed, -200, 200);
  if (speed > 0) {
    digitalWrite(dirPin1_R, HIGH);
    digitalWrite(dirPin2_R, LOW);
    analogWrite(pwmPinR, (int)speed);
  } else if (speed < 0) {
    digitalWrite(dirPin1_R, LOW);
    digitalWrite(dirPin2_R, HIGH);
    analogWrite(pwmPinR, (int)(-speed));
  } else {
    analogWrite(pwmPinR, 0);
  }
}