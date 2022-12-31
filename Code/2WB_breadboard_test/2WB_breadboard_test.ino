
// Basic demo for accelerometer readings from Adafruit MPU6050

#include <Wire.h>
#include <MPU6050_light.h>
#include "PID_vWAM.h"

#include <AccelStepper.h>

//Define the pin connections for the wheels
const int DIR_PIN = 6 ;
const int STEP_PIN = 5 ;


//  Motor setup
AccelStepper stepper(AccelStepper::DRIVER, STEP_PIN, DIR_PIN) ;
const float MAX_SPEED = 2000 ;      // steps per sec. 4k is max for arduino

// PID setup
#define SETPOINT_ANGLE -0.16
#define PID_CALCULATION_INTERVAL_MS 1
#define PID_KP  50.0
#define PID_KD .8
#define PID_KI 25.0
#define PID_KA 0.05

double setPoint = SETPOINT_ANGLE ;
double currentAngle ;
double motorSpeed = 0 ;

PID pid(&currentAngle, &motorSpeed, &setPoint, PID_KP, PID_KI, PID_KD, PID_KA, DIRECT) ;

MPU6050 mpu(Wire);
unsigned long timer = 0;
 
void setup() {
   Serial.begin(9600);
   
   Wire.begin();
   byte status = mpu.begin();
   Serial.print(F("MPU6050 status: "));
   Serial.println(status);
   while (status != 0) { } // stop everything if could not connect to MPU6050
   
   Serial.println(F("Calculating offsets, do not move MPU6050"));
   delay(1000);
   mpu.calcOffsets(); // gyro and accelero

   // initialize PID
   pid.SetMode(AUTOMATIC);
   pid.SetSampleTime(PID_CALCULATION_INTERVAL_MS);
   pid.SetOutputLimits(-1*MAX_SPEED , MAX_SPEED);

   // Initialize Steppers
   stepper.setMaxSpeed(MAX_SPEED) ;

   
   Serial.println("Done!\n");
}


 void loop() {

   // Get the current angle of the bot
   mpu.update();
   currentAngle = mpu.getAngleY();

   // Compute the adjustment speed needed to right the bot
   pid.Compute();

   // Move the wheels
   stepper.setSpeed(motorSpeed) ;
   stepper.runSpeed() ;

   if ((millis() - timer) > 500) { // print data every 500ms
     Serial.print("X : "); Serial.print(mpu.getAngleX());
     Serial.print("\tY : "); Serial.print(mpu.getAngleY());
     Serial.print("\tZ : "); Serial.print(mpu.getAngleZ());
     Serial.print("\tMotorSpeed: "); Serial.println(motorSpeed) ;
     timer = millis();
   }
 }