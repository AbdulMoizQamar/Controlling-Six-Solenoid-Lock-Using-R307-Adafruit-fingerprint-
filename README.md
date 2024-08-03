# Controlling-Six-Solenoid-Lock-Using-R307-Adafruit-fingerprint-


**Components of the System**:

**1. Fingerprint Sensor:**
Model: Adafruit Fingerprint Sensor
Function: Captures fingerprint images and processes them to identify matches against stored fingerprints.
Communication: Uses serial communication to send and receive data from the Arduino.

**2. LCD Display:**
Type: I2C LCD (20x4)
Function: Provides visual feedback to the user, displaying messages such as "Sensor Found" or "ID Match Found".
Communication: Uses I2C protocol, which requires only two wires (SDA and SCL) for communication, making it efficient for projects with limited pin availability.

**3. Solenoid Locks:**
Function: Mechanically locks or unlocks a door or access point based on the fingerprint recognition result.
Control: Each solenoid is controlled by a digital pin on the Arduino, allowing for precise control over which lock is activated.


**Summary:**
This code creates a fingerprint-based access control system using an Adafruit fingerprint sensor, an LCD display for user feedback, and multiple solenoid locks to control access. The system checks for matching fingerprints and unlocks the appropriate solenoid lock while providing visual feedback on the LCD. The modular design allows for easy expansion and modification, making it suitable for various applications.
