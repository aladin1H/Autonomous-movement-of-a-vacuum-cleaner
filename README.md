**Autonomous Vacuum Cleaner Robot**

This project implements an autonomous vacuum cleaner robot using ultrasonic and IR sensors for obstacle detection and navigation. The robot moves forward, avoids obstacles, detects edges (like stairs), and intelligently changes direction when blocked.

**Features**
Ultrasonic sensor for front obstacle detection
Dual IR sensors for obstacle & edge detection
Differential drive motor control
Automatic turning and path correction
Cliff/edge detection (prevents falling)
Simple decision-based navigation logic

**System Overview**

Sensors → Decision Logic → Motor Control → Movement

**Hardware Requirements**
Arduino Uno
Ultrasonic Sensor (HC-SR04)
2x IR Sensors
Motor Driver (L298N / similar)
2 DC Motors (Differential drive)
Battery Pack
Chassis (vacuum platform)

**Pin Configuration**
Ultrasonic Sensor
Trig → Pin 11
Echo → Pin 12
Motor Driver
ENA → Pin 3
ENB → Pin 5
IN1 → Pin 6
IN2 → Pin 7
IN3 → Pin 8
IN4 → Pin 9
IR Sensors
Front IR → Pin 10
Bottom IR (edge detection) → Pin 4

**Working Principle**
1. Forward Movement
Robot moves forward continuously
Speed is controlled using PWM
2. Obstacle Detection
Ultrasonic sensor checks distance
If object is within threshold (12 cm):
Robot stops
Moves backward
Tries alternate paths (left/right)
3. IR Obstacle Detection
Detects nearby objects not captured by ultrasonic
Triggers avoidance maneuver
4. Edge Detection (Cliff Safety)
Bottom IR sensor detects edges (e.g., stairs)
Robot immediately:
Stops
Moves backward
Turns away
5. Decision Logic
If path is clear → move forward
If blocked → try alternate directions
If no path available → stop

**Navigation Behavior**
Clear path → Move forward
Obstacle ahead → Avoid (turn left/right)
Edge detected → Reverse and turn
No available path → Stop

**Key Parameters**
Distance threshold: 12 cm
Forward speed: PWM 70
Turning speeds:
High: 130
Low: 20
Timing:
Forward adjust: 750 ms
Turn: 1000 ms
Reverse: 300 ms

**How to Run**
Connect all sensors and motors as per pin configuration
Upload the code to Arduino
Power the robot
Place it on a flat surface
The robot will start autonomous cleaning/navigation

**Important Notes**
Ensure IR sensor calibration for accurate edge detection
Adjust speed values based on motor characteristics
Stable power supply is required for motors
Avoid reflective surfaces for ultrasonic accuracy

**Concepts Used**
Embedded Systems (Arduino)
Sensor Fusion (Ultrasonic + IR)
Autonomous Navigation
Obstacle Avoidance
Control Logic

**Future Improvements**
Add mapping (SLAM)
Integrate vacuum motor control
Add battery monitoring system
Use PID control for smoother motion
Add WiFi/Bluetooth for remote control
