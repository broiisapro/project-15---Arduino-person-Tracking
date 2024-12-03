#include <Servo.h>

Servo panServo;  // Servo to control horizontal movement
Servo tiltServo; // Servo to control vertical movement

// Define variables to hold target positions
int targetPanAngle = 90;
int targetTiltAngle = 90;

// Define smoothing parameters  
int smoothingSpeed = 1; // Higher value for slower movement

void setup() {
  Serial.begin(9600);
  panServo.attach(9);  // Attach pan servo to pin 9
  tiltServo.attach(10); // Attach tilt servo to pin 10
}

void loop() {
  if (Serial.available() > 0) {
    String data = Serial.readStringUntil('\n');
    int commaIndex = data.indexOf(',');
    if (commaIndex != -1) {
      int centerX = data.substring(0, commaIndex).toInt();
      int centerY = data.substring(commaIndex + 1).toInt();

      // Map the coordinates to servo angles
      targetPanAngle = map(centerX, 0, 640, 0, 180);
      targetTiltAngle = map(centerY, 0, 480, 0, 180);
    }
  }

  // Smoothly move the pan servo to the target angle
  int currentPanAngle = panServo.read();
  if (currentPanAngle < targetPanAngle) {
    panServo.write(currentPanAngle + smoothingSpeed);
  } else if (currentPanAngle > targetPanAngle) {
    panServo.write(currentPanAngle - smoothingSpeed);
  }

  // Smoothly move the tilt servo to the target angle
  int currentTiltAngle = tiltServo.read();
  if (currentTiltAngle < targetTiltAngle) {
    tiltServo.write(currentTiltAngle + smoothingSpeed);
  } else if (currentTiltAngle > targetTiltAngle) {
    tiltServo.write(currentTiltAngle - smoothingSpeed);
  }

  delay(15);  // Adjust the delay to control update frequency
}
