#include "Config.h"
// #include "Pixy2.h"
// #include "DFRobot_ICG20660L.h"
#include "BNO055_support.h"
#include <wire.h>
struct bno055_t myBNO;
struct bno055_euler myEulerData; //Structure to hold the Euler data


// Waypoints
// float waypoints[][2] = {
//   {0.3, 0.0},
//   {0.3, 0.3},
//   {0.0, 0.3}
// };
// int currentWaypoint = 0;
// int numWaypoints = sizeof(waypoints) / sizeof(waypoints[0]);
float waypoints[][2] = {
  {0.3, 0.0},  // Move forward 30cm
  {0.3, 0.3},  // Turn right and move 30cm
  {0.0, 0.3}   // Turn left and move back
};

int currentWaypoint = 0;
int numWaypoints = sizeof(waypoints) / sizeof(waypoints[0]);
bool motionComplete = false;


// DFRobot_ICG20660L_IIC icg(IIC_ADDR_SDO_H, &Wire);  // I2C, address 0x69
void setup() {
  // setupMotor();
  pinMode(buttonPin, INPUT);
  setupEncoder();
  setupMotor();
  // setupIMU();
  // setupcam();
  Wire.begin();  //In
  BNO_Init(&myBNO); //Assigning the structure to hold information about the device
  bno055_set_operation_mode(OPERATION_MODE_NDOF);  //Configuration to NDoF modeitialize I2C communication
  //Initialization of the BNO055
  Serial.begin(115200);
  
  // targetPos_L = targetDistanceCm_L / distancePerTick;
  // targetPos_R = targetDistanceCm_R / distancePerTick;

  lastPIDTime = millis();
  lastIMUTime = millis();
  



}

void loop() {
  bool buttonPressed = digitalRead(buttonPin) == HIGH;

  if (!started && buttonPressed && !buttonPreviouslyPressed) {
    started = true;
    Serial.println("Button pressed! Starting action...");
  }

  buttonPreviouslyPressed = buttonPressed;
  
  if (started) {
    bno055();            // Read IMU heading → update theta
    updateOdometry();    // Update (x, y)
    runPIDControl();     // Use PID to drive toward current target

    // Check if motion is complete
    if (motionComplete && currentWaypoint < numWaypoints) {
      float tx = waypoints[currentWaypoint][0];
      float ty = waypoints[currentWaypoint][1];

      moveToTargetPose(tx, ty);
      motionComplete = false;
      currentWaypoint++;

      moveStart = millis(); // reset timeout for this move
    }

    // Safety: stop if motion takes too long
    if (!motionComplete && (millis() - moveStart > 10000)) {
      setMotorSpeedLeft(0);
      setMotorSpeedRight(0);
      Serial.println(" Timeout — stopping robot");
      motionComplete = true;
    }
  } else {

  }

  // printPose();
  // delay(100); // 10 Hz update rate
}
// void loop() {
//   bno055();             // Update IMU heading
//   updateOdometry();     // Update (x, y, θ)
//   runPIDControl();      // PID drive to targetPos

//   if (motionComplete && currentWaypoint < numWaypoints) {
//     float tx = waypoints[currentWaypoint][0];
//     float ty = waypoints[currentWaypoint][1];
//     moveToTargetPose(tx, ty);
//     motionComplete = false;
//     currentWaypoint++;
//   }

//   printPose();
//   delay(100);




  
//   // runPIDControl();
//   // bno055();
//   // updateOdometry();
//   // setMotorSpeedLeft(150);
//   // setMotorSpeedRight(150);
//   // delay(2000);

//   // setMotorSpeedLeft(0);
//   // setMotorSpeedRight(0);
//   // delay(2000);
//   // //   if (motionComplete) {
//   // //   currentWaypoint++;
//   // //   if (currentWaypoint < numWaypoints) {
//   // //     float tx = waypoints[currentWaypoint][0];
//   // //     float ty = waypoints[currentWaypoint][1];
//   // //     moveToTargetPose(tx, ty);
//   // //     motionComplete = false;
//   // //   }
//   // // }
//   // campixy();
//   // IMU();
//   // test_led();
// }
