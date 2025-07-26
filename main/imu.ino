// #define DEBUG_IMU 1

// void setupIMU() {
//   // Serial.begin(115200);
//   // delay(2000);  // Wait for Serial Monitor to open

//   Serial.print("Init sensor...");
//   while (icg.begin(icg.eRegMode) != 0) {
//     Serial.println("FAILED");
//     // delay(1000);
//   }
//   Serial.println("DONE");

//   icg.enableSensor(icg.eGyroAxisXYZ);  // Enable gyro only
//   icg.configGyro(icg.eFSR_G_250DPS, icg.eGyro_DLPF_176_1KHZ);  // Optional tuning
//   // icg.configAccel(icg.eFSR_A_4G, icg.eAccel_DLPF_99_1KHZ);

//   lastTime = micros();
// }

// // 
// void IMU() {
//   sIcg20660SensorData_t accel, gyro;
//   icg.getSensorData(&accel, &gyro, nullptr);  // Read accel and gyro

//   unsigned long currentTime = micros();
//   float dt = (currentTime - lastTime) / 1000000.0;
//   lastTime = currentTime;

//   // Step 1: Compute raw pitch and roll from accelerometer
//   float accelPitch = atan2(accel.y, sqrt(accel.x * accel.x + accel.z * accel.z)) * 180.0 / PI;
//   float accelRoll  = atan2(-accel.x, accel.z) * 180.0 / PI;

//   // Step 2: Integrate gyro
//   float gyroPitch = pitch + gyro.x * dt;  // Note: x is pitch (around lateral axis)
//   float gyroRoll  = roll + gyro.y * dt;   // Note: y is roll (around longitudinal axis)

//   // Step 3: Complementary filter
//   const float alpha = 0.96;
//   pitch = alpha * gyroPitch + (1 - alpha) * accelPitch;
//   roll  = alpha * gyroRoll  + (1 - alpha) * accelRoll;

//   // Print results
//   Serial.print("Pitch: "); Serial.print(pitch); Serial.print("°\t");
//   Serial.print("Roll: "); Serial.println(roll); Serial.print("°");
// }
