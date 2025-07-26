void runPIDControl() {
  unsigned long now = millis();
  if (now - lastPIDTime >= 10) {
    lastPIDTime = now;

    // PID errors
    error_L = targetPos_L - encoderPos_L;
    error_R = targetPos_R - encoderPos_R;

    integral_L += error_L;
    integral_R += error_R;

    derivative_L = error_L - lastError_L;
    derivative_R = error_R - lastError_R;

    lastError_L = error_L;
    lastError_R = error_R;

    float output_L = constrain(Kp * error_L + Ki * integral_L + Kd * derivative_L, -255, 255);
    float output_R = constrain(Kp_R * error_R + Ki_R * integral_R + Kd_R * derivative_R, -255, 255);

    setMotorSpeedLeft(abs(error_L) > 5 ? output_L : 0);
    setMotorSpeedRight(abs(error_R) > 5 ? output_R : 0);

    // Check pose-based stop condition (2cm threshold)
    float dx = waypoints[currentWaypoint - 1][0] - x;
    float dy = waypoints[currentWaypoint - 1][1] - y;
    float dist_to_target = sqrt(dx * dx + dy * dy);

    if (dist_to_target < 0.02) { // 2 cm
      setMotorSpeedLeft(0);
      setMotorSpeedRight(0);
      motionComplete = true;

      Serial.println(" Reached target by pose!");
    }

    // Debug Print
    Serial.print("Err_L: "); Serial.print(error_L);
    Serial.print(" | Err_R: "); Serial.print(error_R);
    Serial.print(" | dX: "); Serial.print(dx, 3);
    Serial.print(" | dY: "); Serial.print(dy, 3);
    Serial.print(" | Dist_to_Target: "); Serial.println(dist_to_target * 100, 1); // in cm
  }
}
