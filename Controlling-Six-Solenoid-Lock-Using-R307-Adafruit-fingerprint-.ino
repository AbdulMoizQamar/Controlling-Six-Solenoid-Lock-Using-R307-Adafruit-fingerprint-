#include <Adafruit_Fingerprint.h>
#include <HardwareSerial.h>


#define FINGERPRINT_SENSOR_RX 16 // Pin connected to fingerprint sensor TX (Green wire)
#define FINGERPRINT_SENSOR_TX 17 // Pin connected to fingerprint sensor RX (White wire)
#define SOLENOID_PIN_1 12 // Change to GPIO pin 12
#define SOLENOID_PIN_2 13 // Change to GPIO pin 13
#define SOLENOID_PIN_3 14 // Change to GPIO pin 13
#define SOLENOID_PIN_4 15 // Change to GPIO pin 13
#define SOLENOID_PIN_5 18 // Change to GPIO pin 13
#define SOLENOID_PIN_6 19 // Change to GPIO pin 13

HardwareSerial mySerial(1);

Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

bool isFingerprintIDMatch(uint8_t desiredID) {
  uint8_t p = finger.getImage();
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image taken");
      break;
    case FINGERPRINT_NOFINGER:
      return false;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return false;
    case FINGERPRINT_IMAGEFAIL:
      Serial.println("Imaging error");
      return false;
    default:
      Serial.println("Unknown error");
      return false;
  }

  p = finger.image2Tz();
  if (p != FINGERPRINT_OK) return false;

  p = finger.fingerFastSearch();
  if (p == FINGERPRINT_OK && finger.fingerID == desiredID) {
    Serial.println("Found a print match with desired ID!");
    return true;
  } else {
    Serial.println("Fingerprint ID does not match desired ID or not found");
    return false;
  }
}

void setup() {
  Serial.begin(9600);
  while (!Serial);
  delay(100);
  Serial.println("\n\nAdafruit finger detect test");

  mySerial.begin(57600, SERIAL_8N1, FINGERPRINT_SENSOR_RX, FINGERPRINT_SENSOR_TX);

  finger.begin(57600);
  delay(5);
  if (finger.verifyPassword()) {
    Serial.println("Found fingerprint sensor!");
  } else {
    Serial.println("Did not find fingerprint sensor :(");
    while (1) { delay(1); }
  }

  finger.getTemplateCount();
  if (finger.templateCount == 0) {
    Serial.println("Sensor doesn't contain any fingerprint data. Please run the 'enroll' example.");
  } else {
    Serial.println("Waiting for valid finger...");
    Serial.print("Sensor contains "); Serial.print(finger.templateCount); Serial.println(" templates");
  }

  pinMode(SOLENOID_PIN_1, OUTPUT);
  pinMode(SOLENOID_PIN_2, OUTPUT);
  pinMode(SOLENOID_PIN_3, OUTPUT);
  pinMode(SOLENOID_PIN_4, OUTPUT);
  pinMode(SOLENOID_PIN_5, OUTPUT);
  pinMode(SOLENOID_PIN_6, OUTPUT);

  digitalWrite(SOLENOID_PIN_1, LOW);
  digitalWrite(SOLENOID_PIN_2, LOW);
  digitalWrite(SOLENOID_PIN_3, LOW);
  digitalWrite(SOLENOID_PIN_4, LOW);
  digitalWrite(SOLENOID_PIN_5, LOW);
  digitalWrite(SOLENOID_PIN_6, LOW);

}

void loop() {
  if (isFingerprintIDMatch(1)) {
    digitalWrite(SOLENOID_PIN_1, LOW); // Set pin to low state
    delay(100); // Delay to ensure pin state change
    unlockSolenoidLock(1);
    delay(5000); // Unlock duration
    lockSolenoidLock(1);
  }
  else if (isFingerprintIDMatch(2)) {
    digitalWrite(SOLENOID_PIN_2, LOW); // Set pin to low state
    delay(100); // Delay to ensure pin state change
    unlockSolenoidLock(2);
    delay(5000); // Unlock duration
    lockSolenoidLock(2);
  }
  else if (isFingerprintIDMatch(3)) {
    digitalWrite(SOLENOID_PIN_3, LOW); // Set pin to low state
    delay(100); // Delay to ensure pin state change
    unlockSolenoidLock(3);
    delay(5000); // Unlock duration
    lockSolenoidLock(3);
  }
  else if (isFingerprintIDMatch(4)) {
    digitalWrite(SOLENOID_PIN_4, LOW); // Set pin to low state
    delay(100); // Delay to ensure pin state change
    unlockSolenoidLock(4);
    delay(5000); // Unlock duration
    lockSolenoidLock(4);
  }
  else if (isFingerprintIDMatch(5)) {
    digitalWrite(SOLENOID_PIN_5, LOW); // Set pin to low state
    delay(100); // Delay to ensure pin state change
    unlockSolenoidLock(5);
    delay(5000); // Unlock duration
    lockSolenoidLock(5);
  }
  else if (isFingerprintIDMatch(6)) {
    digitalWrite(SOLENOID_PIN_6, LOW); // Set pin to low state
    delay(100); // Delay to ensure pin state change
    unlockSolenoidLock(6);
    delay(5000); // Unlock duration
    lockSolenoidLock(6);
  }
  delay(50);
}

void unlockSolenoidLock(int lockNumber) {
  if (lockNumber == 1) {
    digitalWrite(SOLENOID_PIN_1, HIGH); // Activate the relay to unlock
    Serial.println("Solenoid lock 1 unlocked");
  } else if (lockNumber == 2) {
    digitalWrite(SOLENOID_PIN_2, HIGH); // Activate the relay to unlock
    Serial.println("Solenoid lock 2 unlocked");
  }
  else if (lockNumber == 3) {
    digitalWrite(SOLENOID_PIN_3, HIGH); // Activate the relay to unlock
    Serial.println("Solenoid lock 3 unlocked");
  }
  else if (lockNumber == 4) {
    digitalWrite(SOLENOID_PIN_4, HIGH); // Activate the relay to unlock
    Serial.println("Solenoid lock 4 unlocked");
  }
  else if (lockNumber == 5) {
    digitalWrite(SOLENOID_PIN_5, HIGH); // Activate the relay to unlock
    Serial.println("Solenoid lock 5 unlocked");
  }
  else if (lockNumber == 6) {
    digitalWrite(SOLENOID_PIN_6, HIGH); // Activate the relay to unlock
    Serial.println("Solenoid lock 6 unlocked");
  }
}

void lockSolenoidLock(int lockNumber) {
  if (lockNumber == 1) {
    digitalWrite(SOLENOID_PIN_1, LOW); // Deactivate the relay to lock
    Serial.println("Solenoid lock 1 locked");
  } else if (lockNumber == 2) {
    digitalWrite(SOLENOID_PIN_2, LOW); // Deactivate the relay to lock
    Serial.println("Solenoid lock 2 locked");
  }
  else if (lockNumber == 3) {
    digitalWrite(SOLENOID_PIN_3, LOW); // Deactivate the relay to lock
    Serial.println("Solenoid lock 3 locked");
  }else if (lockNumber == 4) {
    digitalWrite(SOLENOID_PIN_4, LOW); // Deactivate the relay to lock
    Serial.println("Solenoid lock 4 locked");
  }else if (lockNumber == 5) {
    digitalWrite(SOLENOID_PIN_5, LOW); // Deactivate the relay to lock
    Serial.println("Solenoid lock 5 locked");
  }else if (lockNumber == 6) {
    digitalWrite(SOLENOID_PIN_6, LOW); // Deactivate the relay to lock
    Serial.println("Solenoid lock 6 locked");
  }
}