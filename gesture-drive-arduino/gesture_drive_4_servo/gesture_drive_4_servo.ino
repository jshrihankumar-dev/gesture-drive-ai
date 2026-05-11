#include <Servo.h>

const int FRONT_LEFT_PIN = 3;
const int FRONT_RIGHT_PIN = 5;
const int BACK_LEFT_PIN = 6;
const int BACK_RIGHT_PIN = 9;

const int STOP_US = 1500;
const int FORWARD_US = 1700;
const int REVERSE_US = 1300;

Servo frontLeft;
Servo frontRight;
Servo backLeft;
Servo backRight;

void writeDrive(int leftPulse, int rightPulse) {
  frontLeft.writeMicroseconds(leftPulse);
  backLeft.writeMicroseconds(leftPulse);
  frontRight.writeMicroseconds(rightPulse);
  backRight.writeMicroseconds(rightPulse);
}

void stopDrive() {
  writeDrive(STOP_US, STOP_US);
}

void driveForward() {
  writeDrive(FORWARD_US, FORWARD_US);
}

void turnLeft() {
  writeDrive(REVERSE_US, FORWARD_US);
}

void turnRight() {
  writeDrive(FORWARD_US, REVERSE_US);
}

void handleCommand(String command) {
  command.trim();

  if (command == "FORWARD") {
    driveForward();
  } else if (command == "LEFT") {
    turnLeft();
  } else if (command == "RIGHT") {
    turnRight();
  } else {
    stopDrive();
  }
}

void setup() {
  Serial.begin(9600);

  frontLeft.attach(FRONT_LEFT_PIN);
  frontRight.attach(FRONT_RIGHT_PIN);
  backLeft.attach(BACK_LEFT_PIN);
  backRight.attach(BACK_RIGHT_PIN);

  stopDrive();
}

void loop() {
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    handleCommand(command);
  }
}
