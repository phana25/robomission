
// Motor pins
const int pwmPinL = 9;
const int dirPin1_L = 30;
const int dirPin2_L = 31;
const int pwmPinR = 8;
const int dirPin1_R = 28;
const int dirPin2_R = 29;
// Encoder pins
const int encoderPinA_L = 18;
const int encoderPinB_L = 14;
const int encoderPinA_R = 12;
const int encoderPinB_R = 2;
// Wheel and encoder constants
const float wheelDiameter = 6.24; // cm
const float L = 22.5; // distance between wheels in Cm
const float r = wheelDiameter / 2; //wheel radius in cm
// const float PI = 3.1416;


// const int encoderPPR = 17.6;
// const int gearRatio = 21;
const float ticksPerWheelRev = 375.0; 
const float wheelCircumference = 3.1416 * wheelDiameter;
const float distancePerTick = wheelCircumference / ticksPerWheelRev; //distance wheel traveled in cm per tick 
// int led = 8;

// Motion settings
// float targetDistanceCm_L = 150.0;
// float targetDistanceCm_R = 150.0;
long targetPos_L = 0;
long targetPos_R = 0;
volatile long encoderPos_L = 0;
volatile long encoderPos_R = 0;
long prevEncoder_L = 0;
long prevEncoder_R = 0;
unsigned long moveStart = 0;



// PID gains
float Kp = 0.47;
float Ki = 0.0;
float Kd = 0.0;
float Kp_R = 1.7;
float Ki_R = 0.0;
float Kd_R = 0.0;

//PID RPM
// float Kp2 = 0.5;
// float Ki = 0.0;
// float Kd = 0.0;
// float Kp_R2 = 0.5;
// float Ki_R = 0.0;
// float Kd_R = 0.0;
// PID internal state
float error_L, lastError_L, integral_L, derivative_L;
float error_R, lastError_R, integral_R, derivative_R;
unsigned long lastPIDTime = 0;
// bool motionComplete = false;


//IMU
//This structure contains the details of the BNO055 device that is connected. (Updated after initialization)


unsigned long lastTime = 0;

float angleX = 0, angleY = 0, angleZ = 0;
float pitch = 0.0;
float roll = 0.0;
unsigned long lastIMUTime = 0;

float x = 0, y = 0, theta = 0, desired_thelta = 0;
#define DEG_TO_RAD 0.01745

const int buttonPin = 4;
bool started = false;
bool buttonPreviouslyPressed = false;






