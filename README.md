This project consists of two main components: an Arduino script and a Python script. The system uses a webcam to track a specific color in the camera's field of view, and based on the tracked object's position, it controls two servos connected to an Arduino board to pan and tilt. This allows the system to follow the object in real-time by adjusting the servo motors based on the position of the object detected in the webcam feed.

Components:
Arduino Uno or similar microcontroller.
Two servo motors (for panning and tilting).
Webcam for capturing the video feed.
Python libraries:
OpenCV (for image processing and object tracking).
PySerial (for serial communication between Python and Arduino).
Hardware Setup
Servo Motors:

Connect the pan servo to pin 9 on the Arduino.
Connect the tilt servo to pin 10 on the Arduino.
Arduino Board:

Ensure that the Arduino is connected to your computer via USB.
Make sure you have the Servo library installed in the Arduino IDE.
Webcam:

Connect your webcam to your computer (via USB or another interface).
Software Setup
Arduino Code
The Arduino code controls the pan and tilt servo motors based on the coordinates received from the Python script. The system smooths the servo movements for more natural tracking. The communication between the Python script and Arduino is done via Serial.

Key Features:
Servo Control: The pan and tilt servos adjust based on X and Y coordinates received from the Python script.
Smoothing: The movement of the servos is smoothed to avoid jerky motions.
Serial Communication: The Arduino listens for serial data from the Python script containing the center X and Y coordinates of the detected object.
Python Code
The Python script uses OpenCV to process the webcam feed and track a specific color (you can adjust the color range). It then calculates the center of the detected object and sends this position (X, Y coordinates) to the Arduino via serial communication.

Key Features:
Object Tracking: Tracks a specific color in the video feed using HSV color space.
Contours and Center Calculation: Finds the largest contour, calculates the center, and sends the coordinates to the Arduino.
Real-time Display: Shows the live video feed with a bounding box around the tracked object and its center.
Installation
Arduino IDE
Install the Servo Library:

Open Arduino IDE.
Go to Sketch -> Include Library -> Manage Libraries.
Search for Servo and install it.
Upload the Arduino Code:

Connect your Arduino board to the computer.
Open the Arduino code and upload it to your Arduino.
Python Setup
Install Required Libraries: Install OpenCV and PySerial if you haven't already:

bash
Copy code
pip install opencv-python pyserial numpy
Adjust Serial Port:

Find the port to which your Arduino is connected (e.g., COM10 on Windows, or /dev/ttyACM0 on Linux).
Update the serial port in the Python script:
python
Copy code
ser = serial.Serial('COM10', 9600)  # Update this to match your Arduino port
Run the Python Script: Execute the script:

bash
Copy code
python track_and_control.py
How It Works
Webcam Tracking:

The Python script captures frames from the webcam and processes them to track a specific color (e.g., red or another object of interest).
The script uses OpenCV's inRange to create a mask for the specified color, then finds contours to detect the largest object in view.
Coordinate Calculation:

Once the object is detected, the center of the bounding box is calculated.
These coordinates (center X and Y) are then sent to the Arduino via serial communication.
Servo Control:

The Arduino receives the X and Y coordinates and maps them to the corresponding pan and tilt angles (0 to 180 degrees).
The servos then move to these target angles with smooth movement.
Real-time Updates:

The webcam feed is continuously displayed, with a bounding box around the detected object and its center marked with a dot.
The system updates the servo positions in real-time to keep the object centered in the camera view.
