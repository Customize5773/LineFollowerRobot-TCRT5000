// === Pin Definitions ===
#define IR_SENSOR_RIGHT A0
#define IR_SENSOR_LEFT  A1

#define MOTOR_SPEED 180

// Right motor
const int enableRightMotor = 6;
const int rightMotorPin1   = 7;
const int rightMotorPin2   = 8;

// Left motor
const int enableLeftMotor = 5;
const int leftMotorPin1   = 9;
const int leftMotorPin2   = 10;

// === Threshold Variables ===
int leftThreshold  = 500;
int rightThreshold = 500;

void setup() {
  Serial.begin(9600);

  // Improve low-speed PWM control by adjusting Timer0 frequency
  TCCR0B = TCCR0B & B11111000 | B00000010;  // ~7.8 kHz on D5 and D6

  // Motor pin modes
  pinMode(enableRightMotor, OUTPUT);
  pinMode(rightMotorPin1, OUTPUT);
  pinMode(rightMotorPin2, OUTPUT);
  
  pinMode(enableLeftMotor, OUTPUT);
  pinMode(leftMotorPin1, OUTPUT);
  pinMode(leftMotorPin2, OUTPUT);

  // IR sensor pins (analog pins are input by default)

  rotateMotor(0, 0); // Stop motors at start
  calibrateIRSensors(); // Optional dynamic calibration
}

// === Main Loop ===
void loop() {
  int rightIR = analogRead(IR_SENSOR_RIGHT);
  int leftIR  = analogRead(IR_SENSOR_LEFT);

  bool rightOnLine = rightIR > rightThreshold;
  bool leftOnLine  = leftIR > leftThreshold;

  // Debug output (optional)
  Serial.print("Left: "); Serial.print(leftIR);
  Serial.print(" | Right: "); Serial.println(rightIR);

  if (!leftOnLine && !rightOnLine) {
    moveForward();
  } else if (rightOnLine && !leftOnLine) {
    turnRight();
  } else if (!rightOnLine && leftOnLine) {
    turnLeft();
  } else {
    stopMotors();
  }
}

// === Modular Movement Functions ===
void moveForward() {
  rotateMotor(MOTOR_SPEED, MOTOR_SPEED);
}

void turnRight() {
  rotateMotor(-MOTOR_SPEED, MOTOR_SPEED);
}

void turnLeft() {
  rotateMotor(MOTOR_SPEED, -MOTOR_SPEED);
}

void stopMotors() {
  rotateMotor(0, 0);
}

// === Motor Control Function ===
void rotateMotor(int rightMotorSpeed, int leftMotorSpeed) {
  // Right motor direction
  digitalWrite(rightMotorPin1, rightMotorSpeed > 0 ? HIGH : LOW);
  digitalWrite(rightMotorPin2, rightMotorSpeed < 0 ? HIGH : LOW);

  // Left motor direction
  digitalWrite(leftMotorPin1, leftMotorSpeed > 0 ? HIGH : LOW);
  digitalWrite(leftMotorPin2, leftMotorSpeed < 0 ? HIGH : LOW);

  analogWrite(enableRightMotor, abs(rightMotorSpeed));
  analogWrite(enableLeftMotor, abs(leftMotorSpeed));
}

// === Dynamic Calibration Function ===
void calibrateIRSensors() {
  Serial.println("Place sensors on WHITE surface...");
  delay(2000);
  int whiteLeft  = analogRead(IR_SENSOR_LEFT);
  int whiteRight = analogRead(IR_SENSOR_RIGHT);

  Serial.println("Place sensors on BLACK line...");
  delay(2000);
  int blackLeft  = analogRead(IR_SENSOR_LEFT);
  int blackRight = analogRead(IR_SENSOR_RIGHT);

  leftThreshold  = (whiteLeft + blackLeft) / 2;
  rightThreshold = (whiteRight + blackRight) / 2;

  Serial.print("Calibrated Left Threshold: "); Serial.println(leftThreshold);
  Serial.print("Calibrated Right Threshold: "); Serial.println(rightThreshold);
}
