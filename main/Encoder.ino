void setupEncoder() {
  pinMode(encoderPinA_L, INPUT_PULLUP);
  pinMode(encoderPinB_L, INPUT_PULLUP);
  pinMode(encoderPinA_R, INPUT_PULLUP);
  pinMode(encoderPinB_R, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(encoderPinA_L), encoderISL, CHANGE);
  attachInterrupt(digitalPinToInterrupt(encoderPinB_R), encoderISR, CHANGE);

}

void encoderISL() {
  bool A_L = digitalRead(encoderPinA_L);
  bool B_L = digitalRead(encoderPinB_L);
  if (A_L == B_L) {
    encoderPos_L++;
  } else {
    encoderPos_L--;
  }
}
void encoderISR(){
  bool A_R = digitalRead(encoderPinA_R);
  bool B_R = digitalRead(encoderPinB_R);
  if (A_R == B_R){
    encoderPos_R--;
  } else {
    encoderPos_R++;
  }
}


