//version 3
void moveToTargetPose(float target_x, float target_y) {
  // Step 1: Compute difference to target
  float dx = target_x - x;
  float dy = target_y - y;

  // Step 2: Distance and desired heading
  float distance = sqrt(dx * dx + dy * dy);
  float desired_theta = atan2(dy, dx);

  // Step 3: Heading error
  float dTheta = desired_theta - theta;

  // Normalize to [-PI, PI]
  while (dTheta > PI) dTheta -= 2 * PI;
  while (dTheta < -PI) dTheta += 2 * PI;

  // Step 4: Motion control logic
  float heading_correction = constrain(0.3 * dTheta, -50, 50);       // turning effort
  float linear = constrain(500.0 * distance, -200, 200);             // forward effort

  // Step 5: Convert to wheel-based movement
  float left_target = linear - heading_correction * r;
  float right_target = linear + heading_correction * r;

  // Step 6: Convert to encoder ticks
  targetPos_L = encoderPos_L + (left_target / distancePerTick);
  targetPos_R = encoderPos_R + (right_target / distancePerTick);

  // Log info
  Serial.println(" Setting New Target Pose:");
  Serial.print("  → Target X: "); Serial.print(target_x, 2);
  Serial.print(" | Y: "); Serial.print(target_y, 2);
  Serial.print(" | Distance: "); Serial.print(distance * 100, 1); Serial.println(" cm");

  Serial.print("  Heading Now: "); Serial.print(theta * 180 / PI, 1);
  Serial.print(" | Desired: "); Serial.print(desired_theta * 180 / PI, 1);
  Serial.print(" | Error: "); Serial.println(dTheta * 180 / PI, 1);

  Serial.print("  Target Ticks L: "); Serial.print(targetPos_L);
  Serial.print(" | R: "); Serial.println(targetPos_R);
}

//Version 2
// void moveToTargetPose(float target_x, float target_y) {
//   float dx = target_x - x;
//   float dy = target_y - y;
//   float distance = sqrt(dx * dx + dy * dy);
//   float desired_theta = atan2(dy, dx);
//   float dTheta = desired_theta - theta;

//   // Normalize dTheta
//   while (dTheta > PI) dTheta -= 2 * PI;
//   while (dTheta < -PI) dTheta += 2 * PI;

//   float heading_correction = constrain(0.3 * dTheta, -50, 50);
//   float linear = constrain(500.0 * distance, -200, 200);

//   float left_target = linear - heading_correction * r;
//   float right_target = linear + heading_correction * r;

//   targetPos_L = encoderPos_L + (left_target / distancePerTick);
//   targetPos_R = encoderPos_R + (right_target / distancePerTick);

//   Serial.print(" Moving to: X=");
//   Serial.print(target_x);
//   Serial.print(" Y=");
//   Serial.println(target_y);
// }

//version 1
// void printPose() {
//   Serial.print("X: "); Serial.print(x, 2);
//   Serial.print(" | Y: "); Serial.print(y, 2);
//   Serial.print(" | θ: "); Serial.println(theta * 180 / PI, 1);
// }

// void moveToTargetPose(float target_x, float target_y) {
//   float dx = target_x - x;
//   float dy = target_y - y;
//   float distance = sqrt(dx * dx + dy * dy);
//   float desired_theta = atan2(dy, dx);
//   float dTheta = desired_theta - theta;

//   // Normalize dTheta to [-PI, PI]
//   while (dTheta > PI) dTheta -= 2 * PI;
//   while (dTheta < -PI) dTheta += 2 * PI;

//   float heading_correction = constrain(0.3 * dTheta, -50, 50);
//   float linear = constrain(500.0 * distance, -200, 200);

//   float left_target = linear - heading_correction * r;
//   float right_target = linear + heading_correction * r;

//   // Convert distances to ticks
//   targetPos_L = encoderPos_L + (left_target / distancePerTick);
//   targetPos_R = encoderPos_R + (right_target / distancePerTick);

//   Serial.println("▶ Moving to target pose...");
//   Serial.print("Target X: "); Serial.print(target_x);
//   Serial.print(" | Y: "); Serial.print(target_y);
//   Serial.print(" | Distance: "); Serial.print(distance, 2);
//   Serial.print(" | Heading error (deg): "); Serial.println(dTheta * 180 / PI, 1);
// }
// void printPose() {
//   Serial.print("X: "); Serial.print(x, 2);
//   Serial.print(" Y: "); Serial.print(y, 2);
//   Serial.print(" θ(deg): "); Serial.println(theta * 180 / PI);
// }
