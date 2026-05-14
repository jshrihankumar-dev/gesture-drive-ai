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

void writeServoForMs(Servo &servo, int pulse, int durationMs) {
  servo.writeMicroseconds(pulse);
  delay(durationMs);
  servo.writeMicroseconds(STOP_US);
}

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

void testOneServo(const char *label, Servo &servo) {
  Serial.print("Testing ");
  Serial.println(label);
  writeServoForMs(servo, FORWARD_US, 800);
  delay(300);
}

void testServos() {
  stopDrive();
  testOneServo("front left", frontLeft);
  testOneServo("front right", frontRight);
  testOneServo("back left", backLeft);
  testOneServo("back right", backRight);
  stopDrive();
  Serial.println("Test complete");
}

void handleCommand(String command) {
  command.trim();
  command.toUpperCase();

  if (command == "FORWARD") {
    driveForward();
  } else if (command == "LEFT") {
    turnLeft();
  } else if (command == "RIGHT") {
    turnRight();
  } else if (command == "FL") {
    writeServoForMs(frontLeft, FORWARD_US, 1000);
  } else if (command == "FR") {
    writeServoForMs(frontRight, FORWARD_US, 1000);
  } else if (command == "BL") {
    writeServoForMs(backLeft, FORWARD_US, 1000);
  } else if (command == "BR") {
    writeServoForMs(backRight, FORWARD_US, 1000);
  } else if (command == "TEST") {
    testServos();
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
