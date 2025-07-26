void bno055(){
  if ((millis() - lastIMUTime) >= 100) //To stream at 10 Hz without using additional timers
  {
    lastIMUTime = millis();

    bno055_read_euler_hrp(&myEulerData);			//Update Euler data into the structure

    Serial.print("Time Stamp: ");				//To read out the Time Stamp
    Serial.println(lastIMUTime);

    Serial.print("Heading(Yaw): ");				//To read out the Heading (Yaw)
    Serial.println(float(myEulerData.h) / 16.00);		//Convert to degrees

    // Serial.print("Roll: ");					//To read out the Roll
    // Serial.println(float(myEulerData.r) / 16.00);		//Convert to degrees

    // Serial.print("Pitch: ");				//To read out the Pitch
    // Serial.println(float(myEulerData.p) / 16.00);		//Convert to degrees

    Serial.println();					//Extra line to differentiate between packets
  }
}