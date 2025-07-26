void updateOdometry(){

  //Odometry Position estimation 
  unsigned long currentTime = millis();
  float dt = (currentTime - lastTime)/1000.0 ; 
  if (dt < 0.05) return;
  lastTime = currentTime;

  noInterrupts();
  long encoderTick_L = encoderPos_L; 
  long encoderTick_R = encoderPos_R; 
  encoderPos_L = 0;
  encoderPos_R = 0;
  interrupts();

  float dL = encoderTick_L * distancePerTick; // distance left wheel traveled.
  float dR = encoderTick_R * distancePerTick; // distance right wheel traveled.
  float dCenter = (dL + dR) / 2.0;
  bno055_read_euler_hrp(&myEulerData);
  float heading_deg = (myEulerData.h) / 16.0;
  float yaw_rad = heading_deg * DEG_TO_RAD;

  
  // float dThelta = (dR - dL) / L;
  
  theta = yaw_rad; //IMU heading
  x += dCenter * cos(theta);
  y += dCenter *sin(theta);

  Serial.print("X: "); Serial.print(x, 3);
  Serial.print(" | Y: "); Serial.print(y, 3);
  Serial.print(" | θ (deg): "); Serial.println(theta * 180.0 / PI, 2);

}